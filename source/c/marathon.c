#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdint.h>
#include "headers/vga.h"
#include "headers/gdt.h"
#include "headers/idt.h"
#include "headers/isr.h"
#include "headers/irq.h"

void main() {
    vga_init(VGA_WHITE, VGA_BLACK);
    gdt_init();
    idt_init();
    isr_init();
    irq_init();
}
