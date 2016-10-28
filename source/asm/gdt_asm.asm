.section .text
.global flush_gdt

.type flush_gdt, @function
flush_gdt:
	movl 	4(%esp), %eax
	lgdt	(%eax)

	movw	$0x10, %ax
	movw	%ax, %ds
	movw	%ax, %es
	movw	%ax, %fs
	movw	%ax, %gs
	movw	%ax, %ss
	ljmp	$0x08, $.flush
.flush:
	ret

.size flush_gdt, . - flush_gdt
