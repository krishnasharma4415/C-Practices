#include <stdio.h>
#include <mqueue.h>
#include <unistd.h>
#include <string.h>
#define QUEUE "/queue"

void producer(mqd_t mq) {
    for (int i = 0; i < 10; i++) {
        char msg[10];
        sprintf(msg, "Item %d", i);
        mq_send(mq, msg, strlen(msg) + 1, 0);
        printf("Produced: %s\n", msg);
        sleep(1);
    }
}

void consumer(mqd_t mq) {
    char msg[10];
    for (int i = 0; i < 10; i++) {
        mq_receive(mq, msg, sizeof(msg), NULL);
        printf("Consumed: %s\n", msg);
        sleep(2);
    }
}

int main() {
    struct mq_attr attr = {0, 5, 10, 0};
    mqd_t mq = mq_open(QUEUE, O_CREAT | O_RDWR, 0644, &attr);
    if (fork() == 0) producer(mq);
    else consumer(mq), wait(NULL), mq_close(mq), mq_unlink(QUEUE);

    return 0;
}
