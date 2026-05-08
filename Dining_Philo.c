#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
pthread_mutex_t chopstick[N];

void* philosopher(void* num) {
    int id = *(int*)num, time=0;
    while (1) {
        printf("Time %2d: Philosopher %d thinking\n", time++, id);
        pthread_mutex_lock(&chopstick[id]);
        pthread_mutex_lock(&chopstick[(id+1)%N]);
        printf("Time %2d: Philosopher %d eating\n", time++, id);
        sleep(1);
        pthread_mutex_unlock(&chopstick[(id+1)%N]);
        pthread_mutex_unlock(&chopstick[id]);
    }
}

int main() {
    pthread_t tid[N]; int i, phil[N];
    for(i=0;i<N;i++) pthread_mutex_init(&chopstick[i],NULL);
    printf("\n--- Dining Philosophers Simulation ---\n");
    for(i=0;i<N;i++){ phil[i]=i; pthread_create(&tid[i],NULL,philosopher,&phil[i]); }
    for(i=0;i<N;i++) pthread_join(tid[i],NULL);
}
