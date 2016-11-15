TITLE Composite Calculator     (Assignment4.asm)

; Author: Pedro Torres Picon (torrespp@oregonstate.edu)
; Course / Project ID: CS271-400 / Programming Assignment 4
; Due Date: 11/07/2016
; Description: A program that takes an integer from the user
; between 1 and 400 and prints that many compsite numbers

INCLUDE Irvine32.inc

; constant definitions

LOWER_LIMIT equ 1
UPPER_LIMIT equ 400

.data

; global variable definitions
intro_1 BYTE "Hi, my name is Pedro Torres Picon", 0
intro_2 BYTE "This program is called Composite Calculator", 0
ec_1 BYTE "EXTRA CREDIT: The output columns are aligned", 0
prompt_1 BYTE "What is your name? ", 0
greeting_1 BYTE "Hey ", 0
greeting_2 BYTE ", nice to meet you.", 0
instructions_1 BYTE "Enter the number of composite numbers you'd like to see", 0
prompt_2 BYTE "Please enter a number between 1 and 400 (inclusive)", 0
result_1 BYTE "OK, here's the magic:", 0
error_1	 BYTE "Whoops! The number must be between 1 and 400 (inclusive). Please try again.", 0
good_bye BYTE "That's all for now. Until next time! Good bye ", 0

space BYTE " ", 0

user_name BYTE 30 DUP(?) ; the user's name
num_composites DWORD ? ; a variable to store the number enter by the user
divisor DWORD 10

.code
main PROC
		call intro
		call getData
		call showComposites
		call farewell

		exit	; exit to operating system
main ENDP

;---------------------------------------------------------
  ; intro
  ;
  ; Displays introductory message, greets the user, gives
	; instructions to use the program
  ; Receives: none
  ; Returns:  user's name in global var user_name
	; Preconditions: none
	; Registers changed: edx, ecx
;---------------------------------------------------------

intro PROC
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

		; instructions
		mov		edx, OFFSET instructions_1
		call	WriteString
		call	CrLf
		ret
intro ENDP

;---------------------------------------------------------
  ; getData
  ;
  ; Get the number of composites from the user and validate
	; that it is between 1 and 400 inclusive
  ; Receives: none
  ; Returns:  user entered number in global var num_composites
	; Preconditions: none
	; Registers changed: edx, eax
;---------------------------------------------------------

getData PROC
	; get the number of composites from user
	getNumber:
		mov		edx, OFFSET prompt_2
		call	WriteString
		call	ReadDec

		call validate
		cmp 	ebx, 0
		jle		getNumber

		mov		num_composites, eax
		ret
getData ENDP

;---------------------------------------------------------
  ; validate
  ;
  ; Validate that a number in eax is within a range
  ; Receives: the number in eax
  ; Returns:  1 if valid, 0 if invalid in ebx
	; Preconditions: none
	; Registers changed: eax, edx, ebx
;---------------------------------------------------------

validate PROC
		; jump to invalid if number is smaller than 1
		cmp		eax, LOWER_LIMIT
		jl		invalid

		; jump to valid if number is 400 or smaller
		cmp		eax, UPPER_LIMIT
		jle		valid

	invalid:
		; error, store 0 in ebx
		mov		edx, OFFSET error_1
		call	WriteString
		call	CrLf
		mov 	ebx, 0
		jmp		endValidate

	valid:
		; number is valid, store 1 in ebx
		mov 	ebx, 1

	endValidate:
		ret
validate ENDP

;---------------------------------------------------------
  ; showComposites
  ;
  ; Show as many composite numbers as the user entered
  ; Receives: the number of composites in num_composites
  ; Returns:  none
	; Preconditions: none
	; Registers changed: eax, ebx, ecx, edx
;---------------------------------------------------------

showComposites PROC

		mov		edx, OFFSET result_1
		call	WriteString
		call	CrLf

		mov 	ecx, num_composites
		mov 	eax, 1

	compLoop:
		inc 	eax
		call 	isComposite
		cmp 	ebx, 0

		; if not composite go back up to the loop without decreasing ecx or calling WriteDec
		jle		compLoop

		; if composite print the number with proper formatting
		call 	WriteDec
		; and add corresponding amount of spaces to align columns (EXTRA CREDIT)
		mov		edx, OFFSET space
		cmp 	eax, 100 ; if the number has three digits
		jge		addSpaces ; jump to adding just 3 spaces
		call 	WriteString ; if not, add an extra space
		cmp		eax, 10 ; if the number has two or more digits
		jge 	addSpaces ; jump to adding just 3 spaces
		call 	WriteString ; if not, add an extra space

	addSpaces:
		push 	ecx ; save ecx to start inner loop
		mov 	ecx, 3
	spacesLoop:
		call	WriteString
		loop	spacesLoop
		pop 	ecx ; restore ecx and continue outer loop

		; check the current number of printed items to insert line break
		mov 	ebx, eax ; store eax to do division
		mov 	eax, num_composites
		sub		eax, ecx ; place the current number of printed items in eax
		cmp		eax, 0
		je		restoreEAX ; do not insert line break if this is the first iteration in the loop
		inc		eax
		sub		edx, edx ; clean edx for division
		div		divisor
		cmp 	edx, 0
		jne		restoreEAX ; if the current number of printed items is not divisible by 10, skip adding the space
		call 	CrLf
	restoreEAX:
		mov		eax, ebx ; restore eax to continue the loop
		loop 	compLoop
		ret
showComposites ENDP

;---------------------------------------------------------
  ; isComposite
  ;
  ; Validate that a number in eax is a composite number by
	; dividing it by the numbers between 2 and its square
	; root and finding a division with a remainder of 0
  ; Receives: the number in eax
  ; Returns:  1 if valid, 0 if invalid in ebx
	; Preconditions: none
	; Registers changed: eax, ebx, edx
;---------------------------------------------------------

isComposite PROC ; check if eax is not prime
		push 	eax
		push 	ecx
		mov 	ecx, eax
		mov 	ebx, 2 ; start checking if 2 divides the number
		keepChecking:
		mov 	eax, ebx
		mul 	ebx
		cmp		eax, ecx ; if the current divisor squared is larger than the number, stop
		jg 		notComposite
		mov 	eax, ecx
		div 	ebx
		cmp		edx, 0 ; if one of the numbers in the range 2 - sqrt(num) divides the number, stop
		je		yesComposite
		inc 	ebx
		jmp		keepChecking
		notComposite:
		mov 	ebx, 0 ; if not composite, set ebx to 0
		jmp 	restoreRegs
		yesComposite:
		mov 	ebx, 1 ; if composite, set ebx to 1
		restoreRegs:
		pop 	ecx
		pop 	eax
		ret
isComposite ENDP

;---------------------------------------------------------
  ; farewell
  ;
  ; Displays a message to say good bye to the user
  ; Receives: none
  ; Returns:  none
	; Preconditions: user's name stored in user_name
	; Registers changed: edx
;---------------------------------------------------------

farewell PROC
	call	CrLf
	mov		edx, OFFSET good_bye
	call	WriteString
	mov		edx, OFFSET user_name
	call	WriteString
	call	CrLf
	ret
farewell ENDP

END main
