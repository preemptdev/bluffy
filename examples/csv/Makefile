CC = x86_64-w64-mingw32-gcc
FLAGS = -Os -m64 -ffunction-sections -Wl,--strip-all
LIB = -lpcre2-8

csv:
	$(CC) main.c $(FLAGS) $(LIB) -o csv.exe 
