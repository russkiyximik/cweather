CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c23
TARGET = cweather
SRC = src/main.c src/terminal.c src/render.c src/weather.c

.PHONY: all run clean

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)