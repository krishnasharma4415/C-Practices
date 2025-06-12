#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 5
typedef struct
{
    int buf[SIZE], in, out;
} SharedMem;

void producer(SharedMem *shm)
{
    for (int i = 0; i < 10; i++)
    {
        while ((shm->in + 1) % SIZE == shm->out)
            ;
        shm->buf[shm->in] = rand() % 100;
        printf("Produced: %d\n", shm->buf[shm->in]);
        shm->in = (shm->in + 1) % SIZE;
        sleep(1);
    }
}

void consumer(SharedMem *shm)
{
    for (int i = 0; i < 10; i++)
    {
        while (shm->in == shm->out)
            ;
        printf("Consumed: %d\n", shm->buf[shm->out]);
        shm->out = (shm->out + 1) % SIZE;
        sleep(2);
    }
}

int main()
{
    int shmid = shmget(IPC_PRIVATE, sizeof(SharedMem), IPC_CREAT | 0666);
    SharedMem *shm = (SharedMem *)shmat(shmid, NULL, 0);
    shm->in = shm->out = 0;

    if (fork() == 0)
        producer(shm);
    else
        consumer(shm), wait(NULL), shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
