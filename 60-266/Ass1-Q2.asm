; Ass1-Q2.asm - reads hex number and displays it in reverse order
; Author: Samar El-Housami

INCLUDE Irvine32.inc

.data
	bigEndian BYTE ?,?,?,?
	littleEndian DWORD ?
	prompt BYTE "Enter a hex number: ",0

.code
main PROC

	mov edx, OFFSET prompt			;read littleEndian
	call WriteString
	call ReadHex
	mov littleEndian, eax

	mov ah, BYTE PTR littleEndian+0
	mov bh, BYTE PTR littleEndian+1
	mov ch, BYTE PTR littleEndian+2
	mov dh, BYTE PTR littleEndian+3

	mov bigEndian+0, dh
	mov bigEndian+1, ch
	mov bigEndian+2, bh
	mov bigEndian+3, ah

	mov eax, DWORD PTR bigEndian+0
	call WriteHex
	call Crlf
	exit

main ENDP
end main