#include "headers/vga.h"
#include "headers/messages.h"
#include "headers/gdt.h"

void set_gdt_gate(int32_t entry, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran){

    gdt_entries[entry].base_low = (base & 0xFFFF);
    gdt_entries[entry].base_middle = (base >> 16) & 0xFF;
    gdt_entries[entry].base_high = (base >> 24) & 0xFF;

    gdt_entries[entry].limit_low = (limit & 0xFFFF);
    gdt_entries[entry].granularity = (limit >> 16) & 0x0F;

    gdt_entries[entry].granularity |= gran & 0xF0;
    gdt_entries[entry].access = access;

}

void gdt_init(){

    info("Initializing Global Descriptor Table");

    gdt_pointer.limit = (sizeof(gdt_entry_t)*5) - 1;
    gdt_pointer.base = (uint32_t)&gdt_entries;

    /*
     Pr  Priv  1   Ex  DC   RW   Ac
     0x9A == 1001 1010  == 1   00    1   1   0    1    0
     0x92 == 1001 0010  == 1   00    1   0   0    1    0
     0xFA == 1111 1010  == 1   11    1   1   0    1    0
     0xF2 == 1111 0010  == 1   11    1   0   0    1    0

     We have page-granularity and 32-bit mode

     G   D   0   Av
     0xCF == 1100 1111  == 1   1   0   0  ~

     */

    set_gdt_gate(0, 0, 0, 0, 0);
    set_gdt_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    set_gdt_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    set_gdt_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
    set_gdt_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

    info("Flushing Global Descriptor Table");
    flush_gdt(&gdt_pointer);
    info("Global Descriptor Table flushed");
    
}
