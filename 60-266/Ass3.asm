; This program inputs multiple integers from the user into Vector
; and manipulates stacks

;Author: Samar El-Houssami

INCLUDE Irvine32.inc

.data
whatNow       BYTE "What do you want to do now? > ",0
whatSize      BYTE "What is the size N of Vector? > ",0  
whatVector1   BYTE "What are the ",0 
whatVector2   BYTE " values in Vector? > ",0
sizeVec       BYTE "Size of Vector is N = ",0
vecList       BYTE "Vector = ",0
vecIs		  BYTE "Vetor is ",0
stackIs		  BYTE "Stack is ",0
youThought1   BYTE "Error – Stack is empty: Cannot perform StackToArray",0Ah, 0Dh,0
youThought2   BYTE "Error – Vector is empty: Cannot perform ArrayToStack",0Ah, 0Dh,0
youThought3   BYTE "Error – Vector is empty: Cannot perform StackReverse",0Ah, 0Dh,0
stackEmpty    BYTE "stack is empty",0Ah,0Dh,0
stackNotEmpty BYTE "stack not empty",0Ah,0Dh,0
beforeStoA	  BYTE "before StackToArray",0Ah,0Dh,0
afterStoA	  BYTE "after StackToArray",0Ah,0Dh,0
beforeAtoS	  BYTE "before ArrayToStack",0Ah,0Dh,0
afterAtoS	  BYTE "after ArrayToStack",0Ah,0Dh,0
beforeSRev	  BYTE "before StackReverse",0Ah,0Dh,0
afterSRev	  BYTE "after StackReverse",0Ah,0Dh,0
getLost       BYTE "I am exiting… Thank you Honey… and Get lost…",0Ah,0Dh,0
tryAgain	  BYTE "Not valid. Try again",0
space		  BYTE " ",0

N				 DWORD ?
Vector			 DWORD 50 DUP(?)
isEmptyStack	 DWORD ?
isEmptyVec		 DWORD ?

.code
main PROC

mov isEmptyStack, 1						;start with empty stack
mov isEmptyVec, 1						;start with empty vector

Start:
	mov edx, OFFSET whatNow				;read menu selection
	call WriteString
	call ReadInt

	cmp eax, -1							;if input = -1, exit
	je Finish
	
	cmp eax, 0							;if input = 0, jump to ReadInput
	je ReadInput

	cmp eax, 1							;if input = 1, call ArrayToStack
	je aTos
	
	cmp eax, 2							;if input = 2, call StackToArray
	je sTOa
	
	cmp eax, 3							;if input = 3, call StackReverse
	je sRev

	jmp Invalid							;if input is none of the above, it's invalid
	
	ReadInput:							
		call Crlf
		mov edx, OFFSET whatSize		;prompt for Vector size
		call WriteString
		call ReadInt
		mov N, eax						;place size into N

		mov edx, OFFSET whatVector1		;prompt for Vector elements
		call WriteString
		call WriteInt
		mov edx, OFFSET whatVector2
		call WriteString

		mov ecx, N						;set loop = N
		mov esi, OFFSET Vector			;store Vector address into esi
		
		L1:								;read inputs into Vector
			call ReadInt				;read int
			mov [esi], eax				;place int into Vector[esi]
			add esi, TYPE Vector		;go to next cell in Vector
			loop L1
		
		mov eax, N

		call Crlf

		mov edx, OFFSET sizeVec			;display size of vector
		call WriteString
		call WriteInt
		call Crlf

		mov edx, OFFSET vecList
		call WriteString
		
		mov esi, OFFSET Vector			;reset esi to point to start of Vector
		mov ebx, N

		call DisplayArray				;display elements of Vector (esi = OFFSET Vector)
		call Crlf

		mov isEmptyStack, 1				;stack is empty
		mov isEmptyVec, 0				;vec is no longer empty
		mov edx, OFFSET stackEmpty
		call WriteString
		call Crlf
		jmp Start						;go back to menu

	aToS:
		call Crlf

		mov edx, isEmptyStack			;cannot perform array to stack if stack is not empty
		cmp edx, 0
		je Cannot2

		mov edx, isEmptyVec				;cnnot perform array to stack if array is empty
		cmp edx, 1
		je Cannot2

		mov edx, OFFSET vecIs			;"vector is "
		call WriteString
		mov esi, OFFSET Vector
		mov ebx, N

		call DisplayArray				;display vector elements
		
		mov edx, OFFSET beforeAtoS		;"before array to string"
		call WriteString

		mov esi, OFFSET Vector
		mov ebx, N

		call ArrayToStack				;push array to stack
		mov isEmptyStack, 0				;stack is not empty
		mov isEmptyVec, 1				;vec is empty

		mov edx, OFFSET stackIs			;"stack is "
		call WriteString

		mov esi, esp
		mov ebx, N

		call DisplayArray				;display elements of stack

		mov edx, OFFSET afterAtoS		;"after array to stack"
		call WriteString

		mov edx, OFFSET stackNotEmpty
		call WriteString
		call Crlf
		jmp Start						;go back to menu
	
	sTOa:
		call Crlf
		mov edx, isEmptyStack			;if stack is empty, cannot call StackToArray
		cmp edx, 1
		je Cannot1

		mov edx, OFFSET stackIs			
		call WriteString

		mov esi, esp
		mov ebx, N

		call DisplayArray				;display stack before calling StackToArray

		mov edx, OFFSET beforeStoA
		call WriteString

		mov edx, OFFSET vecIs
		call WriteString

		mov esi, OFFSET Vector
		mov ebx, N

		call StackToArray				;call StackToArray
		mov isEmptyStack, 1				;stack becomes empty
		mov isEmptyVec, 0				;vec is not empty
		call DisplayArray				;display vector

		mov edx, OFFSET afterStoA
		call WriteString

		mov edx, OFFSET stackEmpty
		call WriteString
		call Crlf
		jmp Start

	sRev:
		call Crlf
		mov edx, isEmptyStack			;cannot reverse vector if stack is not empty
		cmp edx, 0
		je Cannot3

		mov edx, isEmptyVec				;cannot reverse array if array is empty
		cmp edx, 1
		je Cannot3

		mov edx, OFFSET vecIs
		call WriteString

		mov esi, OFFSET Vector
		mov ebx, N

		call DisplayArray				;display contents of vector before reversing

		mov edx, OFFSET beforeSRev
		call WriteString

		mov esi, OFFSET Vector
		mov ebx, N

		mov edx, OFFSET stackNotEmpty
		call WriteString

		mov esi, OFFSET Vector
		mov ebx, N

		call StackReverse				;reverse elements of vector using stack
		mov isEmptyStack, 1				;stack becomes empty after reversing

		mov edx, OFFSET vecIs
		call WriteString

		mov esi, OFFSET Vector
		mov ebx, N

		call DisplayArray				;display contents of vector after reversing it

		mov edx, OFFSET afterSRev
		call WriteString

		mov edx, OFFSET stackEmpty
		call WriteString
		call Crlf
		jmp Start

	Cannot1:							;cannot perform stack to array if stack is empty
		mov edx, OFFSET youThought1
		call WriteString
		call Crlf
		jmp Start

	Cannot2:							;cannot perform array to stack if array is empty
		mov edx, OFFSET youThought2
		call WriteString
		call Crlf
		jmp Start

	Cannot3:							;cannot reverse vector if stack is full/vector is empty
		mov edx, OFFSET youThought3
		call WriteString
		call Crlf
		jmp Start

	Invalid:							;in case of invalid input try again
		mov edx, OFFSET tryAgain
		call WriteString
		call Crlf
		jmp Start

