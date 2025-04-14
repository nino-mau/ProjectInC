CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/student.c
OUT = build/app

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)