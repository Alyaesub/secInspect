# variable pour géré les appelle de commande makefile 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
TARGET = secinspect
SRC = src/main.c src/banner.c src/system_info.c
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)