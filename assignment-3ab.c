#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

// Function to execute orphan process
void orphan() {
    pid_t pid = fork();

    if(pid > 0)
        printf("Parent Process\n");
    
    else if(pid == 0){
        sleep(10);
        printf("Child Process\n");
    }
}

// Function to execute zombie process
void zombie() {
    pid_t pid = fork();

    if(pid > 0)
        sleep(10);
    
    else
        exit(0);
}

int main() {
    printf("Enter choice: \n1. Orphan Process\n2.Zombie Process\n");
    int n;
    scanf("%d", &n);

    switch(n) {
        case 1:
            orphan();
            break;
        case 2:
            zombie();
            break;
        default:
            printf("Exiting program\n");
    }
}
