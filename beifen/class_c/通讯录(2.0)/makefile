TARGET ?= run
OBJS:=main.o contact.o
CC:=gcc
CFLAGS:= -c -o

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
main.o:main.c
	$(CC) main.c $(CFLAGS) main.o
contact.o:contact.c
	$(CC) contact.c $(CFLAGS) contact.o
clean:
	rm $(OBJS)
