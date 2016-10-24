#ifndef IDT_H
#define IDT_H

#include <stdint.h>

typedef struct {
    uint16_t base_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_pointer_t;

idt_entry_t idt_entries[256];
idt_pointer_t idt_pointer;

void idt_set_gate(uint8_t number, uint32_t base, uint16_t selector, uint8_t flags);
void idt_init();

#endif //SUEDEOS_IDT_H