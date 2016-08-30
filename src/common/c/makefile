CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

INTERMEDIATE_FOLDER = ../../../bin/intermediates/
SRC = $(wildcard *.c)
OBJ = $(addprefix $(INTERMEDIATE_FOLDER),$(SRC:.c=.o))

all: $(OBJ)

($OBJ): $(SRC)
	$(CC) $(CFLAGS) $< -o $@