#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

#define true 1
#define false 0

short bPrintGroups = false;
short bPrintUsers = true;
int gid;
char *name;

void printInfo(){
    int i;
    struct passwd *user;

    while (user = getpwent()) {
        if (bPrintUsers) {
            printf("%s", user->pw_name);
        }

        if (bPrintGroups) {
            int ngroups = 0;
            gid_t *groups;
            struct group *gr;
         
            if (bPrintUsers)
                printf(" - ");
            if (getgrouplist(user->pw_name, user->pw_gid,
                             groups, &ngroups) == -1) {
                if (bPrintUsers)
                    printf("(%d) ", ngroups);
            }

            groups = malloc(ngroups * sizeof(gid_t));

            getgrouplist(user->pw_name, user->pw_gid, groups, &ngroups);

            for (i = 0; i < ngroups; ++i) {
                gr = getgrgid(groups[i]);
                if (gr != NULL) {
                    if (bPrintUsers == false) {
                        //if (gid == groups[i])
                        if (strcmp(name, gr->gr_name) == 0)
                            printf("%s\n", user->pw_name);
                    } else {
                        printf("%d=%s ", groups[i], gr->gr_name);
                    }
                }
            }

            free(groups);
        }

        if (bPrintUsers)
            printf("\n");
    }
}

int main (int argc, char *argv[]) {
    int i, opt;

    while ((opt = getopt(argc, argv, "lg:")) != -1) {
        switch (opt) {
            case 'l':
                bPrintGroups = true; 
                break;
            case 'g':
                //gid = atoi(optarg);
                name = optarg;
                bPrintUsers = false;
                bPrintGroups = true;
                break;
            default:
                printf("Usage: lab01\n"
                       "\t-l\t list groups of user\n"
                       "\t-g <id>\t list users in group\n");
                return -1;
        }
    }

    if (bPrintUsers || bPrintGroups )
        printInfo();

    return 0;
}
