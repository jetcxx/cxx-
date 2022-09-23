TARGET ?= run
OBJS:=./main/main.o ./function/function.o ./function2/function2.o
CC:= cc
CFLAGS:= -c -o
export VPATH = ./function/ ./function2/ ./main/
#vpath %.c ./function ./function2 ./main/
$(TARGET):main.o function.o function2.o
	$(CC) $(OBJS) -o $(TARGET)
%.o:%.c
	make -C $*
.PHONY:clean
clean:
	rm $(OBJS) $(TARGET)

.PHONY:install
install:
	mkdir bin
	mv run ./bin/
.PHONY:uninstall
uninstall:
	rm -rf bin
