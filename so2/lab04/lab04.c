#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// handle ctrl+z
int allowed = 1;

void sig_handler(int signo) {
    if (allowed && signo == SIGINT) {
        printf("\n%d SIGINT!\n", getpid());
        exit(0);
    } else if (signo == SIGTSTP ) {
        if (allowed == 0){
            allowed = 1;
        } else {
            allowed = 0;
        }
    }
}

static void sigchld_hdl (int sig) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
    }
}

int main(int argc, char *argv[]) {
    struct sigaction act;

    memset(&act, 0, sizeof(act));
    act.sa_handler = sigchld_hdl;

    if (sigaction(SIGCHLD, &act, 0)) {
        printf("sigation");
        return 1;
    }

    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("Nie mozna ;<\n");
    
    if (signal(SIGTSTP, sig_handler) == SIG_ERR)
        printf("Nie mozna ;<\n");

    pid_t pid, pgid;
    int n;

    if (argc != 2) {
        printf("Zła ilość argumentów! ./a.out [n]\n");
        return 1;
    }

    n = atoi(argv[1]);

    pgid = getpid();
    printf("%d ", pgid);
    
    int i = 0;
    while(i < n) {
        pid = fork();

        if (pid == 0) {
            setpgid(0, pgid);
            --n;
            i = 0;
            printf("%d ", getpid());
        } else {
            setpgid(pid, pgid);
            ++i;
        }
    }
    printf("\n");
    while(1);
            int status;
            while (-1 == waitpid(pid, &status, 0));

    return 0;
}
