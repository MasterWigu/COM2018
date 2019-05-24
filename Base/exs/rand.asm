; DATA
segment	.data
; ALIGN
align	4
; LABEL
$seed:
; INTEGER
	dd	100003
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$mod:
; INTEGER
	dd	1000000
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_srand:function
; LABEL
$_srand:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; GE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setge	cl
	mov	[esp], ecx
; COPY
	push	dword [esp]
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i1
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; ADDR
	push	dword $mod
; LOAD
	pop	eax
	push	dword [eax]
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; LABEL
$_i1:
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i2
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; COPY
	push	dword [esp]
; ADDRA
	pop	eax
	mov	[$seed], eax
; TRASH
	add	esp, 4
; LABEL
$_i2:
; LEAVE
	leave
; RET
	ret
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_rand:function
; LABEL
$_rand:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; ADDR
	push	dword $seed
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 27983
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword 149
; ADD
	pop	eax
	add	dword [esp], eax
; ADDR
	push	dword $mod
; LOAD
	pop	eax
	push	dword [eax]
; MOD
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
; COPY
	push	dword [esp]
; ADDRA
	pop	eax
	mov	[$seed], eax
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
