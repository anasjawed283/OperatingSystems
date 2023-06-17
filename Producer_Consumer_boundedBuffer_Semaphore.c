//Anas Jawed 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t mutex;
void* producer(void* arg) {
    int item;
    while (1) {
        item = rand() % 100; // Generate a random item

        sem_wait(&empty); // Wait for an empty slot in the buffer
        pthread_mutex_lock(&mutex); // Acquire the lock to access the buffer

 

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

 

        pthread_mutex_unlock(&mutex); // Release the lock
        sem_post(&full); // Signal that a new item is available
    }
    pthread_exit(NULL);
}
void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full); // Wait for an item in the buffer
        pthread_mutex_lock(&mutex); // Acquire the lock to access the buffe
        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex); // Release the lock
        sem_post(&empty); // Signal that an empty slot is available
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t producer_thread, consumer_thread;
    // Initialize the semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    // Wait for the threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    // Clean up resources
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}
