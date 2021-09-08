.POSIX:

CC		= gcc
CFLAGS	= -Wall -pedantic -O2 -pipe -march=native -Iinclude -I./\
		-Wunused-parameter -Wimplicit-function-declaration -Wunreachable-code
LDFLAGS	+= -lX11 -lxcb -lxcb-keysyms

SRCS	= $(wildcard src/*.c)
OBJS	= $(SRCS:.c=.o)

TARGET	= xhk

# Version Macro
VERSION = "1.0.0"
CFLAGS += -DVERSION='$(VERSION)'

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

build: $(OBJS)
	$(CC) -o ./bin/$(TARGET) $^ $(LDFLAGS)
 
clean:
	rm ./**/*.o

install:
	cp ./bin/xhk /usr/bin