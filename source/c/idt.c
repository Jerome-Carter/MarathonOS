#include "headers/idt.h"
#include "headers/vga.h"

void idt_set_gate(uint8_t number, uint32_t base, uint16_t selector, uint8_t flags){
    idt_entries[number].base_low = base & 0xFFFF;
    idt_entries[number].base_high = (base >> 16) & 0xFFFF;

    idt_entries[number].selector = selector;
    idt_entries[number].zero = 0;

    idt_entries[number].flags = flags;
}

void idt_init() {
    idt_pointer.limit = sizeof(idt_entry_t) * 256 -1;
    idt_pointer.base = (uint32_t)&idt_entries;
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_pointer));
    print("INFO: IDT Initialized\n");
}

