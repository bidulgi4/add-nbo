CC = gcc
CFLAGS = -Wall -g

all: add-nbo

test: abb-nbo.o
	$(CC) $(CFLAGS) -o add-nbo add.o

test.o: add-nbo.c
	$(CC) $(CFLAGS) -c add-nbo.c

clean:
	rm -f add-nbo add-nbo.o

