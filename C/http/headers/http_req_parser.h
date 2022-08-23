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

typedef struct HTTP_REQUEST_STRUCT
{
    HTTP_METHOD method;
    char* path;
    char* protocol_version;
    char* host;
    char* connection;
    char* user_agent;
    char* accept;
    char* accept_encoding;
    char* cookie;
} HTTP_REQUEST;


HTTP_REQUEST* http_req_header_parse(char* http_req)
{
    int http_req_len = strlen(http_req);
    HTTP_REQUEST* headers = (HTTP_REQUEST*) malloc(sizeof(HTTP_REQUEST));

    memset(headers, 0, sizeof(headers));

    headers->method = unknown; // for make by default is unknown

    char** http_req_split = (char**) malloc(http_req_len);
    int http_req_split_len = 0;
    char* temp = NULL;

    temp = strtok(http_req, "\r\n"); // this will be automatically solved or something like this

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

        if(headers->host == 0 && startsWith(http_req_split_current, "Host: ")) {
            char* host = slice(http_req_split_current, strlen("Host: "), strlen(http_req_split_current)-1);

            headers->host = (char*) malloc(strlen(host));
            strcpy(headers->host, host);
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

    free(http_req);
    free(http_req_split);
    free(temp);
    /*
    printf("Method: %d\n", headers->method);
    printf("Path: %s\n", headers->path);
    printf("Protocol Version: %s\n", headers->protocol_version);

    printf("Host: %s\n", headers->host);

    printf("Connection: %s\n", headers->connection);
    printf("User-Agent: %s\n", headers->user_agent);
    printf("Accept: %s\n", headers->accept);
    printf("Accept Encoding: %s\n", headers->accept_encoding);
    printf("Cookie: %s\n", headers->cookie);
    */
    return headers;
}