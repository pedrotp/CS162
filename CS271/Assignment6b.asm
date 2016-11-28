TITLE Combinations Quizzer     (Assignment6b.asm)

; Author: Pedro Torres Picon (torrespp@oregonstate.edu)
; Course / Project ID: CS271-400 / Programming Assignment #6b
; Due Date: 12/05/2016
; Description: A system for drill and practice in combinatorics. In particular,
; the system will ask the user to calculate the number of combinations of r
; items taken from a set of n items. The system generates random problems with
; n in [3..12] and r in [1..n]. The user enters an answer, the system reports
; the correct answer and an evaluation of the user's answer. The system repeats
; until the user chooses to quit.

INCLUDE Irvine32.inc

; constant definitions

input_size equ 10

printString MACRO buffer

	push 	edx
	mov 	edx, OFFSET buffer
	call 	WriteString
	pop 	edx

ENDM

printDec MACRO integer

	push 	eax
	mov 	eax, integer
	call 	WriteDec
	pop 	eax

ENDM

.data

; global variable definitions
intro_1 BYTE "Hi, my name is Pedro Torres Picon", 0
intro_2 BYTE "This program is called Combinations Quizzer", 0
ec_1 BYTE "**EXTRA CREDIT: Each problem is numbered, score is kept", 0
instructions BYTE "I will ask you to calculate the number of combinations of r items taken from a set of n items. You give me your best guess, and I'll let you know if you're right.", 0
title_1 BYTE "Problem ", 0
title_2 BYTE ": ", 0
prompt_1 BYTE "How many combinations of ", 0
prompt_2 BYTE " items, taken from a set of ", 0
prompt_3 BYTE " items, are there?", 0
correct BYTE "CORRECT! You genius, you.", 0
incorrect BYTE "Sorry, that is incorrect. Sad face.", 0
result_1 BYTE "There are ", 0
result_2 BYTE " combinations of ", 0
result_3 BYTE " items in a set of ", 0
error_1	BYTE "Whoops! Input must be an unsigned positive integer. Please try again.", 0
error_2 BYTE "Hm, looks like you entered an empty string. Please try again.", 0
prompt_again BYTE "Would you like another problem? (y/n) ", 0
error_3 BYTE "Uh oh, I don't know what that means. Please respond with y or n.", 0
score_1 BYTE "************ FINAL SCORE ************", 0
score_2 BYTE "  RIGHT ANSWERS: ", 0
score_3 BYTE "  WRONG ANSWERS: ", 0
score_4 BYTE "*************************************", 0
good_bye BYTE "That's all for now. Until next time! Good bye", 0

problem_num DWORD 0
set_min DWORD 3
set_max DWORD 13
set_size DWORD ? ; n
subset_size DWORD ? ; r
input BYTE input_size DUP(?) ; the user's raw string input
answer DWORD ? ; the user's answer
result DWORD ? ; the actual result
num_right DWORD 0
num_wrong DWORD 0
play_again DWORD 1

.code

;---------------------------------------------------------

  ; main

  ; Uses all other procedures to run the entire program
  ; Receives: none
  ; Returns: none
  ; Preconditions: none
  ; Registers changed: none

;---------------------------------------------------------

main PROC

	call	Randomize ; seed for random numbers
	call	intro

quizLoop:
	push	set_max
	push	set_min
	push	OFFSET problem_num
	push	OFFSET set_size
	push	OFFSET subset_size
	call	showProblem

	push	OFFSET answer
	push	input_size
	push	OFFSET input
	call	getData

	push	OFFSET result
	push	set_size
	push	subset_size
	call	combinations

	push 	OFFSET input
	push	OFFSET play_again
	push 	OFFSET num_right
	push 	OFFSET num_wrong
	push 	set_size
	push	subset_size
	push 	result
	push	answer
	call	showResults

	cmp		play_again, 0
	jne		quizLoop

	push	num_right
	push	num_wrong
	call	farewell
	exit	; exit to operating system

main ENDP

;---------------------------------------------------------

  ; intro

  ; Displays introductory message, greets the user, gives
  ; instructions to use the program
  ; Receives: none
  ; Returns: none
  ; Preconditions: none
  ; Registers changed: edx

;---------------------------------------------------------

