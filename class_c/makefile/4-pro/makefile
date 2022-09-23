TARGET ?= run
OBJS:=main.o function.o function2.o
CC:= cc
CFLAGS:= -c -o

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
main.o:main.c
	$(CC) main.c $(CFLAGS) main.o
function.o:function.c
	$(CC) function.c $(CFLAGS) function.o
function2.o:function2.c
	$(CC) function2.c $(CFLAGS) function2.o

clean:
	rm $(OBJS) $(TARGET)
