#ifndef IRQ_H
#define IRQ_H

#include "idt.h"
#include "vga.h"
#include "port.h"

extern void irq0 ();
extern void irq1 ();
extern void irq2 ();
extern void irq3 ();
extern void irq4 ();
extern void irq5 ();
extern void irq6 ();
extern void irq7 ();
extern void irq8 ();
extern void irq9 ();
extern void irq10 ();
extern void irq11 ();
extern void irq12 ();
extern void irq13 ();
extern void irq14 ();
extern void irq15 ();

void* irq_routines[16];

void irq_init_handler(int irq, void* handler);
void irq_reset_handler(int irq);

void irq_remap();

void irq_handler(registers_t* r);
void irq_init();

#endif //IRQ_H