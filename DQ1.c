#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void SIGNAL_HANDLER(int signal) {
    printf("\nInput interrupted by user.\n");
    exit(1);
}

int main() {
    int a, b;
    sigset_t mask;


    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    printf("Enter the value of a (cannot be interrupted): ");
    scanf("%d", &a); 
    
    printf("The value of a = %d\n", a);


    sigprocmask(SIG_UNBLOCK, &mask, NULL);
    signal(SIGINT, SIGNAL_HANDLER);

    printf("Enter the value of b (can be interrupted): ");
    scanf("%d", &b);  
    printf("The value of b = %d\n", b); 

    return 0;
}
