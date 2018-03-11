; Author: Samar El-Houssami
; Date: 02/16/18

INCLUDE Irvine32.inc

.data
space BYTE " ",0
prompt1 BYTE "What is the size N of Vector? ",0
prompt2 BYTE "Size must be positive or zero",0
prompt3_1 BYTE "What are the ",0
prompt3_2 BYTE " values in Vector? ",0
prompt4 BYTE "Size of Vector is N = ",0
prompt5 BYTE "Vector = ",0
prompt7 BYTE "The sum of all the negative values in Vector is: Sum = ",0
prompt8 BYTE "The number of all the positive values in Vector is: Count = ",0
prompt9 BYTE "Please give me two values I and J such that 1 <= I <= J <= N > : ",0
prompt10 BYTE "I = ", 0
prompt11 BYTE " and J = ", 0
prompt12 BYTE " and ",0
prompt13 BYTE "The minimum value between position ", 0
prompt14 BYTE " of Vector is: Minimum = ",0
prompt15 BYTE "Invalid I or J",0
prompt16 BYTE "Vector is a palindrome because it reads the same way in both directions.",0
prompt17 BYTE "Vector is not a palindrome because it does not read the same way in both directions.",0
prompt18 BYTE "Repeat with a new Vector of different size and/or content? (Y/N): ",0

N SDWORD ?
Vector SDWORD 50 DUP(?)
Palindrome SDWORD SIZEOF Vector DUP (0)
posCount DWORD ?
I DWORD ?
J DWORD ?
MIN SDWORD ?
No BYTE "N",0

.code
main PROC
		
	Top:
		while_L:
			mov edx, OFFSET prompt1				; "What is the size N of Vector"
			call WriteString
			call ReadInt
			cmp eax, 0							
			jl Input_error
			jmp ReadInput

	Input_error:								; if size N is negative, write error message
		mov edx, OFFSET prompt2
		call WriteString
		jmp while_L

	ReadInput:
		mov N, eax								;"What are the N values in Vector?"
		mov ecx, N
		mov edx, OFFSET prompt3_1							
		call WriteString
		mov eax, N
		call WriteDec
		mov eax, 0
		mov edx, OFFSET prompt3_2
		call WriteString

		mov edi, OFFSET Vector

	L1:										;read inputs into Vector
		call ReadInt				
		mov [edi], eax
		add edi, TYPE Vector
		loop L1

	mov edx, OFFSET prompt4					;"Size of Vector is N = "
	call WriteString
	mov eax, N
	call WriteDec
	call Crlf
	
	mov edi, OFFSET Vector				

	mov edx, OFFSET prompt5					;Vector = 
	call WriteString
	mov ecx, N

	L2:										;prints Vector inputs
		mov edx, OFFSET space
		mov eax, [edi]						
		add edi, TYPE Vector
		call WriteInt
		call WriteString
		loop L2
	
	call Crlf
		
	mov edi, OFFSET Vector					; EDI = address of array
	mov ecx, N								; ECX = N = loop counter
	mov eax, 0								; EAX = sum of neg numbers
	mov ebx, 0								; EBX = # of positive numbers
	
	L3:										; loop counts sum of neg numbers and # of positive numbers in Vector
		mov edx, [edi]
		cmp edx, 0

		JNL _else							;if num is positive
		add  eax, [edi]						;if num is negative
		JMP end_if

	_else:
		inc ebx

	end_if:
		add edi,TYPE Vector      			; point to next element
		loop L3								; repeat until ECX = 0

	mov edx, OFFSET prompt7					; "The sum of all the negative values in Vector is: Sum = "
	call WriteString
	call WriteInt
	call Crlf
	mov posCount, ebx
	mov eax, posCount
	mov edx, OFFSET prompt8					;"The number of all the positive values in Vector is: Count = "
	call WriteString
	call WriteInt
	call Crlf
		
											;reads and validate I and J inputs
	IandJ:
		call crlf

		mov edx, OFFSET prompt9				;Enter I and J
		call WriteString
		call ReadDec
		mov I, eax
		call ReadDec
		mov J, eax

											;check validity
		mov ebx, 1
		cmp ebx, I				;Is 1 > I
		ja quitIJ

		mov ebx, 1
		cmp ebx, J				;Is 1 > J
		ja quitIJ

		mov ebx, 1
		cmp ebx, N				;Is 1 > N
		ja quitIJ

		mov ebx, N
		cmp ebx, I				;Is N < I
		jb quitIJ

		mov ebx, N
		cmp ebx, J				;Is N < J
		jb quitIJ

		mov ebx, J
		cmp ebx, I				;Is J < I
		jb quitIJ

		jmp nextIJ
	
	quitIJ:
		mov edx, OFFSET prompt15		;Invalid I or J
		call WriteString
		jmp IandJ

	nextIJ:
		mov edx, OFFSET prompt10		;Display I and J
		call WriteString
		mov eax, I
		call WriteDec
		mov edx, OFFSET prompt11
		call WriteString
		mov eax, J
		call WriteDec
		mov edx, OFFSET prompt12
		call WriteString
		call crlf

		mov esi, OFFSET Vector
		mov ecx, I
		mov eax, 0
		mov ebx, TYPE Vector
	
	L7:									;find minimum between I and J
		add eax, ebx
		loop L7
		
	add esi, eax
	mov ecx, J
	sub ecx, I
	mov MIN, 0FFFFFFFh
	
	minimum:
		mov ebx, [esi]
		mov edx, ebx
		cmp ebx, MIN
		jge end_if2
		mov MIN, edx
	
		end_if2:
			add esi, TYPE Vector
			loop minimum

	mov edx, OFFSET prompt13						;print min
	call WriteString
	mov eax, I
	call WriteDec
	mov edx, OFFSET prompt12
	call WriteString
	mov eax, J
	call WriteDec
	mov edx, OFFSET prompt14
	call WriteString
	mov eax, MIN
	call WriteInt
	call crlf

		mov ecx, N									;find out if Vector is a Palindrome 
		mov edi, OFFSET Vector
		lea esi, [edi+ecx*4-4]
		inc ecx
		mov edi, OFFSET Palindrome
	
	L8:												;reverse Vector into Palindrome
		mov eax, [esi]
		mov [edi], eax
		sub esi, TYPE Vector
		add edi, TYPE Palindrome
		loop L8

	mov ecx, N
	mov esi, 0
	mov edx, 1
	inc ecx

	L9:
		mov eax, Vector[esi]
		mov ebx, Palindrome[esi]
		cmp eax, ebx
		je equal
		mov edx, 0
		mov ecx, 1

		equal: 
			inc esi
			loop L9

		cmp edx, 0
		je equals
		mov edx, OFFSET prompt16			;Vector IS a palindrome
		call WriteString
		jmp end_equals
	
	equals:
		mov edx, OFFSET prompt17			;Vector is NOT a palindrome
		call WriteString
	
	end_equals:
		call crlf
		call crlf

		mov edx, OFFSET prompt18			;Try again
		call WriteString
		call ReadChar
		call WriteChar
		call Crlf
		cmp No, al
		je finish
		jmp top
	
	finish:
		exit
main ENDP
END main