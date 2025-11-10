/*semaphore (variable, binary) -> gives acess to critical section.
		solves reader writer problem, syncing between simultneous running process
		use 2 sempahore variables 
		1, increment, signal -> resource available ;  0, decrement, wait -> otherwise*/
	
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt, mutex;
int sharedvar = 0;       
int readcount = 0;   //no of readers

void *writer(void *arg) {
    printf("\nWriter is trying to enter");
    sem_wait(&wrt);  //lock writer function

    printf("\nWriter has entered CS");
    sharedvar++;  // update shared variable
    printf("\nWriter chnaged the value of shared var to %d", sharedvar);

    sem_post(&wrt);
    printf("\nWriter is out of CS");
    return NULL;
}

void *reader(void *arg) {
    sem_wait(&mutex);
    readcount++;
    if(readcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);

    printf("\nReader is reading the shared variable: %d", sharedvar);

    sem_wait(&mutex);
    readcount--;
    if(readcount == 0)
        sem_post(&wrt);
    sem_post(&mutex);
    return NULL;
}

int main() {
    
    int n, i;
    pthread_t r[10], w[10];  // Arrays to hold thread IDs for readers and writers

    sem_init(&wrt, 0, 1);
    sem_init(&mutex, 0, 1);

    printf("Enter number of readers and writers: ");
    scanf("%d%d", &n, &n);

    for(i = 0; i < n; i++) {
        pthread_create(&r[i], NULL, reader, NULL);
        pthread_create(&w[i], NULL, writer, NULL);
    }

    for(i = 0; i < n; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    sem_destroy(&wrt);
    sem_destroy(&mutex);

    return 0;
}

		
		
		
