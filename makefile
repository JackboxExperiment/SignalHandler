all: sig.o
	gcc sig.o

sig.o:
	gcc -c sig.c

run:
	./a.out

clean:
	rm error.txt
	rm *.o
	rm a.out
