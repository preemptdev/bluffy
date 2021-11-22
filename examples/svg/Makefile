CC = x86_64-w64-mingw32-gcc
FLAGS = -Os -m64 -ffunction-sections -Wl,--strip-all -Wint-conversion -Wincompatible-pointer-types
LIB = -lpcre2-8

svg:
	$(CC) main.c $(FLAGS) $(LIB) -o svg.exe 
