	.file	"Lexer.cpp"
	.section .rdata,"dr"
__ZL5empty:
	.byte	8
__ZL4mark:
	.byte	16
__ZL18immediate_constant:
	.byte	32
__ZL3reg:
	.byte	64
__ZL3mem:
	.byte	-128
	.globl	_commands_hashes
	.bss
	.align 32
_commands_hashes:
	.space 64
	.section .rdata,"dr"
LC0:
	.ascii "HLT\0"
LC1:
	.ascii "HLT hash: %ld\12\12\0"
LC2:
	.ascii "PUSH\0"
LC3:
	.ascii "PUSH hash: %ld\12\12\0"
LC4:
	.ascii "POP\0"
LC5:
	.ascii "POP hash: %ld\12\12\0"
LC6:
	.ascii "ADD\0"
LC7:
	.ascii "ADD hash: %ld\12\12\0"
LC8:
	.ascii "SUB\0"
LC9:
	.ascii "SUB hash: %ld\12\12\0"
LC10:
	.ascii "MUL\0"
LC11:
	.ascii "MUL hash: %ld\12\12\0"
LC12:
	.ascii "JMP\0"
LC13:
	.ascii "JMP hash: %ld\12\12\0"
	.text
	.globl	__Z20init_commands_hashesv
	.def	__Z20init_commands_hashesv;	.scl	2;	.type	32;	.endef
__Z20init_commands_hashesv:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC0, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, _commands_hashes
	movl	%edx, _commands_hashes+4
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC0, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$4, 4(%esp)
	movl	$LC2, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, _commands_hashes+8
	movl	%edx, _commands_hashes+12
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$4, 4(%esp)
	movl	$LC2, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC4, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, _commands_hashes+16
	movl	%edx, _commands_hashes+20
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC4, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC6, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, _commands_hashes+24
	movl	%edx, _commands_hashes+28
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC6, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC8, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, _commands_hashes+32
	movl	%edx, _commands_hashes+36
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC8, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC9, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC10, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, _commands_hashes+40
	movl	%edx, _commands_hashes+44
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC10, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC11, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC12, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, _commands_hashes+48
	movl	%edx, _commands_hashes+52
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$3, 4(%esp)
	movl	$LC12, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC13, (%esp)
	call	_printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.section .rdata,"dr"
LC14:
	.ascii "%ld\12\12\0"
	.text
	.globl	__Z22printf_commands_hashesv
	.def	__Z22printf_commands_hashesv;	.scl	2;	.type	32;	.endef
__Z22printf_commands_hashesv:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
L4:
	cmpl	$7, -12(%ebp)
	jg	L5
	movl	-12(%ebp), %eax
	movl	_commands_hashes+4(,%eax,8), %edx
	movl	_commands_hashes(,%eax,8), %eax
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC14, (%esp)
	call	_printf
	addl	$1, -12(%ebp)
	jmp	L4
L5:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.globl	__Z9hashFunc_PKcjx
	.def	__Z9hashFunc_PKcjx;	.scl	2;	.type	32;	.endef
__Z9hashFunc_PKcjx:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%eax, -8(%ebp)
	movl	%edx, -4(%ebp)
	movl	$0, -12(%ebp)
L8:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jnb	L7
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movl	%eax, %ecx
	movzbl	%cl, %eax
	movl	$0, %edx
	addl	%eax, -8(%ebp)
	adcl	%edx, -4(%ebp)
	movl	-8(%ebp), %eax
	movl	-4(%ebp), %edx
	shldl	$20, %eax, %edx
	sall	$20, %eax
	addl	%eax, -8(%ebp)
	adcl	%edx, -4(%ebp)
	movl	-8(%ebp), %eax
	movl	-4(%ebp), %edx
	shrdl	$12, %edx, %eax
	shrl	$12, %edx
	xorl	%eax, -8(%ebp)
	xorl	%edx, -4(%ebp)
	addl	$1, 8(%ebp)
	addl	$1, -12(%ebp)
	jmp	L8
