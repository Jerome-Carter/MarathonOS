CC=i686-elf-gcc
AS=i686-elf-as

CFLAGS= -std=gnu99 -ffreestanding -O2 -Wall -Wextra
ASFLAGS= --32
LDFLAGS= -lgcc -ffreestanding -O2 -nostdlib

KERNEL_IMG=binary/marathon.bin

LINK_LOC=source/linker.ld

CPATH=source/c/
HPATH=source/c/headers
ASPATH=source/asm/
OBJPATH=binary/objects/

OBJECTS=$(OBJPATH)entrypoint.o \
	$(OBJPATH)marathon.o \
	$(OBJPATH)port.o \
	$(OBJPATH)vga.o \
	$(OBJPATH)helpers.o \
	$(OBJPATH)gdt.o \
	$(OBJPATH)gdt_asm.o \
	$(OBJPATH)idt.o \
    $(OBJPATH)idt_asm.o \
    $(OBJPATH)isr.o \
    $(OBJPATH)isr_asm.o \
    $(OBJPATH)irq.o \
    $(OBJPATH)irq_asm.o


all: $(KERNEL_IMG)

run: $(KERNEL_IMG)
	qemu-system-i386 -kernel binary/marathon.bin

clean:
	rm -f binary/*.bin
	rm -f binary/objects/*.o

$(OBJPATH)%.o : $(CPATH)%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)%.o : $(ASPATH)%.asm
	$(AS) $(ASFLAGS) $< -o $@

$(KERNEL_IMG) : $(OBJECTS) $(LINK_LOC)
	$(CC) -T $(LINK_LOC) -o $(KERNEL_IMG) $(OBJECTS) $(LDFLAGS)
