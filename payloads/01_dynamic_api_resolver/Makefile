CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wextra -O2 -s

all: resolver.exe

resolver.exe: main.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f resolver.exe
