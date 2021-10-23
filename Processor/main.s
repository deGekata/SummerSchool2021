	.file	"main.cpp"
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
	.def	___main;	.scl	2;	.type	32;	.endef
LC0:
	.ascii "r\0"
LC1:
	.ascii "./ASSembler/input.txt\0"
LC2:
	.ascii "w+\0"
LC3:
	.ascii "output.txt\0"
LC4:
	.ascii "%d %d\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	call	__Z20init_commands_hashesv
	call	__Z22printf_commands_hashesv
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_fopen
	movl	%eax, 28(%esp)
	movl	$LC2, 4(%esp)
	movl	$LC3, (%esp)
	call	_fopen
	movl	%eax, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z15compile_programP6_iobufS0_
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__Z20init_commands_hashesv;	.scl	2;	.type	32;	.endef
	.def	__Z22printf_commands_hashesv;	.scl	2;	.type	32;	.endef
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__Z15compile_programP6_iobufS0_;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
