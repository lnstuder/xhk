.POSIX:

include config.mk

all: clean $(EXEC)

$(EXEC): $(OBJS)
	${CC} ${CFLAGS} ${INCS} -o $@ ${OBJS} ${LDFLAGS}

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $<

clean:
	rm -f *.o $(EXEC)

install:
	mv $(EXEC) $(BINDIR)

uninstall:
	rm -f $(BINDIR)/$(EXEC)

.PHONY: clean install