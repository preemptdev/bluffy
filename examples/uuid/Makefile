CC = x86_64-w64-mingw32-gcc
FLAGS = -Os -m64 -ffunction-sections -Wl,--strip-all
LIB = -lrpcrt4

uuid:
	$(CC) main.c $(FLAGS) $(LIB) -o uuid.exe 
