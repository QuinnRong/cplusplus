	.file	"3.4_mov.c"
	.text
	.globl	mov
	.def	mov;	.scl	2;	.type	32;	.endef
	.seh_proc	mov
mov:
	.seh_endprologue
	movsbl	(%rcx), %eax
	movl	%eax, (%rdx)
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
