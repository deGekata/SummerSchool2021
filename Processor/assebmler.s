	.file	"ASSembler.cpp"
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
	.text
	.globl	__Z15is_args_mathingxh
	.def	__Z15is_args_mathingxh;	.scl	2;	.type	32;	.endef
__Z15is_args_mathingxh:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, -8(%ebp)
	movl	12(%ebp), %edx
	movl	%edx, -4(%ebp)
	movb	%al, -12(%ebp)
	cmpl	$0, -4(%ebp)
	ja	L2
	cmpl	$0, -4(%ebp)
	jb	L11
	cmpl	$6, -8(%ebp)
	ja	L2
L11:
	movl	-8(%ebp), %eax
	sall	$2, %eax
	addl	$L4, %eax
	movl	(%eax), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L4:
	.long	L3
	.long	L5
	.long	L6
	.long	L7
	.long	L8
	.long	L9
	.long	L10
	.text
L3:
	cmpb	$8, -12(%ebp)
	jne	L12
	movl	$1, %eax
	jmp	L13
L12:
	movl	$0, %eax
	jmp	L13
L5:
	cmpb	$-32, -12(%ebp)
	je	L14
	cmpb	$-64, -12(%ebp)
	je	L14
	cmpb	$64, -12(%ebp)
	je	L14
	cmpb	$-96, -12(%ebp)
	je	L14
	cmpb	$96, -12(%ebp)
	je	L14
	cmpb	$32, -12(%ebp)
	je	L14
	cmpb	$64, -12(%ebp)
	jne	L15
L14:
	movl	$1, %eax
	jmp	L13
L15:
	movl	$0, %eax
	jmp	L13
L6:
	cmpb	$-32, -12(%ebp)
	je	L16
	cmpb	$-64, -12(%ebp)
	je	L16
	cmpb	$64, -12(%ebp)
	je	L16
	cmpb	$-96, -12(%ebp)
	je	L16
	cmpb	$64, -12(%ebp)
	je	L16
	cmpb	$8, -12(%ebp)
	jne	L17
L16:
	movl	$1, %eax
	jmp	L13
L17:
	movl	$0, %eax
	jmp	L13
L7:
	cmpb	$8, -12(%ebp)
	jne	L18
	movl	$1, %eax
	jmp	L13
L18:
	movl	$0, %eax
	jmp	L13
L8:
	cmpb	$8, -12(%ebp)
	jne	L19
	movl	$1, %eax
	jmp	L13
L19:
	movl	$0, %eax
	jmp	L13
L9:
	cmpb	$8, -12(%ebp)
	jne	L20
	movl	$1, %eax
	jmp	L13
L20:
	movl	$0, %eax
	jmp	L13
L10:
	cmpb	$16, -12(%ebp)
	jne	L21
	movl	$1, %eax
	jmp	L13
L21:
	movl	$0, %eax
	jmp	L13
L2:
	movl	$0, %eax
L13:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.globl	__Z13write_commandP8MyStringjia
	.def	__Z13write_commandP8MyStringjia;	.scl	2;	.type	32;	.endef
