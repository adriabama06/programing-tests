/*
!!! WARNING !!!
If you use struct with dynamic memory like:
strings/arrays/other structs you need seend size before message for server memory allocation, see: client_message_dynamic.c

*/

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

struct MESSAGE_STRUCT {
    char author[30];
    char content[50];
};

int main(int argc, const char* argv[])
{
    if(argc < 5)
    {
        printf("%s <ip> <port> <author> <message content>\n", argv[0]);
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
    
    uint8_t content_type = 1; // message struct

    struct MESSAGE_STRUCT message = {0};
    
    strcpy(&message.author, argv[3]);
    strcpy(&message.content, argv[4]);


    printf("Sending type as message struct...\n");

    send(server_socket_fd, &content_type, sizeof(uint8_t), 0);

    printf("Sending message struct... with content: %s: %s\n", message.author, message.content);

    send(server_socket_fd, &message, sizeof(struct MESSAGE_STRUCT), 0);


    printf("Data sent, closing connection!\n");


    close(server_socket_fd);

    return 0;
}