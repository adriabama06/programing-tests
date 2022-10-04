// #ifdef _WIN32
//     #include <windows.h>
// #else
//     #include <unistd.h>
// #endif
// Sleep is only in seconds, and is different for win and linux

#include <time.h>

#include <stdio.h>
#include <stdlib.h>

int sleep(unsigned long ms /* milliseconds */)
{
    struct timespec ts;
    
    ts.tv_sec = ms / 1000; // seconds
    ts.tv_nsec = (ms % 1000) * 1000000; // nano seconds

    int res = nanosleep(&ts, &ts);
    
    return res;
}

int main(int argc, const char* argv[])
{
    if(argc < 2)
    {
        printf("%s <time in ms>\n", argv[0]);
        return 0;
    }

    unsigned int time = atoi(argv[1]);

    printf("Hello World\n");

    sleep(time);

    printf("Bye world\n");

    return 0;
}