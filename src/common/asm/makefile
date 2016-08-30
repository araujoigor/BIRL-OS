AS = nasm
ASFLAGS = -f elf
INTERMEDIATE_FOLDER = ../../../bin/intermediates/
SRC = $(wildcard *.s)
OBJ = $(addprefix $(INTERMEDIATE_FOLDER),$(SRC:.s=.o))

all: $(OBJ)

$(OBJ): $(SRC)
	$(AS) $(ASFLAGS) $< -o $@