CFLAGS = -Og
CC = gcc

all: show-bytes32 show-bytes64

show-bytes32: 2_show_bytes.cpp
	$(CC) $(CFLAGS) -m32 2_show_bytes.cpp -o show-bytes32

show-bytes64: 2_show_bytes.cpp
	$(CC) $(CFLAGS) -m64 2_show_bytes.cpp -o show-bytes64

clean:
	rm -f *~ *.o show-bytes32 show-bytes64