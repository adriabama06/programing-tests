#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int startsWith(const char *s1, const char *s2) {
    for (int i = 0; s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return 0; // here return false cause there one string that are not the same at same position starting from 0
        }
    }

    return 1;
}

char* replace(const char* str, const char to_search, const char replace_value) {
    char* toreturn = (char*) calloc(1, strlen(str));
    int toreturn_len = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == to_search) {
            if(replace_value == '\0') {
                continue;
            }

            toreturn[toreturn_len] = replace_value;
        } else {
            toreturn[toreturn_len] = str[i];
        }
        toreturn_len += 1;
    }

    toreturn[toreturn_len] = '\0';

    return toreturn;
}

char* slice(const char* str, int start, int end) {
    char* toreturn = (char*) calloc(1, end-start);
    int toreturn_len = 0;
    for(int i = start; i <= (end-1); i++)
    {
        toreturn[toreturn_len] = str[i];
        toreturn_len += 1;
    }
    toreturn[toreturn_len] = '\0';

    return toreturn;
}

typedef enum HTTP_METHOD_ENUM
{
    unknown = -1,
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE,
    PATCH,
} HTTP_METHOD;

typedef struct HTTP_HOST_STRUCT
{
    char* address;
    int port;
} HTTP_HOST;

typedef struct HTTP_REQUEST_STRUCT
{
    HTTP_METHOD method;
    char* path;
    char* protocol_version;
    HTTP_HOST host;
    char* connection;
    char* user_agent;
    char* accept;
    char* accept_encoding;
    char* cookie;
} HTTP_REQUEST;


int main()
{
    FILE* http_req_file = fopen("example_http_request.txt", "r");    

    fseek(http_req_file, 0L, SEEK_END);
    size_t http_req_file_size = ftell(http_req_file);
    // fseek(fp, 0L, SEEK_SET); // go back where i'm reading or:
    rewind(http_req_file); // go to the start of the file
    
    char* http_req = (char*) calloc(http_req_file_size, 1);

    fread(http_req, 1, http_req_file_size, http_req_file);

    HTTP_REQUEST* headers = (HTTP_REQUEST*) calloc(1, sizeof(HTTP_REQUEST));

    headers->method = -1; // for make by default is unknown
    headers->host.port = -1; // for make know the port is unknown in this moment

    char** http_req_split = (char**) malloc(http_req_file_size);
    int http_req_split_len = 0;
    char* temp = NULL;

    temp = strtok(http_req, "\n"); // this will be automatically solved or something like this

    while (temp != NULL)
    {
        http_req_split[http_req_split_len] = (char*) malloc(strlen(temp));
        strcpy(http_req_split[http_req_split_len], temp);

        http_req_split_len += 1;

        temp = strtok(NULL, "\r\n"); // if the input is null will read the last splited string
    }

    for (int i = 0; i < http_req_split_len; i++)
    {
        char* http_req_split_current = http_req_split[i];
        
        if(headers->protocol_version == 0 && headers->path == 0 && strstr(http_req_split_current, " HTTP/") != NULL) {
            char* protocol_version;
            char* path = NULL;

            temp = strtok(http_req_split_current, " ");

            while (temp != NULL)
            {
                protocol_version = temp;

                if(path == NULL && startsWith(protocol_version, "/")) {
                    path = (char*) malloc(strlen(protocol_version));
                    strcpy(path, protocol_version);
                }

                temp = strtok(NULL, " ");
            }

            headers->protocol_version = (char*) malloc(strlen(protocol_version));
            strcpy(headers->protocol_version, protocol_version);

            headers->path = (char*) malloc(strlen(path));
            strcpy(headers->path, path);

            if(startsWith(http_req_split_current, "GET")) {
                headers->method = GET;
            } else if(startsWith(http_req_split_current, "HEAD")) {
                headers->method = HEAD;
            } else if(startsWith(http_req_split_current, "POST")) {
                headers->method = POST;
            } else if(startsWith(http_req_split_current, "PUT")) {
                headers->method = PUT;
            } else if(startsWith(http_req_split_current, "DELETE")) {
                headers->method = DELETE;
            } else if(startsWith(http_req_split_current, "CONNECT")) {
                headers->method = CONNECT;
            } else if(startsWith(http_req_split_current, "OPTIONS")) {
                headers->method = OPTIONS;
            } else if(startsWith(http_req_split_current, "TRACE")) {
                headers->method = TRACE;
            } else if(startsWith(http_req_split_current, "PATCH")) {
                headers->method = PATCH;
            } else {
                headers->method = unknown;
            }
        }

        if(headers->host.address == 0 && headers->host.port == 0 && startsWith(http_req_split_current, "Host: ")) {
            char* port;
            char* host = NULL;

            http_req_split_current = replace(http_req_split_current, ' ', '\0');

            temp = strtok(http_req_split_current, ":");

            while (temp != NULL)
            {
                port = temp;

                if(host == NULL && !strstr(port, "Host")) {
                    host = (char*) malloc(strlen(port));
                    strcpy(host, port);
                }

                temp = strtok(NULL, ":");
            }
            
            headers->host.port = atoi(port);
            headers->host.address = (char*) malloc(strlen(host));
            strcpy(headers->host.address, host);
        }

        if(headers->connection == 0 && startsWith(http_req_split_current, "Connection: ")) {
            char* connection = slice(http_req_split_current, strlen("Connection: "), strlen(http_req_split_current));
            
            headers->connection = (char*) malloc(strlen(connection));
            strcpy(headers->connection, connection);
        }

        if(headers->user_agent == 0 && startsWith(http_req_split_current, "User-Agent: ")) {
            char* user_agent = slice(http_req_split_current, strlen("User-Agent: "), strlen(http_req_split_current));
            
            headers->user_agent = (char*) malloc(strlen(user_agent));
            strcpy(headers->user_agent, user_agent);
        }

        if(headers->accept == 0 && startsWith(http_req_split_current, "Accept: ")) {
            char* accept = slice(http_req_split_current, strlen("Accept: "), strlen(http_req_split_current));
            
            headers->accept = (char*) malloc(strlen(accept));
            strcpy(headers->accept, accept);
        }

        if(headers->accept_encoding == 0 && startsWith(http_req_split_current, "Accept-Encoding: ")) {
            char* accept_encoding = slice(http_req_split_current, strlen("Accept-Encoding: "), strlen(http_req_split_current));
            
            headers->accept_encoding = (char*) malloc(strlen(accept_encoding));
            strcpy(headers->accept_encoding, accept_encoding);
        }

        if(headers->cookie == 0 && startsWith(http_req_split_current, "Cookie: ")) {
            char* cookie = slice(http_req_split_current, strlen("Cookie: "), strlen(http_req_split_current));
            
            headers->cookie = (char*) malloc(strlen(cookie));
            strcpy(headers->cookie, cookie);
        }
    }

    printf("Method: %d\n", headers->method);
    printf("Path: %s\n", headers->path);
    printf("Protocol Version: %s\n", headers->protocol_version);

    printf("Address: %s\n", headers->host.address);
    printf("Port: %d\n", headers->host.port);

    printf("Connection: %s\n", headers->connection);
    printf("User-Agent: %s\n", headers->user_agent);
    printf("Accept: %s\n", headers->accept);
    printf("Accept Encoding: %s\n", headers->accept_encoding);
    printf("Cookie: %s\n", headers->cookie);

    fclose(http_req_file);
   
    return 0;
}