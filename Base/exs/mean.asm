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
	sub	esp, 20
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; CHAR
	db	0x4E
; CHAR
	db	0xC3
; CHAR
	db	0xBA
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x65
; CHAR
	db	0x20
; CHAR
	db	0x76
; CHAR
	db	0x61
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x70
; CHAR
	db	0x73
; CHAR
	db	0x65
; CHAR
	db	0x75
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x2D
; CHAR
	db	0x61
; CHAR
	db	0x6C
; CHAR
	db	0x65
; CHAR
	db	0x61
; CHAR
	db	0x74
; CHAR
	db	0xC3
; CHAR
	db	0xB3
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0x6F
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x67
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x61
; CHAR
	db	0x72
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i1
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_readi
; TRASH
	add	esp, 0
; PUSH
	push	eax
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-8], eax
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-12], eax
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
; COPY2
	push	dword [esp+4]
	push	dword [esp+4]
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; STORE2
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
; TRASH
	add	esp, 8
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i2
; LABEL
$_i3:
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_rand
; TRASH
	add	esp, 0
; PUSH
	push	eax
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
; DADD
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	faddp	st1
	fstp	qword [esp]
; COPY2
	push	dword [esp+4]
	push	dword [esp+4]
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; STORE2
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
; TRASH
	add	esp, 8
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; COPY
	push	dword [esp]
; INCR
	pop	eax
	add	dword [eax], 1
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_i3
; LABEL
$_i4:
; LABEL
$_i2:
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
; DDIV
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	fdivrp	st1
	fstp	qword [esp]
; CALL
	call	$_printd
; TRASH
	add	esp, 8
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
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; EXTRN
extern	$_prints
; EXTRN
extern	$_printd
; EXTRN
extern	$_println
; EXTRN
extern	$_readi
; EXTRN
extern	$_srand
; EXTRN
extern	$_rand
