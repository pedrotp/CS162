TITLE Fibonacci Generator     (Assignment2.asm)

; Author: Pedro Torres Picon (torrespp@oregonstate.edu)
; Course / Project ID: CS271-400 / Programming Assignment 2
; Due Date: 10/17/2016
; Description: This program generates a sequence of fibonacci numbers, according to the number of terms provided by the user

INCLUDE Irvine32.inc

; constant definitions

LOWER_LIMIT equ 1
UPPER_LIMIT equ 46

.data 

; variable definitions

intro_1 BYTE "Hi, my name is Pedro Torres Picon", 0
intro_2 BYTE "This program is called Fibonacci Generator", 0
ec_1 BYTE "EXTRA CREDIT: The numbers are displayed in aligned columns", 0
ec_2 BYTE "EXTRA CREDIT: The first extra credit was hard, and I think the solution I implemented was kind of amazing :)", 0
prompt_1 BYTE "What's your name? ", 0
greeting_1 BYTE "Hey ", 0
greeting_2 BYTE ", nice to meet you.", 0
instructions_1 BYTE "Give me a number, and I will display a sequence of fibonacci numbers", 0
instructions_2 BYTE "Unfortunately, I cannot display more than 46 numbers, so choose a number between 1 and 46", 0
prompt_2 BYTE "How many fibonacci terms do you want to see? ", 0
result_1 BYTE "OK, here's the magic:", 0
error_1	 BYTE "Whoops! The number must be between 1 and 46. Please try again.", 0
good_bye BYTE "That's all for now. Until next time! Good bye ", 0

space BYTE " ", 0

user_name BYTE 30 DUP(?) ; the user's name
num_sequence DWORD ? ; the number of elements in the fibonacci sequence
res_per_line DWORD 5 ; the number of results to be printed per line
loop_counter DWORD 0 ; counter to keep track of how many iterations have happened
multiplier DWORD 10 ; multiplier to check how many spaces to put in front of a digit (EXTRA CREDIT)
prevFib DWORD 0 ; variable to store the previous number when calculating the sequence
tempStore DWORD ? ; temp variable to store values in both inner loops below

.code
main PROC

; introduction

	mov		al, 011011b
	test	al, 2

	mov		edx, OFFSET intro_1
	call	WriteString
	call	CrLf

	mov		edx, OFFSET intro_2
	call	WriteString
	call	CrLf	

	mov		edx, OFFSET ec_1
	call	WriteString
	call	CrLf	

	mov		edx, OFFSET ec_2
	call	WriteString
	call	CrLf	

	mov		edx, OFFSET prompt_1
	call	WriteString
	mov		edx, OFFSET user_name
	mov		ecx, SIZEOF user_name
	call	ReadString	

	mov		edx, OFFSET greeting_1
	call	WriteString
	mov		edx, OFFSET user_name
	call	WriteString
	mov		edx, OFFSET greeting_2
	call	WriteString
	call	CrLf	

; userInstructions

	mov		edx, OFFSET instructions_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instructions_2
	call	WriteString
	call	CrLf

; getUserData

	; get the number of steps from user

	getNumber:
	mov		edx, OFFSET prompt_2
	call	WriteString
	call	ReadDec
	mov		num_sequence, eax

	; jump to error if number is smaller than 1

	cmp		eax, LOWER_LIMIT
	jl		outOfBounds

	; jump to displayFibs if number is 46 or smaller

	cmp		eax, UPPER_LIMIT
	jle		displayFibs

	; error, jump back to enter the number again

outOfBounds:
	mov		edx, OFFSET error_1
	call	WriteString
	call	CrLf
	jmp		getNumber

; displayFibs

displayFibs: 
	mov		eax, 1
	mov		ecx, num_sequence

fibLoop:
	; write the current number to the screen
	call	WriteDec

	; store the values of eax and ecx while the inner loop runs
	mov		ebx, eax 
	mov		tempStore, ecx 

	; add the corresponding number of spaces for extra credit
	mov		ecx, 9
	mov		eax, 1

	digitsLoop:
		mul		multiplier
		cmp		ebx, eax
		jge		noSpace
		mov		edx, OFFSET space
		call	WriteString
		noSpace:
		loop	digitsLoop

	; restore eax and ecx to continue outer loop
	mov		eax, ebx
	mov		ecx, tempStore

	; update current number (eax) and previous number(prevFib)
	add		eax, prevFib
	mov		prevFib, ebx ; load previous value of eax into prevFib

	; add a new line every fifth iteration of the loop 
	inc		loop_counter
	mov		tempStore, eax
	mov		eax, loop_counter
	sub		edx, edx
	div		res_per_line
	mov		eax, tempStore
	cmp		edx, 0
	jne		loopEnd
	call	CrLf 
loopEnd:
	loop	fibLoop

; farewell

	call	CrLf
	mov		edx, OFFSET good_bye
	call	WriteString
	mov		edx, OFFSET user_name
	call	WriteString
	call	CrLf

	exit	; exit to operating system
main ENDP

END main
