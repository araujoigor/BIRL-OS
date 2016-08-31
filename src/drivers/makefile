CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

INTERMEDIATES_PATH = ../../bin/intermediates
VPATH = src:$(INTERMEDIATES_PATH)

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=%.o)

all: $(OBJ)

%.o: %.c 
	$(CC) $(CFLAGS) $< -o $(INTERMEDIATES_PATH)/$@