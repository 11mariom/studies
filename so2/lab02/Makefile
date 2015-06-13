build:
	gcc -c -fPIC -o libuname.o libuname.c
	gcc -shared -fPIC -o libuname.so libuname.o
	gcc lab02.c -rdynamic -ldl

run:
	LD_LIBRARY_PATH=. ./a.out

all:	build run