intro PROC

	printString intro_1
	call	CrLf

	printString intro_2
	call	CrLf

	printString ec_1
	call	CrLf
	call	CrLf

	printString instructions
	call	CrLf
	call 	CrLf

ret

intro ENDP

;---------------------------------------------------------

  ; showProblem

  ; Generates two random numbers, displays a new problem
  ; to the user
  ; Receives: addresses of set_size and subset_size
  ; Returns: two random numbers stored in received variables
  ; Preconditions: Randomize has been called
  ; Registers changed: ebp, eax, edx

;---------------------------------------------------------

showProblem PROC

	push	ebp
	mov		ebp, esp
	pushad

	mov		eax, [ebp+24]
	sub		eax, [ebp+20]
	call	RandomRange
	add		eax, [ebp+20]
	mov		edi, [ebp+12]
	mov		[edi], eax ; set size

	call	RandomRange
	inc		eax
	mov		edi, [ebp+8]
	mov		[edi], eax ; subset size

	printString title_1
	mov		esi, [ebp+16]
	mov		eax, [esi]
	inc		eax
	call	WriteDec
	mov		[esi], eax
	printString title_2
	call 	CrLf

	printString prompt_1
	mov		esi, [ebp+8]
	mov		eax, [esi]
	call	WriteDec
	printString prompt_2
	mov		esi, [ebp+12]
	mov		eax, [esi]
	call	WriteDec
	printString prompt_3
	call 	CrLf

	popad
	pop		ebp

	ret		20

showProblem ENDP

;---------------------------------------------------------

  ; getData

  ; Gets the user's answer from standard input
  ; Receives: offset of the result variable
  ; Returns:  validated input in the result variable
  ; Preconditions:
  ; Registers changed:

;---------------------------------------------------------

getData PROC

	push	ebp
	mov		ebp, esp
	pushad

getInput:
	mov		edx, [ebp+8]
	mov		ecx, [ebp+12]
	call	ReadString
	cmp		eax, 0
	je		emptyString ; if the string is empty, show an error

	mov		ecx, eax
	mov		esi, [ebp+8]

	push	ecx ; save input size before loop
	cld
checkDigits:
	sub		eax, eax ; clean up eax
	lodsb
	cmp		al, 48
	jb		notDigits
	cmp		al, 57
	ja		notDigits
	loop	checkDigits ; check if all items are digits

	pop		ecx
	mov		esi, [ebp+8]
	mov		edi, [ebp+16]
	mov		edx, 0
	mov		[edi], edx
	cld
parseNum:
	sub		eax, eax ; clean up eax
	lodsb
	sub		al, 48
	mov		ebx, eax
	mov		eax, [edi]
	mov		edx, 10
	mul		edx
	add		eax, ebx
	mov		[edi], eax
	loop	parseNum ; parse the number
	jmp		allDone

notDigits:
	pop		ecx
	printString error_1
	call	CrLf
	jmp		getInput

emptyString:
	printString error_2
	call 	CrLf
	jmp		getInput

allDone:
	popad
	pop		ebp

	ret		12

getData ENDP

;---------------------------------------------------------

  ; combinations

  ; calculates the number of combinations of a certain
	; subset size in a set of a give size
  ; Receives: set_size and subset_size by value, and
	; result by reference
  ; Returns:  the number of combinations in result
  ; Preconditions: subset_size < set_size
  ; Registers changed: ebp, esp, eax, esi, edi, ebx

;---------------------------------------------------------

combinations PROC

	push 		ebp
	mov 		ebp, esp
	sub 		esp, 12
	pushad

	mov			ebx, [ebp+8] ; r in ebx
	mov			eax, [ebp+12] ; n in eax

	mov			edi, ebp
	sub			edi, 4
	push		edi
	push		eax
	call		factorial ; n! in ebp-4

	mov			edi, ebp
	sub			edi, 8
	push		edi
	push		ebx
	call		factorial ; r! in ebp-8

	mov			edi, ebp
	sub			edi, 12
	push		edi
	sub			eax, ebx
	push		eax
	call		factorial ; (n-r)! in ebp-12

	mov			eax, [ebp-8]
	mov 		ebx, [ebp-12]
	mul 		ebx
	mov 		ecx, eax ; r!(n-r)! in ecx

	mov 		eax, [ebp-4]
	div			ecx
	mov			esi, [ebp+16]
	mov			[esi], eax ; store the result

	popad
	mov			esp, ebp
	pop 		ebp

	ret			12

