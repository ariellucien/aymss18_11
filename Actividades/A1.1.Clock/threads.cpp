#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static int* shared_pointer = NULL;

void* alter_thread_entry(void* arg) {
    // The following variable will be reachable,
    // while it exists, by both the main and the alter thread.
    int local_variable = 10;
    shared_pointer = &local_variable;
    sleep(2);
    return 0;
}

int main() {
    int local
    pthread_t alter_thread;
    pthread_create(&alter_thread, NULL, alter_thread_entry, NULL);
    sleep(1);
    printf("%i", *shared_pointer);
    fflush(stdout);
    pthread_join(alter_thread, NULL);
}