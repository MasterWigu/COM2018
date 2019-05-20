; DATA
segment	.data
; ALIGN
align	4
; LABEL
$x:
; GLOBL
global	$x:object
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0xC3
; CHAR
	db	0xA1
; CHAR
	db	0x20
; CHAR
	db	0x70
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x73
; CHAR
	db	0x6F
; CHAR
	db	0x61
; CHAR
	db	0x6C
; CHAR
	db	0x21
; CHAR
	db	0x00
; DATA
segment	.data
; ID
	dd	$_i1
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
; ADDR
	push	dword $x
; LOAD
	pop	eax
	push	dword [eax]
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
