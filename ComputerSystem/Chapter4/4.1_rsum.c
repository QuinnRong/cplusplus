long long rsum(long long *start, long long count)
{
	if (count <= 0)
		return 0;
	return *start + rsum(start + 1, count - 1);
}

/*
# start in %rdi, count in %rsi

rsum:
	pushq	%rbx				# callee-saved
	subq	$32, %rsp
	andq	%rsi, %rsi
	jle	.L3
	mrmovq  (%rdi), %rbx		# get *start
	irmovq  $8, %r8
	addq	$r8, %rdi			# start + 1
	irmovq  $-1, %r8
	addq	$r8, %rsi			# count - 1
	call	rsum
	addq	%rbx, %rax
.L1:
	addq	$32, %rsp
	popq	%rbx
	ret
.L3:
	xorq    %rax, %rax			# set return value to 0
	jmp	.L1

 */