.POSIX:

configure:
	mkdir build
	cd build &&\
	cmake ..

run:
	./build/Debug/xhk.exe

.PHONY: configure run
