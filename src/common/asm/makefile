AS = nasm
ASFLAGS = -f elf

INTERMEDIATES_PATH = ../../../bin/intermediates
V_PATH = $(INTERMEDIATES_PATH)

SRC = $(wildcard *.s)
OBJ = $(SRC:.s=.o)

all: $(OBJ)

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $(INTERMEDIATES_PATH)/$@