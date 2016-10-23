CC=./../opt/cross/bin/i686-elf-gcc
AS=./../opt/cross/bin/i686-elf-as

CFLAGS= -std=gnu99 -ffreestanding -O2 -Wall -Wextra
ASFLAGS= --32

KERNEL_IMG=binary/marathon.bin

LINK_LOC=source/linker.ld

CPATH=source/c/
HPATH=source/c/headers
ASPATH=source/asm/
OBJPATH=binary/objects/

OBJECTS=$(OBJPATH)entrypoint.o \
	$(OBJPATH)marathon.o

all: $(KERNEL_IMG)

$(OBJPATH)%.o : $(CPATH)%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)%.o : $(ASPATH)%.asm
	$(AS) $(ASFLAGS) $< -o $@

$(KERNEL_IMG) : $(OBJECTS) $(LINK_LOC)
	$(CC) -T $(LINK_LOC) -o $(KERNEL_IMG) $(OBJECTS) -lgcc -ffreestanding -O2 -nostdlib
