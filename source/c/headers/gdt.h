#ifndef GDT_H
#define GDT_H

#include <stdint.h>

struct gdt_entry_struct{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_pointer_struct{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));
typedef struct gdt_pointer_struct gdt_pointer_t;

extern void flush_gdt(gdt_pointer_t * gdt_pointer);

gdt_entry_t gdt_entries[5];
gdt_pointer_t gdt_pointer;

void set_gdt_gate(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);
void gdt_init();

#endif
