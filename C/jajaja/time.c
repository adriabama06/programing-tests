#include <stdio.h>

#include <sys/time.h>
#include <time.h>

#define timeval_to_nanoseconds(t) ((t.tv_sec * 1000000) + t.tv_usec)

int main()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    
    struct timespec ts;
    ts.tv_sec = 2;
    ts.tv_nsec = 0; // nano seconds
    nanosleep(&ts, &ts);

    struct timeval end;
    gettimeofday(&end, NULL);

    printf("Elapsed: %f seconds",
        (double) (end.tv_usec - start.tv_usec) / 1000000
        +
        (double) (end.tv_sec - start.tv_sec)
    );

    printf("Elapsed: %d nanoseconds", timeval_to_nanoseconds(end) - timeval_to_nanoseconds(start));

    return 0;
}