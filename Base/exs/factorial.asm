; DATA
segment	.data
; ALIGN
align	4
; LABEL
$n:
; GLOBL
global	$n:object
; INTEGER
	dd	5
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_entry:function
; LABEL
$_entry:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i1
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_atoi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; COPY
	push	dword [esp]
; ADDRA
	pop	eax
	mov	[$n], eax
; TRASH
	add	esp, 4
; LABEL
$_i1:
; ADDR
	push	dword $n
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; CHAR
	db	0x21
; CHAR
	db	0x20
; CHAR
	db	0x3D
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i2
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $n
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_factorial
; TRASH
	add	esp, 4
; PUSH
	push	eax
; CALL
	call	$_printd
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; TRASH
	add	esp, 0
; PUSH
	push	eax
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+-4]
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
; EXTRN
extern	$_printd
; EXTRN
extern	$_println
; EXTRN
extern	$_atoi
; EXTRN
extern	$_factorial
