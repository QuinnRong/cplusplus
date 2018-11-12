	.file	"3.11_float.c"
	.text
	.globl	find_range
	.def	find_range;	.scl	2;	.type	32;	.endef
	.seh_proc	find_range
find_range:
	.seh_endprologue
	pxor	%xmm1, %xmm1
	comiss	%xmm0, %xmm1
	ja	.L5
	ucomiss	%xmm1, %xmm0
	jp	.L8
	jne	.L8
	movl	$1, %eax
	jmp	.L2
.L8:
	comiss	.LC0(%rip), %xmm0
	jbe	.L10
	movl	$2, %eax
	jmp	.L2
.L5:
	movl	$0, %eax
.L2:
	ret
.L10:
	movl	$3, %eax
	jmp	.L2
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC0:
	.long	0
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
