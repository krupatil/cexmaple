#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

#define MAX	20

int buffer = 1;
pthread_mutex_t mutex;
pthread_cond_t pcond;
pthread_cond_t ccond;

void * producer(void *arg)
{
	for(int i = 0; i < MAX; i++)
	{
		pthread_mutex_lock(&mutex);
		while(buffer != 0)
			pthread_cond_wait(&pcond, &mutex);

		buffer++;
		printf("Producer[%d]: %d\n", i, buffer);
		pthread_cond_signal(&ccond);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void * consumer(void *arg)
{
        for(int i = 0; i < MAX; i++)
        {       
                pthread_mutex_lock(&mutex);
		while(buffer == 0)
                	pthread_cond_wait(&ccond, &mutex);
                
		buffer--;
		printf("Consumer[%d]: %d\n", i, buffer);
                pthread_cond_signal(&pcond);
                pthread_mutex_unlock(&mutex);
        }
	return NULL;
}

int main()
{
	pthread_t	prod, conc;

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&pcond, NULL);
	pthread_cond_init(&ccond, NULL);

	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&conc, NULL, consumer, NULL);
	
	pthread_join(prod, NULL);
	pthread_join(conc, NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&pcond);
	pthread_cond_destroy(&ccond);
	return 0;
}

