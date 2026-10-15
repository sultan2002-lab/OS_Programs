#include <stdio.h>
#include <pthread.h>
#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;
void* producer(void* arg) {
    int next_produced = 0;
    while (1) {
        if (count < BUFFER_SIZE) {
            buffer[in] = next_produced;
            printf("Produced: %d\n", next_produced);
            in = (in + 1) % BUFFER_SIZE;
            count++;
            next_produced++;
        }
    }
}
void* consumer(void* arg) {
    while (1) {
        if (count > 0) {
            int next_consumed = buffer[out];
            printf("Consumed: %d\n", next_consumed);
            out = (out + 1) % BUFFER_SIZE;
            count--;
        }
    }
}
int main(int argc, char** argv) {
    pthread_t tid1, tid2;
    pthread_attr_t attr1, attr2;
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_create(&tid1, &attr1, producer, NULL);
    pthread_create(&tid2, &attr2, consumer, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
