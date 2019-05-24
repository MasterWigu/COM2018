; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_factorial:function
; LABEL
$_factorial:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 24
; IMM
	push	dword 1
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
; COPY2
	push	dword [esp+4]
	push	dword [esp+4]
; LOCAL
	lea	eax, [ebp+-4]
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
	lea	eax, [ebp+8]
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
	je	near $_i1
; LABEL
$_i2:
; LABEL
$_i4:
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
; DMUL
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	fmulp	st1
	fstp	qword [esp]
; COPY2
	push	dword [esp+4]
	push	dword [esp+4]
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; STORE2
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
; TRASH
	add	esp, 8
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-24], eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i5
; IMM
	push	dword 1
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_i4
; LABEL
$_i5:
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; COPY
	push	dword [esp]
; DECR
	pop	eax
	sub	dword [eax], 1
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
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_i2
; LABEL
$_i3:
; LABEL
$_i1:
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
; IMM
	push	dword 2
; CALL
	call	$_factorial
; TRASH
	add	esp, 4
; PUSH
	push	eax
; CALL
	call	$_printd
; TRASH
	add	esp, 8
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i6:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i6
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; IMM
	push	dword 5
; CALL
	call	$_factorial
; TRASH
	add	esp, 4
; PUSH
	push	eax
; CALL
	call	$_printd
; TRASH
	add	esp, 8
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i7:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i7
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; IMM
	push	dword 10
; CALL
	call	$_factorial
; TRASH
	add	esp, 4
; PUSH
	push	eax
; CALL
	call	$_printd
; TRASH
	add	esp, 8
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i8:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i8
; CALL
	call	$_prints
; TRASH
	add	esp, 4
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
extern	$_printd
; EXTRN
extern	$_prints
