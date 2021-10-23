	.file	"StringFileParser.cpp"
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii ".\\Libs\\StringLib\\StringFileParser.cpp\0"
LC1:
	.ascii "inp\0"
	.text
	.globl	__Z11getFileSizeP6_iobuf
	.def	__Z11getFileSizeP6_iobuf;	.scl	2;	.type	32;	.endef
__Z11getFileSizeP6_iobuf:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	8(%ebp), %eax
	testl	%eax, %eax
	jne	L2
	movl	$5, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L2:
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	leal	-44(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_fstat
	movl	-24(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.globl	__Z14createFileBuffj
	.def	__Z14createFileBuffj;	.scl	2;	.type	32;	.endef
__Z14createFileBuffj:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$2, %eax
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	_calloc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.section .rdata,"dr"
LC2:
	.ascii "text\0"
	.text
	.globl	__Z10countLinesPcjcc
	.def	__Z10countLinesPcjcc;	.scl	2;	.type	32;	.endef
__Z10countLinesPcjcc:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movl	8(%ebp), %eax
	testl	%eax, %eax
	jne	L7
	movl	$17, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC2, (%esp)
	call	__assert
L7:
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
L11:
	movl	12(%ebp), %eax
	addl	$1, %eax
	cmpl	-16(%ebp), %eax
	jbe	L8
	movl	8(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-28(%ebp), %al
	jne	L9
	movl	8(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
L9:
	movl	8(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L10
	addl	$1, -12(%ebp)
L10:
	addl	$1, -16(%ebp)
	jmp	L11
L8:
	movl	-12(%ebp), %eax
	subl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.globl	__Z12readFromFileP6_iobufcc
	.def	__Z12readFromFileP6_iobufcc;	.scl	2;	.type	32;	.endef
__Z12readFromFileP6_iobufcc:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movl	8(%ebp), %eax
	testl	%eax, %eax
	jne	L14
	movl	$37, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L14:
	cmpb	$0, -32(%ebp)
	jne	L15
	movl	$0, %eax
	jmp	L16
L15:
	movl	$16, 4(%esp)
	movl	$1, (%esp)
	call	_calloc
	movl	%eax, -12(%ebp)
	movsbl	-32(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z8fillTextP4TextP6_iobufc
	movl	-12(%ebp), %eax
L16:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.globl	__Z16buildStrPointersP4Textc
	.def	__Z16buildStrPointersP4Textc;	.scl	2;	.type	32;	.endef
__Z16buildStrPointersP4Textc:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	movb	%al, -28(%ebp)
	movl	8(%ebp), %eax
	testl	%eax, %eax
	jne	L18
	movl	$48, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC2, (%esp)
	call	__assert
L18:
	movl	$0, -12(%ebp)
	movl	$1, -16(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	$8, 4(%esp)
	movl	%eax, (%esp)
	call	_calloc
	movl	%eax, -24(%ebp)
	movl	$0, -20(%ebp)
L24:
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-20(%ebp), %eax
	cmpl	%eax, %edx
	jbe	L19
L21:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	-16(%ebp), %ecx
	movl	-12(%ebp), %edx
	addl	%ecx, %edx
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	je	L20
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	-16(%ebp), %ecx
	movl	-12(%ebp), %edx
	addl	%ecx, %edx
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-28(%ebp), %al
	je	L20
	addl	$1, -12(%ebp)
	jmp	L21
L20:
	movl	-20(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-24(%ebp), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %ecx
	movl	-16(%ebp), %eax
	addl	%ecx, %eax
	movl	%eax, (%edx)
	movl	-20(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-24(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, 4(%edx)
	movl	-12(%ebp), %eax
	addl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-28(%ebp), %al
	jne	L22
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	addl	$1, -16(%ebp)
L23:
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	je	L22
	addl	$1, -16(%ebp)
	jmp	L23
L22:
	addl	$1, -16(%ebp)
	movl	$0, -12(%ebp)
	addl	$1, -20(%ebp)
	jmp	L24
L19:
	movl	8(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.globl	__Z8fillTextP4TextP6_iobufc
	.def	__Z8fillTextP4TextP6_iobufc;	.scl	2;	.type	32;	.endef
__Z8fillTextP4TextP6_iobufc:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movb	%al, -12(%ebp)
	movl	12(%ebp), %eax
	testl	%eax, %eax
	jne	L26
	movl	$86, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L26:
	movl	8(%ebp), %eax
	testl	%eax, %eax
	jne	L27
	movl	$87, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC2, (%esp)
	call	__assert
L27:
	movl	8(%ebp), %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z11getFileSizeP6_iobuf
	movl	%eax, 8(%ebx)
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z14createFileBuffj
	movl	%eax, 12(%ebx)
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	8(%ebp), %ecx
	movl	12(%ecx), %ecx
	addl	$1, %ecx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1, 4(%esp)
	movl	%ecx, (%esp)
	call	_fread
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	addl	$1, %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$10, %al
	je	L28
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	addl	$1, %eax
	addl	%edx, %eax
	movb	$10, (%eax)
	movl	8(%ebp), %eax
	movl	8(%ebp), %edx
	movl	8(%edx), %edx
	addl	$1, %edx
	movl	%edx, 8(%eax)
L28:
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	$10, 12(%esp)
	movl	$10, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z10countLinesPcjcc
	movl	%eax, 4(%ebx)
	movsbl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z16buildStrPointersP4Textc
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.globl	__Z10destructorP4Text
	.def	__Z10destructorP4Text;	.scl	2;	.type	32;	.endef
__Z10destructorP4Text:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	testl	%eax, %eax
	jne	L30
	movl	$103, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC2, (%esp)
	call	__assert
L30:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__assert;	.scl	2;	.type	32;	.endef
	.def	_fstat;	.scl	2;	.type	32;	.endef
	.def	_calloc;	.scl	2;	.type	32;	.endef
	.def	_fread;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
