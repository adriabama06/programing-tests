#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <netinet/ip.h>

#include <unistd.h>

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

    /*

    sockaddr vs sockaddr_in

    sockaddr - Structure describing a generic socket address
    
    sockaddr_in - Structure describing an Internet socket address
    */

    // server socket info
    struct sockaddr_in server_info = {0};

    server_info.sin_family = AF_INET;
    server_info.sin_port = htons(PORT);

    socklen_t server_info_len = sizeof(server_info);

    /*
    > man 7 ip

    tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    raw_socket = socket(AF_INET, SOCK_RAW, protocol);

    https://stackoverflow.com/questions/30682057/socket-programming-what-is-fd-and-sd
    FD? File Descriptor:
    In Unix and related computers operating systems,
    a file descriptor (FD, less frequently fildes) is an abstract indicator used to access a file or other input/output resource,
    such as a pipe or network connection.
    File descriptors are part of the POSIX application programming interface.
    A file descriptor is a non-negative integer, represented in C programming language as the type int.
    */
    // create tcp socket
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket_fd < 0)
    {
        printf("Error on socket creation\n");

        return 0;
    }

    /*
    struct sockaddr == struct sockaddr_in, +_in is for input connection, but the struct is like the same info
    */

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

        char* message = "Hello World\n";
        size_t message_len = strlen(message);

        printf("Sending: %s", message);

        ssize_t send_len = send(client_fd, (void*) message, message_len, 0);

        if(send_len < message_len)
        {
            printf("Send %d but expect send %d\n", send_len, message_len);
        }

        printf("Closing connection\n");

        close(client_fd);
    }

    return 0;
}