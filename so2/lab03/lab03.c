#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int n;

    if (argc != 2) {
        printf("Zła ilość argumentów! ./a.out [n]\n");
        return 1;
    }

    n = atoi(argv[1]);

    printf("%d ", getpid());
    
    int i = 0;
    while(i < n) {
        pid = fork();

        if (pid == 0) {
            --n;
            i = 0;
            //++i;
            printf("%d ", getpid());
        } else {
            ++i;
            int status;
            while (-1 == waitpid(pid, &status, 0));
        }
    }
    printf("\n");

    return 0;
}