Finish:									;display leaving message and exit
	mov edx, OFFSET getLost
	call WriteString
	call Crlf
	exit

main ENDP

;-----------------------------------------------------
DisplayArray PROC
;
; Displays N elements of array
; Receives: ESI points to the array, EBX = array size
; Returns:  nothing
;-----------------------------------------------------

mov edx, OFFSET space
mov ecx, ebx				;set loop = size of array

L1:
	mov eax, [esi]
	call WriteDec			;print array element
	call WriteString		;print 2 spaces
	call WriteString
	add  esi,4				;go to next integer
	loop L1

	ret
DisplayArray ENDP


;-----------------------------------------------------
ArrayToStack PROC
;
; Copies N elements of array onto the runtime stack
; Receives: ESI points to the array, EBX = array size
; Returns:  ESP points to top of full stack
;-----------------------------------------------------

mov ecx, ebx			;set loop = size of array
mov edx, OFFSET space	
mov edx, [esp]			;save return address to edx

L1:						
	PUSH [esi]			;push array element into stack
	add esi, 4			;go to next element in array
	loop L1

PUSH edx				;push return address to top of array for ret

	ret
ArrayToStack ENDP

;-----------------------------------------------------
StackToArray PROC
;
; Copies N elements of stack onto array
; Receives: ESI points to the array, EBX = array size
; Returns:  ESP is restored
;-----------------------------------------------------

mov ecx, ebx			;set loop = size of array
mov edx, [esp]			;save return address to edx

L1:						;reach end of array
	add esi, 4
	loop L1

mov ecx, ebx
L2:						
	POP [esi]			;push array element into stack
	sub esi, 4			;go to next element in array
	loop L2

PUSH edx				;push return address to top of array for ret

	ret
StackToArray ENDP

;-----------------------------------------------------
StackReverse PROC
;
; Uses the stack to reverse elements in an array
; Receives: ESI points to the array, EBX = array size
; Returns:  nothing
;-----------------------------------------------------

mov ecx, ebx			;set loop = size of array
mov edx, [esp]			;save return address to ebx
mov eax, esi			;save pointer to beginning of vector

L1:						;push array into stack
	PUSH [esi]
	add esi, 4
	loop L1

mov esi, eax			;point back to beginning of vector
mov ecx, ebx			;set loop = size of array
L2:						
	POP [esi]			;push array element into stack
	add esi, 4			;go to next element in array
	loop L2

PUSH edx				;push return address to top of array for ret

	ret
StackReverse ENDP
END main
