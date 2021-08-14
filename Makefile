.POSIX:

all:
	cd build &&\
	meson compile -j 4

clean:
	rm -f *.o $(EXEC)

install:
	mv $(EXEC) $(BINDIR)

uninstall:
	rm -f $(BINDIR)/$(EXEC)

.PHONY: clean install uninstall