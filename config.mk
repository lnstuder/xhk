
VERSION = 1.0.0

# Compiler flags
CFLAGS		+=	-Wall -std=c99 -Os -g3 -pedantic -Wall -Wunused-parameter -Wlong-long \
				-Wsign-conversion -Wconversion -Wimplicit-function-declaration \
				-march=native -DVERSION="\"$(VERSION)\""
LDFLAGS		+=	-lxcb -lxcb-xinerama -lxcb-randr

# Source files directory
SRCROOT		=	src/

# Executable name
EXEC		=	xhk

# Includes
INCS		=	-I/usr/include/xcb

# Object files
OBJS		=	xhk.o

# Install directory
BINDIR		=	/usr/bin