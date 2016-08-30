LD = ld
LDFLAGS = -T src/link.ld -melf_i386
OBJECTS = $(wildcard bin/intermediates/*.o)

all: iso

outputdir:
	mkdir -p bin/intermediates
	mkdir -p bin/iso/boot/grub

#kernel: outputdir $(OBJECTS)
#	ld $(LDFLAGS) $(OBJECTS) -o bin/kernel.elf
make_source: 
	cd src; make;

kernel: outputdir make_source
	$(LD) $(LDFLAGS) $(OBJECTS) -o bin/kernel.elf

iso: outputdir kernel
	cp bin/kernel.elf bin/iso/boot/kernel.elf
	cp utils/grub/* bin/iso/boot/grub/
	genisoimage -R -b boot/grub/stage2_eltorito \
		-no-emul-boot -boot-load-size 4     \
		-A os -input-charset utf8           \
		-quiet -boot-info-table             \
		-o bin/os.iso bin/iso

run: iso
	qemu-system-i386 -cdrom bin/os.iso

#bin/intermediates/%.o: src/%.c outputdir
#	$(CC) $(CFLAGS) $< -o $@

#bin/intermediates/%.o: src/%.s outputdir
#	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf bin/
