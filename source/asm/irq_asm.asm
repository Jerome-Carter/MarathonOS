.macro irq num, map
.global irq\num
irq\num:
cli
push    $0
push    $\map
jmp     irq_stub
.endm

irq 0, 32
irq 1, 33
irq 2, 34
irq 3, 35
irq 4, 36
irq 5, 37
irq 6, 38
irq 7, 39
irq 8, 40
irq 9, 41
irq 10, 42
irq 11, 43
irq 12, 44
irq 13, 45
irq 14, 46
irq 15, 47

.extern irq_handler
irq_stub:
pusha

mov     %ds, %ax
pushl   %eax
movl    %eax, %esi

movw    $0x10, %ax
movw    %ax, %ds
movw    %ax, %es
movw    %ax, %fs
movw    %ax, %gs

call    irq_handler

pop     %ebx
movl    %esi, %ebx

movw    %bx, %ds
movw    %bx, %es
movw    %bx, %fs
movw    %bx, %gs

popa
add     $8, %esp
sti
iret
