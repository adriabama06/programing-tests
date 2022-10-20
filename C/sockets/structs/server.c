#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <netinet/ip.h>

#include <unistd.h>

#define CONTENT_TYPE_FILE 0
#define CONTENT_TYPE_MESSAGE 1
#define CONTENT_TYPE_FLOAT 2

int main(int argc, const char* argv[])
{
    if(argc < 2)
    {
        printf("%s <port>\n", argv[0]);
        return 0;
    }
    
    int PORT = atoi(argv[1]);

    if(PORT == 0)
    {
        printf("Please provide a valid port\n");

        return 0;
    }

    // server socket info
    struct sockaddr_in server_info = {0};

    server_info.sin_family = AF_INET;
    server_info.sin_port = htons(PORT);

    socklen_t server_info_len = sizeof(server_info);

    // create tcp socket
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket_fd < 0)
    {
        printf("Error on socket creation\n");

        return 0;
    }

    // bind info
    if(bind(server_socket_fd, (struct sockaddr*) &server_info, server_info_len) < 0)
    {
        printf("Error on bind data\n");

        return 0;
    }
    
    // listen for connections
    if(listen(server_socket_fd, 0) < 0)
    {
        printf("Error on listen\n");

        return 0;
    }

    printf("Listening in port :%d\n", PORT);

    while (1)
    {
        // client socket info
        struct sockaddr_in client_info = {0};
        socklen_t client_info_len = sizeof(client_info);

        int client_fd = accept(server_socket_fd, (struct sockaddr*) &client_info, &client_info_len);

        getpeername(client_fd, (struct sockaddr*) &client_info, &client_info_len);

        printf("New client from: %s:%d\n", inet_ntoa(client_info.sin_addr), ntohs(client_info.sin_port));

        uint8_t content_type = 255;

        recv(client_fd, &content_type, sizeof(uint8_t), 0);

        if(content_type == CONTENT_TYPE_FILE)
        {
            uint8_t filename_len = 0;
            uint8_t filecontent_len = 0;

            recv(client_fd, &filename_len, sizeof(uint8_t), 0);
            recv(client_fd, &filecontent_len, sizeof(uint8_t), 0);

            char* filename = (char*) malloc(filename_len);
            char* filecontent = (char*) malloc(filecontent_len);

            recv(client_fd, filename, filename_len, 0);
            recv(client_fd, filecontent, filecontent_len, 0);
            
            printf("Creating file \"%s\" with content: \"%s\"\n", filename, filecontent);

            FILE* tosave = fopen(filename, "w");

            fwrite(filecontent, sizeof(char), filecontent_len, tosave);

            fclose(tosave);

            free(filename);
            free(filecontent);
        }

        printf("Closing connection\n");

        close(client_fd);
    }

    return 0;
}