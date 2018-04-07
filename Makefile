
CC=gcc
CFLAGS=-Wall
LDFLAGS=-lfmod -L lib-ext/fmodstudioapi11004linux/api/lowlevel/lib/x86_64/

TARGET_NAME=itunes.bin


default: all




all:
	gcc -o $(TARGET_NAME) src/itunes.c $(CFLAGS) $(LDFLAGS)

clean:
	rm $(TARGET_NAME)


run:	all
	LD_LIBRARY_PATH=lib-ext/fmodstudioapi11004linux/api/lowlevel/lib/x86_64/ ./$(TARGET_NAME)

