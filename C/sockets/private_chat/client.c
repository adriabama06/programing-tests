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

uint8_t program_end = 0;

typedef struct MESSAGE_S
{
    uint32_t content_len;
    char* content;
} MESSAGE;

void send_message(int* server_socket_fd, MESSAGE* msg)
{
    send(*server_socket_fd, &msg->content_len, sizeof(uint32_t), 0);
    send(*server_socket_fd, msg->content, msg->content_len, 0);
}

typedef struct THREAD_LAUNCH_DATA_S
{
    int server_socket_fd;
    struct sockaddr_in server_info;
} THREAD_LAUNCH_DATA;

void* recive_handler(void* __data)
{
    THREAD_LAUNCH_DATA* data = (THREAD_LAUNCH_DATA*) __data;

    while (program_end == 0)
    {
        MESSAGE msg = {0};
        
        recv(data->server_socket_fd, &msg.content_len, sizeof(uint32_t), 0);

        msg.content = (char*) malloc(msg.content_len * sizeof(char));

        recv(data->server_socket_fd, msg.content, msg.content_len * sizeof(char), 0);

        printf("%s\n", msg.content);

        free(msg.content);
    }
    
    return NULL;
}

void* send_handler(void* __data)
{
    THREAD_LAUNCH_DATA* data = (THREAD_LAUNCH_DATA*) __data;

    while (program_end == 0)
    {
        MESSAGE msg = {0};
        msg.content_len = 0;
        msg.content = (char*) malloc(msg.content_len * sizeof(char));

        char* buff = (char*) malloc((1024 * 4) * sizeof(char));
        scanf("%s", buff);
        if(strcmp(buff, "/exit") == 0)
        {
            program_end = 1;
            break;
        }
        size_t buff_len = strlen(buff);

        msg.content = (char*) realloc(msg.content, (msg.content_len + buff_len) * sizeof(char));
        msg.content_len = msg.content_len + buff_len;

        strncpy(msg.content, buff, buff_len);

        send_message(&data->server_socket_fd, &msg);

        free(msg.content);
        free(buff);
    }
    
    return NULL;
}

int main(int argc, const char* argv[])
{
    if(argc < 4)
	{
		printf("%s <ip> <port> <nickname>\n", argv[0]);
		return 0;
	}

    const char* server_ip = argv[1]; // 128.0.0.1 for localhost
    int PORT = atoi(argv[2]);

    THREAD_LAUNCH_DATA data = {0};

    // server socket info, where I like connect
    data.server_info.sin_family = AF_INET;
    // server_info.sin_addr.s_addr = htonl(server_ip); // not work, because is a string
    data.server_info.sin_port = htons(PORT);

    if(inet_pton(AF_INET, server_ip, &data.server_info.sin_addr) <= 0)
	{
		printf("Error on inet_pton\n");

		return 0;
	}

    socklen_t server_info_len = sizeof(data.server_info);

    // create socket for server connection
    data.server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(data.server_socket_fd < 0)
    {
        printf("Error on socket creation\n");

        return 0;
    }

    printf("Connecting to the server...\n");

    // connect to the server
    if(connect(data.server_socket_fd, (struct sockaddr*) &data.server_info, sizeof(data.server_info)) < 0)
    {
        printf("Error on connect to the server\n");

        return 0;
    }

    uint32_t nickname_len = strlen(argv[3]);
    send(data.server_socket_fd, &nickname_len, sizeof(uint32_t), 0);
    send(data.server_socket_fd, argv[3], nickname_len, 0);

    printf("Conected as %s!\n", argv[3]);

    pthread_t recive_thread;
    pthread_t send_thread;

    pthread_create(&recive_thread, NULL, recive_handler, &data);
    pthread_create(&send_thread, NULL, send_handler, &data);

    while (program_end == 0) {;}
    
    pthread_join(recive_thread, NULL);
    pthread_join(send_thread, NULL);

    close(data.server_socket_fd);

    return 0;
}