#include <stdio.h>
#include <pthread.h>
void *print(void *arg)
{
    for (int i = 0; i < 5; i++)
        printf("%s ", (char *)arg), fflush(stdout), usleep(500000);
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, print, "Hello");
    pthread_create(&t2, NULL, print, "World\n");
    pthread_join(t1, NULL), pthread_join(t2, NULL);
    return 0;
}
