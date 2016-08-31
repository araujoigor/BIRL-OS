CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

INTERMEDIATES_PATH = ../../../bin/intermediates
V_PATH = $(INTERMEDIATES_PATH)

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $(INTERMEDIATES_PATH)/$@