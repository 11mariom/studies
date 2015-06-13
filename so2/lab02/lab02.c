#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[]) {
    // załadowanie biblioteki
    void *handle;
    char *error;
    char* (*f)(void);

    handle = dlopen("/home/mariom/git/studies/so2/lab02/libuname.so", RTLD_LAZY);
    if (!handle) {
        fputs(dlerror(), stderr);
        return 1;
    }

    // program właściwy
    int opt;
    int a = 0, s = 0, n = 0, r = 0, v = 0, m = 0;
    
    if (argc == 1){
        //printf("%s ", sysname());
        f = dlsym(handle, "sysname");
        if (dlerror() != NULL) {
            printf("Nie ma opcji!");
        } else {
            printf("%s ", (*f)());
        }
    }

    while ((opt = getopt(argc, argv, "asnrvmh")) != -1) {
        switch (opt) {
            case 'a':
                a = 1;
                break;
            case 's':
                s = 1;
                break;
            case 'n':
                n = 1;
                break;
            case 'r':
                r = 1;
                break;
            case 'v':
                v = 1;
                break;
            case 'm':
                m = 1;
                break;
            case 'h':
                printf("Przełączniki: -a -s -n -r -v -m");
                break;
            default:
                break;
        }
    }

    if (s || a) {
        f = dlsym(handle, "sysname");
        if (dlerror() != NULL) {
            printf("[brak obsługi parametru -s] ");
        } else {
            printf("%s ", (*f)());
        }
    }
    if (n || a) {
        f = dlsym(handle, "nodename");
        if (dlerror() != NULL) {
            printf("[brak obsługi parametru -n] ");
        } else {
            printf("%s ", (*f)());
        }
    }
    if (r || a) {
        f = dlsym(handle, "release");
        if (dlerror() != NULL) {
            printf("[brak obsługi parametru -r] ");
        } else {
            printf("%s ", (*f)());
        }
    }
    if (v || a) {
        f = dlsym(handle, "version");
        if (dlerror() != NULL) {
            printf("[brak obsługi parametru -v] ");
        } else {
            printf("%s ", (*f)());
        }
    }
    if (m || a) {
        f = dlsym(handle, "machine");
        if (dlerror() != NULL) {
            printf("[brak obsługi parametru -m] ");
        } else {
            printf("%s ", (*f)());
        }
    }

    printf("\n");

    return 0;
}
