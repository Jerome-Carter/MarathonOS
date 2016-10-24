.section .text
.global outb
.global inb
.global inw

.type outb, @function

outb:

    movzwl	4(%esp), %edx
 	movzbl	8(%esp), %eax

 	outb %al, %dx
 	ret

.size outb, . - outb

.type inb, @function

inb:
    xorl	%eax, %eax
 	movzwl	4(%esp), %edx
 	inb	%dx, %al
 	ret

.size inb, . - inb

.type inw, @function

inw:
    xorl	%eax, %eax
 	movzwl	4(%esp), %edx
 	inw	%dx, %ax
 	ret
.size inw, . - inw
