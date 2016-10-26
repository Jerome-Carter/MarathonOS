#include "headers/isr.h"

void isr_init() {
    idt_set_gate(0, (uint32_t)isr0, 0x08, 0x8E);
    idt_set_gate(1, (uint32_t)isr1, 0x08, 0x8E);
    idt_set_gate(2, (uint32_t)isr2, 0x08, 0x8E);
    idt_set_gate(3, (uint32_t)isr3, 0x08, 0x8E);
    idt_set_gate(4, (uint32_t)isr4, 0x08, 0x8E);
    idt_set_gate(5, (uint32_t)isr5, 0x08, 0x8E);
    idt_set_gate(6, (uint32_t)isr6, 0x08, 0x8E);
    idt_set_gate(7, (uint32_t)isr7, 0x08, 0x8E);
    idt_set_gate(8, (uint32_t)isr8, 0x08, 0x8E);
    idt_set_gate(9, (uint32_t)isr9, 0x08, 0x8E);
    idt_set_gate(10, (uint32_t)isr10, 0x08, 0x8E);
    idt_set_gate(11, (uint32_t)isr11, 0x08, 0x8E);
    idt_set_gate(12, (uint32_t)isr12, 0x08, 0x8E);
    idt_set_gate(13, (uint32_t)isr13, 0x08, 0x8E);
    idt_set_gate(14, (uint32_t)isr14, 0x08, 0x8E);
    idt_set_gate(15, (uint32_t)isr15, 0x08, 0x8E);
    idt_set_gate(16, (uint32_t)isr16, 0x08, 0x8E);
    idt_set_gate(17, (uint32_t)isr17, 0x08, 0x8E);
    idt_set_gate(18, (uint32_t)isr18, 0x08, 0x8E);
    idt_set_gate(19, (uint32_t)isr19, 0x08, 0x8E);
    idt_set_gate(20, (uint32_t)isr20, 0x08, 0x8E);
    idt_set_gate(21, (uint32_t)isr21, 0x08, 0x8E);
    idt_set_gate(22, (uint32_t)isr22, 0x08, 0x8E);
    idt_set_gate(23, (uint32_t)isr23, 0x08, 0x8E);
    idt_set_gate(24, (uint32_t)isr24, 0x08, 0x8E);
    idt_set_gate(25, (uint32_t)isr25, 0x08, 0x8E);
    idt_set_gate(26, (uint32_t)isr26, 0x08, 0x8E);
    idt_set_gate(27, (uint32_t)isr27, 0x08, 0x8E);
    idt_set_gate(28, (uint32_t)isr28, 0x08, 0x8E);
    idt_set_gate(29, (uint32_t)isr29, 0x08, 0x8E);
    idt_set_gate(30, (uint32_t)isr30, 0x08, 0x8E);
    idt_set_gate(31, (uint32_t)isr31, 0x08, 0x8E);
}

void isr0 () {
    fault_handler(0);
}

void isr1 () {
    fault_handler(1);
}

void isr2 () {
    fault_handler(2);
}

void isr3 () {
    fault_handler(3);
}

void isr4 () {
    fault_handler(4);
}

void isr5 () {
    fault_handler(5);
}

void isr6 () {
    fault_handler(6);
}

void isr7 () {
    fault_handler(7);
}

void isr8 () {
    fault_handler(8);
}

void isr9 () {
    fault_handler(9);
}

void isr10 () {
    fault_handler(10);
}

void isr11 () {
    fault_handler(11);
}

void isr12 () {
    fault_handler(12);
}

void isr13 () {
    fault_handler(13);
}

void isr14 () {
    fault_handler(14);
}

void isr15 () {
    fault_handler(15);
}

void isr16 () {
    fault_handler(16);
}

void isr17 () {
    fault_handler(17);
}

void isr18 () {
    fault_handler(18);
}

void isr19 () {
    fault_handler(19);
}

void isr20 () {
    fault_handler(20);
}

void isr21 () {
    fault_handler(21);
}

void isr22 () {
    fault_handler(22);
}

void isr23 () {
    fault_handler(23);
}

void isr24 () {
    fault_handler(24);
}

void isr25 () {
    fault_handler(25);
}

void isr26 () {
    fault_handler(26);
}

void isr27 () {
    fault_handler(27);
}

void isr28 () {
    fault_handler(28);
}

void isr29 () {
    fault_handler(29);
}

void isr30 () {
    fault_handler(30);
}

void isr31 () {
    fault_handler(31);
}

const char* exceptions[] = {
    "Division By Zero Exception",
    "Debug Exception",
    "Non-Maskable Interrupt Exception",
    "Breakpoint Exception",
    "Overflow Exception",
    "Out of Bounds Exception",
    "Invalid Opcode Exception",
    "Missing Coprocessor Exception",
    "Double Fault Exception",
    "Coprocessor Segment Overrun Exception",
    "Invalid TSS Exception",
    "Segment Not Present Exception",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt Exception",
    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
};

void fault_handler(int isr) {
    if (isr < 32) {
        print("\nFATAL: ");
        print(exceptions[isr]);
        print("\nINFO: System halted\n");
        for (;;);
    }
}
