solve: solve.o Makefile
	gcc -o solve solve.o 
solve.o: solve.c fun.h Makefile
	gcc -c solve.c
clean:
	rm solve solve.o
