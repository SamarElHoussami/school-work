; Ass1-Q1.asm - gets user input and does operations on 32-bit signed integers
; Author: Samar El-Housami

INCLUDE Irvine32.inc

.data

	A SDWORD -210
	B SDWORD +10
	C_ SDWORD ?
	D SDWORD ?
	Z SDWORD ?

	prompt1 BYTE "What is the value of C? ",0
	prompt2 BYTE "What is the value of D? ",0
	equation BYTE "Z = (A - B) + (C - D)",0Dh, 0Ah, 0
	delim BYTE "   ;   ",0

.code
main proc

	mov edx, OFFSET prompt1			;read C
	call WriteString
	call ReadInt
	mov C_, eax
	
	mov edx, OFFSET prompt2			;read D
	call WriteString
	call ReadInt
	mov D, eax

	mov edx, OFFSET equation		;print equation
	call WriteString
	
	mov edx, OFFSET delim			;print all variables seperated by delimiter
	mov eax, A
	call WriteInt
	call WriteString

	mov eax, B
	call WriteInt
	call WriteString

	mov eax, C_
	call WriteInt
	call WriteString

	mov eax, D
	call WriteInt

	call Crlf
	call Crlf

	mov eax, A					;calculate value of Z
	sub eax, B
	mov ebx, C_
	sub ebx, D
	mov C_, ebx
	add eax, C_
	mov Z, eax
	
	call WriteBin				;display Z in binary, decimal, hex
	call Crlf
	call WriteInt
	call Crlf
	call WriteHex
	call Crlf	

	exit
main endp
end main