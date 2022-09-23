run:test.o
	gcc test.o -o run
test.o:test.s
	gcc -c test.s -o test.o
test.s:test.i
	gcc -S test.i -o test.s
test.i:test.c
	gcc -E test.c -o test.i
clean:
	rm -rf run test.s test.i test.o