__Z13write_commandP8MyStringjia:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	20(%ebp), %eax
	movb	%al, -8(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %ecx
	movl	12(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %ecx
	movzbl	-8(%ebp), %eax
	andl	$-9, %eax
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	orl	%ebx, %eax
	orl	%ecx, %eax
	movb	%al, (%edx)
	nop
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.section .rdata,"dr"
LC0:
	.ascii "writing imm const :%d\12\12\0"
	.align 4
LC1:
	.ascii "writing imm const :%d  ip %d\12\12\0"
	.text
	.globl	__Z10write_argsP8MyStringPjP12command_args
	.def	__Z10write_argsP8MyStringPjP12command_args;	.scl	2;	.type	32;	.endef
__Z10write_argsP8MyStringPjP12command_args:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movzbl	8(%eax), %eax
	movzbl	%al, %eax
	andl	$16, %eax
	testl	%eax, %eax
	je	L24
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	$0, (%eax)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	4(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L23
L24:
	movl	16(%ebp), %eax
	movzbl	8(%eax), %eax
	movzbl	%al, %eax
	andl	$8, %eax
	testl	%eax, %eax
	jne	L28
	movl	16(%ebp), %eax
	movzbl	8(%eax), %eax
	movzbl	%al, %eax
	andl	$64, %eax
	testl	%eax, %eax
	je	L27
	movl	16(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%eax, %edx
	movl	16(%ebp), %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
L27:
	movl	16(%ebp), %eax
	movzbl	8(%eax), %eax
	movzbl	%al, %eax
	andl	$32, %eax
	testl	%eax, %eax
	je	L23
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	4(%eax), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%eax, %edx
	movl	16(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%edx)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	4(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L23
L28:
	nop
L23:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.section .rdata,"dr"
LC2:
	.ascii "JUMP ARGS:::%s %d\12\12\0"
LC3:
	.ascii "parse_write ask\0"
LC4:
	.ascii "left str %s\12\0"
	.align 4
LC5:
	.ascii "offset before fill_command %d\12\0"
LC6:
	.ascii "left str2 %s\12\0"
LC7:
	.ascii "left str3 %s\12\0"
LC8:
	.ascii "%hu flags  %d\12\12\0"
LC9:
	.ascii "%d new offset\12\12\0"
LC10:
	.ascii ".\\ASSembler\\ASSembler.cpp\0"
	.align 4
LC11:
	.ascii "0 && \"args not matching\\n\\n\\n\"\0"
	.text
	.globl	__Z16parse_write_argsP8MyStringxaPaS0_PjS2_
	.def	__Z16parse_write_argsP8MyStringxaPaS0_PjS2_;	.scl	2;	.type	32;	.endef
__Z16parse_write_argsP8MyStringxaPaS0_PjS2_:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	20(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%ebx, -32(%ebp)
	movl	16(%ebp), %ebx
	movl	%ebx, -28(%ebp)
	movb	%cl, -36(%ebp)
	movl	-32(%ebp), %ecx
	xorl	$6, %ecx
	movl	%ecx, %eax
	movl	-28(%ebp), %ecx
	xorb	$0, %ch
	movl	%ecx, %edx
	orl	%edx, %eax
	testl	%eax, %eax
	jne	L30
	movl	32(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	28(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z15skip_delimitersP8MyStringj
	movl	%eax, %edx
	movl	32(%ebp), %eax
	movl	%edx, (%eax)
	movl	32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	28(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16fill_command_argP8MyStringPj
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	36(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	$228, (%eax)
	movl	36(%ebp), %eax
	movl	(%eax), %eax
	leal	4(%eax), %edx
	movl	36(%ebp), %eax
	movl	%edx, (%eax)
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
	movl	-16(%ebp), %ecx
	movl	12(%ecx), %ecx
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	jmp	L29
L30:
	movl	24(%ebp), %eax
	movb	$0, (%eax)
	movl	$LC3, (%esp)
	call	_puts
	movb	$0, -9(%ebp)
L36:
	movzbl	-9(%ebp), %eax
	cmpb	-36(%ebp), %al
	jge	L38
	movl	32(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	28(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z15skip_delimitersP8MyStringj
	movl	%eax, %edx
	movl	32(%ebp), %eax
	movl	%edx, (%eax)
	movl	28(%ebp), %eax
	movl	(%eax), %edx
	movl	32(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	32(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	28(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16fill_command_argP8MyStringPj
	movl	%eax, -20(%ebp)
	movl	28(%ebp), %eax
	movl	(%eax), %edx
	movl	32(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	cmpl	$0, -20(%ebp)
	je	L39
	movl	24(%ebp), %eax
	movzbl	(%eax), %edx
	movl	-20(%ebp), %eax
	movzbl	8(%eax), %eax
	orl	%eax, %edx
	movl	24(%ebp), %eax
	movb	%dl, (%eax)
	movl	28(%ebp), %eax
	movl	(%eax), %edx
	movl	32(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	-20(%ebp), %eax
	movl	4(%eax), %edx
	movl	-20(%ebp), %eax
	movzbl	8(%eax), %eax
	movzbl	%al, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	-20(%ebp), %eax
	movzbl	8(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, 8(%esp)
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	__Z15is_args_mathingxh
	testb	%al, %al
	je	L34
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10write_argsP8MyStringPjP12command_args
	movl	32(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	28(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16get_lexem_offsetP8MyStringj
	movl	%eax, %edx
	movl	32(%ebp), %eax
	movl	%edx, (%eax)
	movl	32(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
	jmp	L37
L34:
	movl	$93, 8(%esp)
	movl	$LC10, 4(%esp)
	movl	$LC11, (%esp)
	call	__assert
L37:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movzbl	-9(%ebp), %eax
	addl	$1, %eax
	movb	%al, -9(%ebp)
	jmp	L36
L38:
	nop
	jmp	L29
L39:
	nop
L29:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.section .rdata,"dr"
LC12:
	.ascii "write 0 \0"
LC13:
	.ascii "write 1 \0"
LC14:
	.ascii "0 && \"ASSembling error\"\0"
LC15:
	.ascii "program last sym %d\12\0"
	.text
	.globl	__Z15compile_programP6_iobufS0_
	.def	__Z15compile_programP6_iobufS0_;	.scl	2;	.type	32;	.endef
__Z15compile_programP6_iobufS0_:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$1, 4(%esp)
	movl	$1, (%esp)
	call	_calloc
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movb	$97, (%eax)
	movl	$35, 8(%esp)
	movl	$10, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12readFromFileP6_iobufcc
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$1, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	movl	$LC12, (%esp)
	call	_puts
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z13decode_lexemsP4Text
	movl	%eax, -20(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$1, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	movl	$LC13, (%esp)
	call	_puts
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$-1, %eax
	jne	L41
	movl	$112, 8(%esp)
	movl	$LC10, 4(%esp)
	movl	$LC14, (%esp)
	call	__assert
L41:
	movl	-20(%ebp), %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	subl	$1, %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$LC15, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22write_programm_on_diskP8MyStringP6_iobuf
	movl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE27:
	.section .rdata,"dr"
LC16:
	.ascii "new line %d\12\12\0"
LC17:
	.ascii "before command id\0"
LC18:
	.ascii "after command id\0"
LC19:
	.ascii "after -2 if command id: %d\12\0"
LC20:
	.ascii "cur_offset %d \12\12\0"
LC21:
	.ascii "write command\0"
LC22:
	.ascii "last sym %d %d\12\0"
	.align 4
LC23:
	.ascii "str size: %d  offset:%d, str:'%s'\12\0"
LC24:
	.ascii "0 && \"Too many args\"\0"
LC25:
	.ascii "%d program bef ip command eq\12\0"
	.text
	.globl	__Z13decode_lexemsP4Text
	.def	__Z13decode_lexemsP4Text;	.scl	2;	.type	32;	.endef
__Z13decode_lexemsP4Text:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	$0, -32(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -36(%ebp)
	movl	$-2, -20(%ebp)
	movl	$8, 4(%esp)
	movl	$1, (%esp)
	call	_calloc
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	_calloc
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	movl	%edx, (%eax)
	movl	$0, -12(%ebp)
L59:
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	cmpl	%eax, %edx
	jbe	L44
	movl	$0, -32(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC16, (%esp)
	call	_printf
	movl	-32(%ebp), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	-12(%ebp), %ecx
	sall	$3, %ecx
	addl	%ecx, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__Z15skip_delimitersP8MyStringj
	movl	%eax, -32(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	movl	4(%eax), %eax
	movl	%eax, %edx
	movl	-32(%ebp), %eax
	cmpl	%eax, %edx
	jne	L45
	movl	$0, -32(%ebp)
	jmp	L46
L45:
	movl	$LC17, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__Z14get_command_idP8MyStringPj
	movl	%eax, -20(%ebp)
	movl	$LC18, (%esp)
	call	_puts
	cmpl	$-2, -20(%ebp)
	jne	L47
	movl	-24(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	$0, %eax
	jmp	L60
L47:
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	movl	-36(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -36(%ebp)
	movl	%eax, -16(%ebp)
	movb	$0, -25(%ebp)
	cmpl	$6, -20(%ebp)
	ja	L61
	movl	-20(%ebp), %eax
	sall	$2, %eax
	addl	$L51, %eax
	movl	(%eax), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L51:
	.long	L50
	.long	L52
	.long	L53
	.long	L54
	.long	L55
	.long	L56
	.long	L57
	.text
L50:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	leal	-36(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	%edx, 20(%esp)
	leal	-37(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$1, 12(%esp)
	movl	$0, 4(%esp)
	movl	$0, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16parse_write_argsP8MyStringxaPaS0_PjS2_
	jmp	L58
L52:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	leal	-36(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	%edx, 20(%esp)
	leal	-37(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$1, 12(%esp)
	movl	$1, 4(%esp)
	movl	$0, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16parse_write_argsP8MyStringxaPaS0_PjS2_
	jmp	L58
L53:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	leal	-36(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	%edx, 20(%esp)
	leal	-37(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$1, 12(%esp)
	movl	$2, 4(%esp)
	movl	$0, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16parse_write_argsP8MyStringxaPaS0_PjS2_
	jmp	L58
L54:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	leal	-36(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	%edx, 20(%esp)
	leal	-37(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$1, 12(%esp)
	movl	$3, 4(%esp)
	movl	$0, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16parse_write_argsP8MyStringxaPaS0_PjS2_
	jmp	L58
L55:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	leal	-36(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	%edx, 20(%esp)
	leal	-37(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$1, 12(%esp)
	movl	$4, 4(%esp)
	movl	$0, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16parse_write_argsP8MyStringxaPaS0_PjS2_
	jmp	L58
L56:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	leal	-36(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	%edx, 20(%esp)
	leal	-37(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$1, 12(%esp)
	movl	$5, 4(%esp)
	movl	$0, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16parse_write_argsP8MyStringxaPaS0_PjS2_
	jmp	L58
L57:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	leal	-36(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	%edx, 20(%esp)
	leal	-37(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$1, 12(%esp)
	movl	$6, 4(%esp)
	movl	$0, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16parse_write_argsP8MyStringxaPaS0_PjS2_
	jmp	L58
L61:
	nop
L58:
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC20, (%esp)
	call	_printf
	movl	$LC21, (%esp)
	call	_puts
	movzbl	-37(%ebp), %eax
	movsbl	%al, %edx
	movl	-20(%ebp), %eax
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z13write_commandP8MyStringjia
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	setne	%al
	movzbl	%al, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$3, %ecx
	addl	%ecx, %eax
	movl	(%eax), %ecx
	movl	-32(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC22, (%esp)
	call	_printf
	movl	-32(%ebp), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	-12(%ebp), %ecx
	sall	$3, %ecx
	addl	%ecx, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__Z15skip_delimitersP8MyStringj
	movl	%eax, -32(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	movl	-32(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$3, %ecx
	addl	%ecx, %eax
	movl	4(%eax), %ecx
	movl	(%edx), %eax
	movl	4(%edx), %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	$LC23, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	movl	4(%eax), %eax
	movl	%eax, %edx
	movl	-32(%ebp), %eax
	cmpl	%eax, %edx
	je	L46
	movl	$167, 8(%esp)
	movl	$LC10, 4(%esp)
	movl	$LC24, (%esp)
	call	__assert
L46:
	addl	$1, -12(%ebp)
	jmp	L59
L44:
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_printf
	movl	-36(%ebp), %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-24(%ebp), %eax
L60:
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.section .rdata,"dr"
LC26:
	.ascii "writing program: '%d'\0"
LC27:
	.ascii "%hu_ \0"
LC28:
	.ascii "  %d\12\0"
LC29:
	.ascii "%d fiiile\0"
	.section	.text$_Z22write_programm_on_diskP8MyStringP6_iobuf,"x"
	.linkonce discard
	.globl	__Z22write_programm_on_diskP8MyStringP6_iobuf
	.def	__Z22write_programm_on_diskP8MyStringP6_iobuf;	.scl	2;	.type	32;	.endef
__Z22write_programm_on_diskP8MyStringP6_iobuf:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC26, (%esp)
	call	_printf
	movl	$0, -12(%ebp)
L64:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jle	L63
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$LC27, (%esp)
	call	_printf
	addl	$1, -12(%ebp)
	jmp	L64
L63:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC28, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC29, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	_fwrite
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__Z15skip_delimitersP8MyStringj;	.scl	2;	.type	32;	.endef
	.def	__Z16fill_command_argP8MyStringPj;	.scl	2;	.type	32;	.endef
	.def	__Z9hashFunc_PKcjx;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__Z16get_lexem_offsetP8MyStringj;	.scl	2;	.type	32;	.endef
	.def	__assert;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_calloc;	.scl	2;	.type	32;	.endef
	.def	__Z12readFromFileP6_iobufcc;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	__Z14get_command_idP8MyStringPj;	.scl	2;	.type	32;	.endef
