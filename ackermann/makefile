CC=gcc
CFLAGS=-c -Wall -std=c99

all: ack

ack.o: ack.c
	$(CC) $(CFLAGS) ack.c

ack: ack.o
	$(CC) ack.o -o a.out

clean:
	rm *.out *.o core