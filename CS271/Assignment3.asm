TITLE Negative Accumulator     (Assignment3.asm)

; Author: Pedro Torres Picon (torrespp@oregonstate.edu)
; Course / Project ID: CS271-400 / Programming Assignment 3
; Due Date: 10/31/2016
; Description: The program asks the user to enter a series of negative numbers and returns their average

INCLUDE Irvine32.inc

; constant definitions

LOWER_LIMIT equ -100

.data

; variable definitions

intro_1 BYTE "Hi, my name is Pedro Torres Picon", 0
intro_2 BYTE "This program is called Negative Accumulator", 0
ec_1 BYTE "EXTRA CREDIT: The lines are numbered during user input", 0
prompt_1 BYTE "What is your name? ", 0
greeting_1 BYTE "Hey ", 0
greeting_2 BYTE ", nice to meet you.", 0
instructions_1 BYTE "Enter as many negative numbers as you want, and I will give you their average", 0
instructions_2 BYTE "When you are done entering negative numbers, enter a non-negative number to continue", 0
prompt_2 BYTE "Please enter a number between -1 and -100 (inclusive)", 0
result_1 BYTE "OK, here's the magic:", 0
result_2 BYTE "You entered ", 0
result_3 BYTE " numbers between -100 and -1", 0
result_4 BYTE "The sum of those numbers is ", 0
result_5 BYTE "And their rounded average is ", 0
error_1	 BYTE "Whoops! The number must be equal or larger to -100. Please try again.", 0
error_2	 BYTE "Hm, looks like you forgot to enter any negative numbers. Maybe next time!", 0
good_bye BYTE "That's all for now. Until next time! Good bye ", 0
space BYTE ": ", 0

user_name BYTE 30 DUP(?) ; the user's name
loop_counter DWORD 0 ; counter to keep track of how many iterations have happened
negative_sum SDWORD 0 ; to store the sum of the negative numbers

.code
main PROC

; introduction

	mov		edx, OFFSET intro_1
	call	WriteString
	call	CrLf

	mov		edx, OFFSET intro_2
	call	WriteString
	call	CrLf

	mov		edx, OFFSET ec_1
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

	; get the negative numbers from the user
	getNumber:
	mov		edx, OFFSET prompt_2
	call	WriteString
	call	CrLf
	mov		eax, loop_counter
	add		eax, 1
	call	WriteDec
	mov		edx, OFFSET space
	call	WriteString
	call	ReadInt

	; if 0 or positive, jump to calculate sum
	cmp		eax, 0
	jge		showResults

	; if smaller than -100, show error and loop back
	cmp		eax, LOWER_LIMIT
	jge		addNumber
	mov		edx, OFFSET error_1
	call	WriteString
	call	CrLf
	jmp		getNumber

	; otherwise, add to accumulator and loop back
	addNumber:
	add		negative_sum, eax
	inc		loop_counter
	jmp		getNumber

	showResults:
	; if the counter is equal to 0, no negative numbers were entered so skip the results
	cmp		loop_counter, 0
	je		noNegatives

	mov		edx, OFFSET result_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET result_2
	call	WriteString
	mov		eax, loop_counter
	call	WriteDec
	mov		edx, OFFSET result_3
	call	WriteString
	call	CrLf
	mov		edx, OFFSET result_4
	call	WriteString
	mov		eax, negative_sum
	call	WriteInt
	call	CrLf

	; calculate the average
	sub		edx, edx ; clear edx
	cdq
	idiv 	loop_counter

	mov		edx, OFFSET result_5
	call	WriteString
	call	WriteInt
	call	CrLf
	jmp		farewell

	; if no negative numbers were entered, show an error message
	noNegatives:
	call	CrLf
	mov		edx, OFFSET error_2
	call	WriteString
	call	CrLf

; farewell

	farewell:
	call	CrLf
	mov		edx, OFFSET good_bye
	call	WriteString
	mov		edx, OFFSET user_name
	call	WriteString
	call	CrLf

	exit	; exit to operating system

main ENDP

END main
