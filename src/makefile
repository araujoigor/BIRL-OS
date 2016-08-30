CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

AS = nasm
ASFLAGS = -f elf

INTERMEDIATE_FOLDER = ../bin/intermediates/
LOCAL_CSRC = $(wildcard *.c)
LOCAL_SSRC = $(wildcard *.s)
LINKER_SRC = $(wildcard *.ld)

LOCAL_COBJ = $(addprefix $(INTERMEDIATE_FOLDER), $(LOCAL_CSRC:.c=.o))
LOCAL_SOBJ = $(addprefix $(INTERMEDIATE_FOLDER), $(LOCAL_SSRC:.s=.o))

all: subfolders $(LOCAL_SOBJ) $(LOCAL_COBJ)

subfolders:
	cd common; make;
	cd drivers; make;

$(LOCAL_SOBJ): $(LOCAL_SSRC)
	$(AS) $(ASFLAGS) $< -o $@

$(LOCAL_COBJ): $(LOCAL_CSRC)
	$(CC) $(CFLAGS) $< -o $@


