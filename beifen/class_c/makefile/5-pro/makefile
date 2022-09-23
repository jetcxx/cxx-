TARGET ?= run
OBJS:=main.o function.o function2.o
CC:= cc
CFLAGS:= -c -o

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
%.o:%.c
	$(CC) $< $(CFLAGS) $@
clean:
	rm $(OBJS) $(TARGET)
