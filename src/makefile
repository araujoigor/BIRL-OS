CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

AS = nasm
ASFLAGS = -f elf

INTERMEDIATES_PATH = ../bin/intermediates
VPATH = $(INTERMEDIATES_PATH)

LOCAL_CSRC = $(wildcard *.c)
LOCAL_SSRC = $(wildcard *.s)
LINKER_SRC = $(wildcard *.ld)

LOCAL_COBJ = $(LOCAL_CSRC:.c=.o)
LOCAL_SOBJ = $(LOCAL_SSRC:.s=.o)

all: subfolders $(LOCAL_SOBJ) $(LOCAL_COBJ)

subfolders:
	cd common; make;
	cd drivers; make;

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $(INTERMEDIATES_PATH)/$@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $(INTERMEDIATES_PATH)/$@


