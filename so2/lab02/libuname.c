#include <sys/utsname.h>

struct utsname unameData;

char* sysname() {
    return unameData.sysname;
}

//char* nodename() {
//    return unameData.nodename;
//}

char* release() {
    return unameData.release;
}

char* version() {
    return unameData.version;
}

char* machine() {
    return unameData.machine;
}

void __attribute__ ((constructor)) my_init() {
    uname(&unameData);
}
