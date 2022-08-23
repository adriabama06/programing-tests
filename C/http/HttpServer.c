// Server side C program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

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

        char buffer[30000] = {0};
        long valread = read(sockfd, buffer, 30000);
        printf("%s\n", buffer);

        

        const char* hello = "HTTP/1.1 200 OK\nContent-Length: 12\nContent-Type: text/plain\n\nHello world!";

        write(sockfd, hello, strlen(hello));
        close(sockfd);
    }
    
}