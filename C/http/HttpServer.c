#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include "headers/http_req_parser.h"

int main(int argc, char const *argv[])
{
    if(argc < 2) {
        return -1;
    }

    const char* port_str = argv[1];
    const int PORT = atoi(port_str);

    printf("Using port %d\n", PORT);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serv_addr;
    int serv_addr_len = sizeof(serv_addr);

    serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

    memset(serv_addr.sin_zero, '\0', sizeof(serv_addr.sin_zero));

	bind(listenfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

	listen(listenfd, 10);

    while(1)
    {
        int sockfd = accept(listenfd, (struct sockaddr*)&serv_addr, (socklen_t*)&serv_addr_len);

        char* buffer = (char*) malloc(1024);
        long int valread = read(sockfd, buffer, 1024);
        
        //printf("%s\n", buffer);

        HTTP_REQUEST* req = http_req_header_parse(buffer);
        
        if(req->method != GET)
        {
            const char* message = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nOnly accept GET";
            write(sockfd, message, strlen(message));
            close(sockfd);
            continue;
        }

        if(startsWith(req->path, "/favicon.ico")) {
            close(sockfd);
            continue;
        }

        printf("%s -> %s | %s\n", req->host, req->path, req->accept_encoding);

        if(startsWith(req->path, "/secret")) {
            const char* message = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nBienvenido a la pagina secreta :D";

            write(sockfd, message, strlen(message));
            close(sockfd);
            continue;
        }

        const char* message = "HTTP/1.1 200 OK\nContent-Length: 12\nContent-Type: text/plain\n\nHello world!";

        write(sockfd, message, strlen(message));
        close(sockfd);
    }
}