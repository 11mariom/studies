# Makefile for matrix multiplication

CC = gcc
CFLAGS = -Wall -std=c99

all:
	$(CC) $(CFLAGS) src/main.c -o matrix_mult

unit:
	$(CC) $(CFLAGS) test/test.c -o mm_unit -lcunit

clean:
	-rm matrix_mult
	-rm mm_unit
