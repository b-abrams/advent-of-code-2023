CC=gcc
CFLAGS=-I.
DEPS = utils.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o utils.o 
	$(CC) -o main.out main.o utils.o
	rm *.o