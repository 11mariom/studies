#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define true 1
#define false 0

static char *get_basename (char *path) {
    char *pos;
    char *result;

    pos = path;
    result = path;

    while (*pos != '\0') {
        if ( *(pos++) == '/' ) result = pos;
    }

    return result;
}

static char* exe_path (char *path) {
    char link[PATH_MAX];
    char *result;

    int len = readlink(path, link, sizeof(link));

    link[len] = '\0';
    result = link;
    return result;
}

int main (int argc, char *argv[])
{
    char p[] = "/proc/%d/exe";
    int i = 0;

    for (i = 1; i < NGROUPS_MAX; ++i) {
        char path[16];
        sprintf(path, p, i);

        if (access(path, F_OK) != -1) {
            char *l = exe_path(path);
            char *b = get_basename(l);
            if (!strcmp(b, argv[1]) || !strncmp(b, argv[1], strlen(argv[1]))) {
                printf("%d ", i);
            }
        }
    }
    printf("\n");
    return 0;
}
