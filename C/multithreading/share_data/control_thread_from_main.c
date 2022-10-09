#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

void custom_sleep(uint32_t ms /* milliseconds */)
{
    struct timespec ts;
    
    ts.tv_sec = ms / 1000; // seconds
    ts.tv_nsec = (ms % 1000) * 1000000; // nano seconds

    int res = nanosleep(&ts, &ts);
    
    return;
}

typedef struct print_char_requesed_i_args_s
{
    uint8_t* exit;
    uint32_t* current_i;

    const char* message;
} print_char_requesed_i_args;

void* print_char_requesed_i(void* __data)
{
    print_char_requesed_i_args* data = (print_char_requesed_i_args*) __data;

    uint32_t last_i = 1;
    
    while (1)
    {
        if(*data->exit == 1)
        {
            break;
        }

        if(last_i == *data->current_i)
        {
            continue;
        }

        last_i = *data->current_i;

        printf("%d -> %c\n", last_i, data->message[last_i]);
    }
    
    return NULL;
}

int main(int argc, const char* argv[])
{
    if(argc < 2)
    {
        printf("%s <string>\n", argv[0]);
        return 0;
    }

    const char* message = argv[1];
    uint32_t message_len = strlen(message);
    uint8_t exit_co = 0;
    uint32_t current_i = 0;

    print_char_requesed_i_args data;

    data.current_i = &current_i;
    data.exit = &exit_co;
    data.message = message;

    pthread_t handle;

    pthread_create(&handle, NULL, print_char_requesed_i, &data);

    while (1)
    {
        int32_t input;
        scanf("%d", &input);

        if(input <= -1)
        {
            exit_co = 1;
            pthread_join(handle, NULL);
            break;
        }
    
        if(input >= message_len)
        {
            continue;
        }

        current_i = input;
    }
    
    return 0;
}