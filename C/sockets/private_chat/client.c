#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("%s <ip> <port> <username 30 char>\n", argv[0]);
		return 1;
	}

    const int PORT = atoi(argv[1]);
    const char* server_ip = "128.0.0.1";

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
	{
		printf("\n Error : Could not create socket \n");
		return 1;
	}

	struct sockaddr_in serv_addr;

	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if(inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0)
	{
		printf("inet_pton error occured\n");
		return 1;
	}

	if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("Error : Connect Failed \n");
		return 1;
	}

    printf("Sending hello message!\n");

    write(sockfd, argv[3], strlen(argv[3]));

	while (1)
	{
        char* buffer = (char*) malloc(1024);

        ssize_t valread = read(sockfd, buffer, 1024);
		
        buffer[valread] = 0;
		
        printf("%s\n", buffer);

        free(buffer);

        char* message = (char*) malloc(1024);

        scanf("%s", message);

        write(sockfd, message, strlen(message));

        printf("%s: %s\n", argv[3], message);
        
        free(message);
	}

	return 0;
}