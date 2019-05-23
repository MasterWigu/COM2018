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
	sub	esp, 8
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 2
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i1
; IMM
	push	dword 1
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i2
; LABEL
$_i1:
; LOCAL
	lea	eax, [ebp+8]
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
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$_factorial
; TRASH
	add	esp, 4
; PUSH
	push	eax
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; TRASH
	add	esp, 4
; LABEL
$_i2:
; LOCV
	push	dword [ebp+-4]
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
