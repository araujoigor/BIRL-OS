CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

INTERMEDIATE_FOLDER = ../../bin/intermediates/
SRC = $(wildcard src/*.c)
OBJ = $(addprefix $(INTERMEDIATE_FOLDER),$(SRC:src/%.c=%.o))

all: $(OBJ)
	echo $(OBJ); echo $(SRC)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -g $< -o $@