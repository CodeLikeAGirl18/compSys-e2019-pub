	.file	"a_sum.c"
	.text
	.globl	plus
	.type	plus, @function
plus:
.LFB0:
	.cfi_startproc
	movq	(%rdi), %rdx
	movl	$0, %eax
	jmp	.L2
.L3:
	leaq	(%rdx,%rdx,4), %rdx
	addq	%rdx, %rax
	addq	$8, %rdi
	movq	(%rdi), %rdx
.L2:
	testq	%rdx, %rdx
	jne	.L3
	rep ret
	.cfi_endproc
.LFE0:
	.size	plus, .-plus
	.ident	"GCC: (Debian 6.3.0-18) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
