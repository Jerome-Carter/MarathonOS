.section .text
.global flush_idt

.type flush_idt, @function
# void flush_idt(idt_pointer_t *)
flush_idt:
movl    4(%esp),%eax
lidt    (%eax)
ret

.size flush_idt, . - flush_idt
