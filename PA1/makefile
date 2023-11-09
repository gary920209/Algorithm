# CC and CFLAGS are varilables
CC = g++
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.

OPTFLAGS = -O2

all	: bin/mps
	@echo -n ""

# optimized version
bin/mps	: src/main.cpp
			$(CC) $(OPTFLAGS) $< -o $@

# clean all the .o and executable files
clean:
		rm -rf *.o lib/*.a lib/*.o bin/*

