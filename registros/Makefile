cc = gcc
CFLAGS = -O3 -c -Wall

all:	obj 
	rm -f test.o
	$(cc) -o main *.o -lncurses
	rm -f *.o	

test:	obj
	rm -f main.o
	$(cc) -o test *.o -lncurses
	rm -f *.o	

obj:
	$(cc) $(CFLAGS) *.c

clean:
	rm -f main
	rm -f test
