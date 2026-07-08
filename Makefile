CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c20
TARGET = cweather
SRC = src/main.c

.PHONY: all run clean

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)