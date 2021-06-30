.POSIX:

CC = MSBuild.exe
TARGET = xhk.sln

rebuild: configure compile

debug: compile run

configure:
	mkdir -p build
	cd build &&\
	cmake ..

compile:
	cd build &&\
	$(CC) $(TARGET) -O3

run:
	./build/Debug/xhk.exe

.PHONY: configure run