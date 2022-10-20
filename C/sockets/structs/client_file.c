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

int main(int argc, const char* argv[])
{
    if(argc < 5)
	{
		printf("%s <ip> <port> <file name> <file content>\n", argv[0]);
		return 0;
	}

    const char* server_ip = argv[1]; // 128.0.0.1 for localhost
    int PORT = atoi(argv[2]);

    // server socket info, where I like connect
    struct sockaddr_in server_info = {0};

    server_info.sin_family = AF_INET;
    // server_info.sin_addr.s_addr = htonl(server_ip); // not work, because is a string
    server_info.sin_port = htons(PORT);

    if(inet_pton(AF_INET, server_ip, &server_info.sin_addr) <= 0)
	{
		printf("Error on inet_pton\n");

		return 0;
	}

    socklen_t server_info_len = sizeof(server_info);

    // create socket for server connection
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket_fd < 0)
    {
        printf("Error on socket creation\n");

        return 0;
    }

    printf("Connecting to the server...\n");

    // connect to the server
    if(connect(server_socket_fd, (struct sockaddr*) &server_info, sizeof(server_info)) < 0)
    {
        printf("Error on connect to the server\n");

        return 0;
    }

    printf("Connected to the server!\n");
    
    uint8_t content_type = 0; // file
    
    const char* filename = argv[3];
    uint8_t filename_len = strlen(filename);
    
    const char* filecontent = argv[4];
    uint8_t filecontent_len = strlen(filecontent);



    printf("Sending file \"%s\" with content: \"%s\"\n", filename, filecontent);



    send(server_socket_fd, &content_type, sizeof(uint8_t), 0);

    send(server_socket_fd, &filename_len, sizeof(uint8_t), 0);

    send(server_socket_fd, &filecontent_len, sizeof(uint8_t), 0);


    printf("Variable of size sent, sending data...\n");


    send(server_socket_fd, filename, filename_len, 0);

    send(server_socket_fd, filecontent, filecontent_len, 0);


    printf("Data sent, closing connection!\n");


    close(server_socket_fd);

    return 0;
}