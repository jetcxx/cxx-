run:main.o function.o function2.o
	gcc main.o function.o function2.o -o run
main.o:main.c
	gcc -c main.c -o main.o
function.o:function.c
	gcc -c function.c -o function.o
function2.o:function2.c
	gcc -c function2.c -o function2.o

clean:
	rm *.o run
