#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <netinet/ip.h>

#include <unistd.h>

#include <pthread.h>

typedef struct MESSAGE_S
{
    uint32_t content_len;
    char* content;
} MESSAGE;

typedef struct THREAD_LAUNCH_DATA_S
{
    int client_fd;
    struct sockaddr_in client_info;
    socklen_t client_info_len;
    int** clients;
    uint32_t* clients_len;
    uint32_t author_len;
    char* author;
} THREAD_LAUNCH_DATA;

void send_message(int* clientfd, MESSAGE* msg)
{
    send(*clientfd, &msg->content_len, sizeof(uint32_t), 0);
    send(*clientfd, msg->content, msg->content_len, 0);
}

void send_to_all(int** clients, uint32_t clients_len, MESSAGE* msg)
{
    for (uint32_t i = 0; i < clients_len; i++)
    {
        int* clientfd = clients[i];

        if(*clientfd == -1)
        {
            continue;
        }

        send_message(clientfd, msg);
    }
}

void* client_handler(void* __thread_data /* THREAD_LAUNCH_DATA */)
{
    THREAD_LAUNCH_DATA* thread_data = (THREAD_LAUNCH_DATA*) __thread_data;

    while (1)
    {
        MESSAGE msg = {0};
        
        recv(thread_data->client_fd, &msg.content_len, sizeof(uint32_t), 0);
        
        msg.content = (char*) malloc(msg.content_len * sizeof(char));

        recv(thread_data->client_fd, msg.content, msg.content_len * sizeof(char), 0);

        
        if(strcmp(msg.content, "exit") == 0)
        {
            free(msg.content);
            break;
        }

        
        MESSAGE msg_to_send = {0};

        msg_to_send.content_len = thread_data->author_len + 1 + msg.content_len;

        msg_to_send.content = (char*) malloc(msg_to_send.content_len * sizeof(char));
    
        strcpy(msg_to_send.content, thread_data->author);
        strcat(msg_to_send.content, " ");
        strcat(msg_to_send.content, msg.content);

        
        send_to_all(thread_data->clients, *thread_data->clients_len, &msg_to_send);


        free(msg.content);
        free(msg_to_send.content);
    }

    thread_data->client_fd = -1;

    return NULL;
}

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

    int** clients = (int**) malloc(0 * sizeof(int*));
    uint32_t clients_len = 0;

    while (1)
    {
        THREAD_LAUNCH_DATA* thread_data = (THREAD_LAUNCH_DATA*) malloc(sizeof(THREAD_LAUNCH_DATA));

        thread_data->clients = clients;
        thread_data->clients_len = &clients_len;

        memset(&thread_data->client_info, 0, sizeof(struct sockaddr_in));
        thread_data->client_info_len = sizeof(thread_data->client_info);

        thread_data->client_fd = accept(server_socket_fd, (struct sockaddr*) &thread_data->client_info, &thread_data->client_info_len);

        getpeername(thread_data->client_fd, (struct sockaddr*) &thread_data->client_info, &thread_data->client_info_len);

        recv(thread_data->client_fd, &thread_data->author_len, sizeof(uint32_t), 0);

        thread_data->author = (char*) malloc(thread_data->author_len * sizeof(char));

        recv(thread_data->client_fd, thread_data->author, thread_data->author_len, 0);

        printf("New client from \"%s:%d\" with name \"%s\"\n", inet_ntoa(thread_data->client_info.sin_addr), ntohs(thread_data->client_info.sin_port), thread_data->author);



        pthread_t handler;
        if(pthread_create(&handler, NULL, client_handler, thread_data) != 0)
        {
            printf("Error on create thread!\n");
            
            close(thread_data->client_fd);

            free(thread_data->author);
            free(thread_data);
        }

        clients = (int**) realloc(clients, (clients_len + 1) * sizeof(int*));
        clients[clients_len++] = &thread_data->client_fd;
    }

    return 0;
}