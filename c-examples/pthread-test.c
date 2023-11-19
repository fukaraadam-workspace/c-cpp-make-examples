#include <pthread.h>
#include <stdio.h>

/**
 * x86_64-w64-mingw32-gcc -o pthread-test.exe pthread-test.c -lpthread
 * 
 * Above command will generate pthread-test.exe.
 * If there are no errors, winpthreads is working correctly.
*/
void* print_hello(void* data) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, print_hello, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    return 0;
}