combinations ENDP

;---------------------------------------------------------

  ; factorial

  ; calculates the factorial for a given number
  ; Receives: a number and a memory location
  ; Returns:  the factorial in the memory location
  ; Preconditions: number is a positive integer
  ; Registers changed: ebp, esp, eax, esi, edi, ebx

;---------------------------------------------------------

factorial PROC

	push 		ebp
	mov 		ebp, esp
	sub 		esp, 4
	pushad

	mov			eax, [ebp+8]
	mov			esi, [ebp+12]
	cmp 		eax, 1
	jbe 		oneOrBelow

	dec			eax
	mov			edi, ebp
	sub			edi, 4
	push 		edi
	push 		eax
	call 		factorial
	inc			eax
	mov			ebx, [ebp-4]
	mul			ebx
	mov			DWORD PTR [esi], eax
	jmp			endFactorial

oneOrBelow:
	mov			DWORD PTR [esi], 1

endFactorial:
	popad
	mov			esp, ebp
	pop 		ebp

	ret			8

factorial ENDP

;---------------------------------------------------------

  ; showResults

  ; Checks whether user was right or wrong, displays results,
  ; updates the score and asks the user whether they want to
	; play again or not
  ; Receives: answer, result, set_size and subset_size by
	; value. num_right, num_wrong, input and play_again by ref.
  ; Returns: 1 or 0 in play_again
  ; Preconditions: all inputs are valid
  ; Registers changed: ebp, eax, ebx, esi, ecx, edx

;---------------------------------------------------------

; push 	OFFSET input +36
; push	OFFSET play_again +32
; push 	OFFSET num_right +28
; push 	OFFSET num_wrong +24
; push 	set_size +20
; push	subset_size +16
; push 	result +12
; push	answer +8
; call	showResults

showResults PROC

	push	ebp
	mov		ebp, esp
	pushad

	call	CrLf
	mov 	eax, [ebp+8] ; answer in eax
	mov 	ebx, [ebp+12] ; result in ebx
	cmp		eax, ebx
	jne		incorrectAns

	printString correct
	call	CrLf
	mov		esi, [ebp+28]
	mov		ecx, [esi]
	inc		ecx
	mov		[esi], ecx ; increase and update num_right
	jmp		printResult

incorrectAns:
	printString incorrect
	call	CrLf
	mov		esi, [ebp+24]
	mov		ecx, [esi]
	inc		ecx
	mov		[esi], ecx ; increase and update num_wrong

printResult:
	printString result_1
	printDec 	ebx
	printString result_2
	printDec 	[ebp+16]
	printString	result_3
	printDec	[ebp+20]
	call	CrLf
	call 	CrLf

promptLoop:
	printString prompt_again
	mov		edx, [ebp+36] ; offset of the input buffer
	mov		ecx, 5
	call	ReadString
	call	CrLf
	cmp		eax, 1
	jne		inputError ; error if the users inputs more than 1 character

	mov 	esi, edx
	sub		eax, eax ; clean up eax
	lodsb
	cmp		al, 121
	je		endResults
	cmp		al, 89
	je		endResults
	cmp		al, 110
	je 		inputN
	cmp		al, 78
	je 		inputN

inputError:
	printString error_3
	call	CrLf
	jmp 	promptLoop

inputN:
	mov		esi, [ebp+32]
	mov		[esi], DWORD PTR 0

endResults:
	popad
	pop		ebp

	ret		32

showResults ENDP

;---------------------------------------------------------

  ; farewell

  ; Displays a message to say good bye to the user
  ; Receives: num_wrong and num_right by value
  ; Returns:  none
  ; Preconditions: none
  ; Registers changed: edx, eax

;---------------------------------------------------------

farewell PROC

	push	ebp
	mov		ebp, esp

	printString score_1
	call	CrLf
	printString score_2
	printDec [ebp+12]
	call	CrLf
	printString score_3
	printDec [ebp+8]
	call	CrLf
	printString score_4
	call	CrLf
	call	CrLf

	printString good_bye
	call	CrLf

	pop		ebp

	ret		8

farewell ENDP

END main
