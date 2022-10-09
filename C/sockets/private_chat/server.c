#define MAX_CLIENTS 30

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <pthread.h>
#endif

struct client_data
{
    char name[30];
    int sockfd;
};

struct client_handler_args
{
    struct client_data* clients[MAX_CLIENTS];
    unsigned int* clients_len;
};


void* client_handler(void* __data)
{
    struct client_handler_args* data = (struct client_handler_args*) __data;

    while(1)
    {
        for(unsigned int i = 0; i < *data->clients_len; i++)
        {
            struct client_data* client = data->clients[i];

            char* buffer = (char*) malloc(1024);
            ssize_t valread = read(client->sockfd, buffer, 1024);

            if(valread <= 0)
            {
                free(buffer);
                continue;
            }

            char* message = (char*) malloc(1024);

            strcpy(message, client->name);
            strcat(message, ": ");
            strncat(message, buffer, 1024 - 4 - strlen(client->name));

            printf("%s\n", message);

            for(unsigned int j = 0; j < *data->clients_len; j++)
            {
                if(j == i)
                {
                    continue;
                }

                struct client_data* client_to_send = data->clients[i];

                
                write(client_to_send->sockfd, message, strlen(message));
            }

            free(buffer);
            free(message);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2) {
        return 1;
    }

    const int PORT = atoi(argv[1]);

    printf("Using port %d\n", PORT);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    int serv_addr_len = sizeof(serv_addr);

    serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

    memset(serv_addr.sin_zero, '\0', sizeof(serv_addr.sin_zero));

    bind(listenfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

	listen(listenfd, MAX_CLIENTS);

    pthread_t client_handler_thread;

    struct client_handler_args ch_data;

    *ch_data.clients_len = 0;

    if(pthread_create(&client_handler_thread, NULL, client_handler, &ch_data) != 0)
    {
        printf("Error creating thread\n");
        return 1;
    }

    while(1)
    {
        int sockfd = accept(listenfd, (struct sockaddr*) &serv_addr, (socklen_t*) &serv_addr_len);

        char* buffer = (char*) malloc(1024);
        ssize_t valread = read(sockfd, buffer, 1024);
        
        printf("New client: %s\n", buffer);

        const char* message = "server:ok";

        write(sockfd, message, strlen(message));

        struct client_data client;

        strcpy(client.name, buffer);

        client.sockfd = sockfd;

        ch_data.clients[*ch_data.clients_len++] = &client;
   
        free(buffer);
        // close(sockfd);
    }

    return 0;
}