L7:
	movl	-8(%ebp), %eax
	movl	-4(%ebp), %edx
	shldl	$6, %eax, %edx
	sall	$6, %eax
	addl	%eax, -8(%ebp)
	adcl	%edx, -4(%ebp)
	movl	-8(%ebp), %eax
	movl	-4(%ebp), %edx
	shrdl	$22, %edx, %eax
	shrl	$22, %edx
	xorl	%eax, -8(%ebp)
	xorl	%edx, -4(%ebp)
	movl	-8(%ebp), %eax
	movl	-4(%ebp), %edx
	shldl	$29, %eax, %edx
	sall	$29, %eax
	addl	%eax, -8(%ebp)
	adcl	%edx, -4(%ebp)
	movl	-8(%ebp), %eax
	movl	-4(%ebp), %edx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.section	.text$_Z12is_delimiterc,"x"
	.linkonce discard
	.globl	__Z12is_delimiterc
	.def	__Z12is_delimiterc;	.scl	2;	.type	32;	.endef
__Z12is_delimiterc:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	cmpb	$32, -4(%ebp)
	sete	%al
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.section .rdata,"dr"
LC15:
	.ascii "%ld offff beg\12\12\0"
LC16:
	.ascii "%ld offff lex\12\12 \0"
	.text
	.globl	__Z14get_command_idP8MyStringPj
	.def	__Z14get_command_idP8MyStringPj;	.scl	2;	.type	32;	.endef
__Z14get_command_idP8MyStringPj:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$80, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$0, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z15skip_delimitersP8MyStringj
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC15, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	$1, %eax
	cmpl	-12(%ebp), %eax
	jne	L13
	movl	$-1, %eax
	movl	$-1, %edx
	jmp	L14
L13:
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16get_lexem_offsetP8MyStringj
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC16, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	subl	-12(%ebp), %eax
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	_commands_hashes, %eax
	movl	_commands_hashes+4, %edx
	movl	%eax, %ecx
	xorl	-24(%ebp), %ecx
	movl	%ecx, %ebx
	movl	%edx, %eax
	xorl	-20(%ebp), %eax
	movl	%eax, %esi
	movl	%esi, %eax
	orl	%ebx, %eax
	testl	%eax, %eax
	jne	L15
	movl	$0, %eax
	movl	$0, %edx
	jmp	L14
