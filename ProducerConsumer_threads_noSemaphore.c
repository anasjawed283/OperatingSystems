//Anas Jawed (21BRS1336)
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;
void *producer(void *arg)
{
    int item;
    for (int i = 0; i < 10; i++)
    {
        item = rand() % 100;  // Generate a random item

        while (count == BUFFER_SIZE)
        {
            // Buffer is full, wait for the consumer to consume
        }
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Produced item: %d\n", item);
    }
    pthread_exit(NULL);
}
void *consumer(void *arg)
{
    int item;
    for (int i = 0; i < 10; i++)
    {
        while (count == 0)
        {
            // Buffer is empty, wait for the producer to produce
        }
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumed item: %d\n", item);
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t producerThread, consumerThread;
    // Create producer and consumer threads
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);
    // Wait for threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);
    return 0;
}
