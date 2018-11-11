	.file	"3.6_jmp.c"
	.text
	.globl	absdiff_se
	.def	absdiff_se;	.scl	2;	.type	32;	.endef
	.seh_proc	absdiff_se
absdiff_se:
	.seh_endprologue
	cmpq	%rdx, %rcx
	jge	.L2
	addq	$1, lt_cnt(%rip)
	movq	%rdx, %rax
	subq	%rcx, %rax
.L1:
	ret
.L2:
	addq	$1, ge_cnt(%rip)
	movq	%rcx, %rax
	subq	%rdx, %rax
	jmp	.L1
	.seh_endproc
	.globl	gotodiff_se
	.def	gotodiff_se;	.scl	2;	.type	32;	.endef
	.seh_proc	gotodiff_se
gotodiff_se:
	.seh_endprologue
	cmpq	%rdx, %rcx
	jge	.L7
	addq	$1, lt_cnt(%rip)
	movq	%rdx, %rax
	subq	%rcx, %rax
.L4:
	ret
.L7:
	addq	$1, ge_cnt(%rip)
	movq	%rcx, %rax
	subq	%rdx, %rax
	jmp	.L4
	.seh_endproc
	.globl	ge_cnt
	.bss
	.align 8
ge_cnt:
	.space 8
	.globl	lt_cnt
	.align 8
lt_cnt:
	.space 8
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