L15:
	movl	_commands_hashes+8, %eax
	movl	_commands_hashes+12, %edx
	movl	%eax, %esi
	xorl	-24(%ebp), %esi
	movl	%esi, -32(%ebp)
	movl	%edx, %eax
	xorl	-20(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	-32(%ebp), %ecx
	movl	-28(%ebp), %ebx
	movl	%ebx, %eax
	orl	%ecx, %eax
	testl	%eax, %eax
	jne	L16
	movl	$1, %eax
	movl	$0, %edx
	jmp	L14
L16:
	movl	_commands_hashes+16, %eax
	movl	_commands_hashes+20, %edx
	movl	%eax, %esi
	xorl	-24(%ebp), %esi
	movl	%esi, -40(%ebp)
	movl	%edx, %eax
	xorl	-20(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-40(%ebp), %ecx
	movl	-36(%ebp), %ebx
	movl	%ebx, %eax
	orl	%ecx, %eax
	testl	%eax, %eax
	jne	L17
	movl	$2, %eax
	movl	$0, %edx
	jmp	L14
L17:
	movl	_commands_hashes+24, %eax
	movl	_commands_hashes+28, %edx
	movl	%eax, %esi
	xorl	-24(%ebp), %esi
	movl	%esi, -48(%ebp)
	movl	%edx, %eax
	xorl	-20(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-48(%ebp), %edx
	movl	-44(%ebp), %ecx
	movl	%ecx, %eax
	orl	%edx, %eax
	testl	%eax, %eax
	jne	L18
	movl	$3, %eax
	movl	$0, %edx
	jmp	L14
L18:
	movl	_commands_hashes+32, %eax
	movl	_commands_hashes+36, %edx
	movl	%eax, %esi
	xorl	-24(%ebp), %esi
	movl	%esi, -56(%ebp)
	movl	%edx, %eax
	xorl	-20(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	-56(%ebp), %edx
	movl	-52(%ebp), %ecx
	movl	%ecx, %eax
	orl	%edx, %eax
	testl	%eax, %eax
	jne	L19
	movl	$4, %eax
	movl	$0, %edx
	jmp	L14
L19:
	movl	_commands_hashes+40, %eax
	movl	_commands_hashes+44, %edx
	movl	%eax, %ebx
	xorl	-24(%ebp), %ebx
	movl	%ebx, -64(%ebp)
	movl	%edx, %eax
	xorl	-20(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-64(%ebp), %ebx
	movl	-60(%ebp), %esi
	movl	%esi, %eax
	orl	%ebx, %eax
	testl	%eax, %eax
	jne	L20
	movl	$5, %eax
	movl	$0, %edx
	jmp	L14
L20:
	movl	_commands_hashes+48, %eax
	movl	_commands_hashes+52, %edx
	movl	%eax, %esi
	xorl	-24(%ebp), %esi
	movl	%esi, -72(%ebp)
	movl	%edx, %eax
	xorl	-20(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-72(%ebp), %edx
	movl	-68(%ebp), %ecx
	movl	%ecx, %eax
	orl	%edx, %eax
	testl	%eax, %eax
	jne	L21
	movl	$6, %eax
	movl	$0, %edx
	jmp	L14
L21:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$1, %eax
	jle	L22
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	$1, %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$58, %al
	jne	L22
	movl	$7, %eax
	movl	$0, %edx
	jmp	L14
L22:
	movl	$-2, %eax
	movl	$-1, %edx
L14:
	addl	$80, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE27:
	.section .rdata,"dr"
LC17:
	.ascii "%1[[]\0"
LC18:
	.ascii "lol\0"
LC19:
	.ascii "scanned string1 %s\12\12\0"
LC20:
	.ascii "%1[abcd]x%1[+]%d%n\0"
LC21:
	.ascii "scanf_ret %d  n:%d lol\12\0"
LC22:
	.ascii "%1[abcd]x%n\0"
LC23:
	.ascii "scanfreturn: %d %d\12\12\0"
LC24:
	.ascii "scanned string %s\12\12\0"
	.align 4
LC25:
	.ascii "scanned reg ans syms: %s   %d\12\12\0"
LC26:
	.ascii "%d%n\0"
LC27:
	.ascii "scanned string in const %s\12\12\0"
LC28:
	.ascii "%1[]]\0"
LC29:
	.ascii "delim: %s\12\0"
LC30:
	.ascii "parse_mark %d\12\12\0"
LC31:
	.ascii "parse_mark in %d mark off\12\12\0"
LC32:
	.ascii "parse_mark gavno '%c' \12\12\0"
LC33:
	.ascii "MARK: %s\12\0"
LC34:
	.ascii "MARK: %d\12\0"
	.text
	.globl	__Z16fill_command_argP8MyStringPj
	.def	__Z16fill_command_argP8MyStringPj;	.scl	2;	.type	32;	.endef
__Z16fill_command_argP8MyStringPj:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	$16, 4(%esp)
	movl	$1, (%esp)
	call	_calloc
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z15skip_delimitersP8MyStringj
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	%eax, %edx
	jne	L24
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	orl	$8, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%dl, 8(%eax)
L24:
	movl	$0, -32(%ebp)
	movl	$1, 4(%esp)
	movl	$2, (%esp)
	call	_calloc
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movb	$100, (%eax)
	movl	$1, 4(%esp)
	movl	$2, (%esp)
	call	_calloc
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %ecx
	movl	12(%ebp), %edx
	movl	(%edx), %edx
	addl	%ecx, %edx
	movl	%eax, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	%edx, (%esp)
	call	_sscanf
	movl	%eax, -24(%ebp)
	cmpl	$1, -24(%ebp)
	jne	L25
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	orl	$-128, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%dl, 8(%eax)
L25:
	movl	$LC18, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	movl	-16(%ebp), %eax
	leal	4(%eax), %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%eax, %edx
	leal	-32(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	%ecx, 16(%esp)
	leal	-36(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	%edx, (%esp)
	call	_sscanf
	movl	%eax, -24(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC21, (%esp)
	call	_printf
	cmpl	$3, -24(%ebp)
	jne	L26
	movl	-32(%ebp), %eax
	testl	%eax, %eax
	je	L26
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	-32(%ebp), %edx
	addl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-20(%ebp), %eax
	movzbl	(%eax), %eax
	subl	$97, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%dl, (%eax)
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	orl	$96, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%dl, 8(%eax)
	jmp	L27
L26:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%eax, %edx
	leal	-32(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC22, 4(%esp)
	movl	%edx, (%esp)
	call	_sscanf
	movl	%eax, -24(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC23, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_printf
	cmpl	$1, -24(%ebp)
	jne	L28
	movl	-32(%ebp), %eax
	testl	%eax, %eax
	je	L28
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	-32(%ebp), %edx
	addl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-20(%ebp), %eax
	movzbl	(%eax), %eax
	subl	$97, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%dl, (%eax)
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	orl	$64, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%dl, 8(%eax)
	jmp	L27
L28:
	movl	-16(%ebp), %eax
	leal	4(%eax), %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%eax, %edx
	leal	-32(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	$LC26, 4(%esp)
	movl	%edx, (%esp)
	call	_sscanf
	movl	%eax, -24(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC23, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC27, (%esp)
	call	_printf
	cmpl	$1, -24(%ebp)
	jne	L27
	movl	-32(%ebp), %eax
	testl	%eax, %eax
	je	L27
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	-32(%ebp), %edx
	addl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	orl	$32, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%dl, 8(%eax)
	nop
L27:
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	testb	%al, %al
	jns	L29
	movl	-36(%ebp), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %ecx
	movl	12(%ebp), %edx
	movl	(%edx), %edx
	addl	%ecx, %edx
	movl	%eax, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	%edx, (%esp)
	call	_sscanf
	movl	%eax, -24(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC29, (%esp)
	call	_printf
	cmpl	$1, -24(%ebp)
	je	L30
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	$0, %eax
	jmp	L39
L30:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	orl	$-128, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%dl, 8(%eax)
L29:
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$LC30, (%esp)
	call	_printf
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	testb	%al, %al
	jne	L32
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16get_lexem_offsetP8MyStringj
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC31, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
L38:
	movl	-12(%ebp), %eax
	cmpl	-28(%ebp), %eax
	jnb	L33
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$96, %al
	jle	L34
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$122, %al
	jle	L35
L34:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$64, %al
	jle	L36
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$90, %al
	jle	L35
L36:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$47, %al
	jle	L37
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$57, %al
	jle	L35
L37:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$LC32, (%esp)
	call	_printf
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	$0, %eax
	jmp	L39
L35:
	addl	$1, -12(%ebp)
	jmp	L38
L33:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC33, (%esp)
	call	_printf
	movl	-16(%ebp), %eax
	movzbl	8(%eax), %eax
	orl	$16, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%dl, 8(%eax)
	movl	$8, 4(%esp)
	movl	$1, (%esp)
	call	_calloc
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	-16(%ebp), %eax
	movl	12(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %ecx
	movl	12(%ebp), %edx
	movl	(%edx), %edx
	addl	%ecx, %edx
	movl	%edx, (%eax)
	movl	-16(%ebp), %eax
	movl	12(%eax), %eax
	movl	12(%ebp), %edx
	movl	(%edx), %edx
	movl	-28(%ebp), %ecx
	subl	%edx, %ecx
	movl	%ecx, %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movl	12(%eax), %eax
	movl	(%eax), %eax
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z9hashFunc_PKcjx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC34, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%eax)
L32:
	movl	-16(%ebp), %eax
L39:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.globl	__Z15skip_delimitersP8MyStringj
	.def	__Z15skip_delimitersP8MyStringj;	.scl	2;	.type	32;	.endef
__Z15skip_delimitersP8MyStringj:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
L44:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
	call	__Z12is_delimiterc
	testb	%al, %al
	je	L41
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	je	L41
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	12(%ebp), %eax
	jbe	L41
	movl	$1, %eax
	jmp	L42
L41:
	movl	$0, %eax
L42:
	testb	%al, %al
	je	L43
	addl	$1, 12(%ebp)
	jmp	L44
L43:
	movl	12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.section .rdata,"dr"
	.align 4
LC35:
	.ascii "%d offset in get_lexem_offset\12\12\0"
	.text
	.globl	__Z16get_lexem_offsetP8MyStringj
	.def	__Z16get_lexem_offsetP8MyStringj;	.scl	2;	.type	32;	.endef
__Z16get_lexem_offsetP8MyStringj:
LFB30:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC35, (%esp)
	call	_printf
L50:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
	call	__Z12is_delimiterc
	xorl	$1, %eax
	testb	%al, %al
	je	L47
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	je	L47
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	12(%ebp), %eax
	jbe	L47
	movl	$1, %eax
	jmp	L48
L47:
	movl	$0, %eax
L48:
	testb	%al, %al
	je	L49
	addl	$1, 12(%ebp)
	jmp	L50
L49:
	movl	12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE30:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_calloc;	.scl	2;	.type	32;	.endef
	.def	_sscanf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
