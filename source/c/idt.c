#include "headers/idt.h"

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

    memset(&idt_entries, 0, sizeof(idt_entry_t) * 256);

//    idt_set_gate(32, (uint32_t)irq0, 0x08, 0x8E);
//    idt_set_gate(33, (uint32_t)irq1, 0x08, 0x8E);
//    idt_set_gate(34, (uint32_t)irq2, 0x08, 0x8E);
//    idt_set_gate(35, (uint32_t)irq3, 0x08, 0x8E);
//    idt_set_gate(36, (uint32_t)irq4, 0x08, 0x8E);
//    idt_set_gate(37, (uint32_t)irq5, 0x08, 0x8E);
//    idt_set_gate(38, (uint32_t)irq6, 0x08, 0x8E);
//    idt_set_gate(39, (uint32_t)irq7, 0x08, 0x8E);
//    idt_set_gate(40, (uint32_t)irq8, 0x08, 0x8E);
//    idt_set_gate(41, (uint32_t)irq9, 0x08, 0x8E);
//    idt_set_gate(42, (uint32_t)irq10, 0x08, 0x8E);
//    idt_set_gate(43, (uint32_t)irq11, 0x08, 0x8E);
//    idt_set_gate(44, (uint32_t)irq12, 0x08, 0x8E);
//    idt_set_gate(45, (uint32_t)irq13, 0x08, 0x8E);
//    idt_set_gate(46, (uint32_t)irq14, 0x08, 0x8E);
//    idt_set_gate(47, (uint32_t)irq15, 0x08, 0x8E);

    info("Flushing Interrupt Descriptor Table");
    flush_idt(&idt_pointer);
    info("Interrupt Descriptor Table flushed");
    
    //__asm__ __volatile__("lidtl (%0)" : : "r" (&idt_pointer));
    //print("INFO: IDT Initialized\n");
}
