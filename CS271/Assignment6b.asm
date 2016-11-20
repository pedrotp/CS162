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

input_size equ 30

.data

; global variable definitions
intro_1 BYTE "Hi, my name is Pedro Torres Picon", 0
intro_2 BYTE "This program is called Combinations Quizzer", 0
ec_1 BYTE "**EXTRA CREDIT: Each problem is numbered, score is kept", 0
ec_2 BYTE "**EXTRA CREDIT: Factorials are computed in the floating point unit", 0

instructions_1 BYTE "I will ask you to calculate the number of combinations of r items taken from a set of n items. You give me your best guess, and I'll let you know if you're right.", 0
title_1 BYTE "Problem ", 0
title_2 BYTE ": ", 0
prompt_1 BYTE "How many combinations of ", 0
prompt_2 BYTE " items, taken from a set of ", 0
prompt_3 BYTE " items, are there?", 0
correct BYTE "CORRECT! You genius, you.", 0
incorrect BYTE "Sorry, that is incorrect. Sad face."
result_1 BYTE "There are ", 0
result_2 BYTE " combinations of ", 0
result_3 BYTE " items in a set of ", 0
error_1	 BYTE "Whoops! Input must be a positive integer. Please try again.", 0
prompt_4 BYTE "Would you like another problem? (y/n)", 0
error_2 BYTE "Uh oh, I don't know what that means", 0
score_1 BYTE "************ FINAL SCORE ************", 0
score_2 BYTE "  RIGHT ANSWERS: ", 0
score_3 BYTE "  WRONG ANSWERS: ", 0
score_4 BYTE "*************************************", 0
good_bye BYTE "That's all for now. Until next time! Good bye", 0

space BYTE " ", 0

set_size DWORD ? ; n
subset_size DWORD ? ; r
input BYTE input_size DUP(?) ; the user's raw string input
answer DWORD ? ; the user's answer
result DWORD ? ; the actual result

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

		call Randomize

		call intro

		push OFFSET request
		call getData

		push OFFSET array
		push request
		call fillArray

		push OFFSET unsorted_title
		push OFFSET array
		push request
		call printArray

		push OFFSET array
		push request
		call sortArray

		push OFFSET array
		push request
		call printMedian

		push OFFSET sorted_title
		push OFFSET array
		push request
		call printArray

		call farewell

		exit	; exit to operating system

main ENDP

;---------------------------------------------------------

  ; intro

  ; Displays introductory message, greets the user, gives
  ; instructions to use the program
  ; Receives: offset of 'user_name' variable
  ; Returns: user's name in 'user_name' variable
  ; Preconditions: none
  ; Registers changed: edx, ecx, eax

;---------------------------------------------------------

intro PROC

		push	ebp
		mov		ebp, esp
		pushad

		mov		edx, OFFSET intro_1
		call	WriteString
		call	CrLf

		mov		edx, OFFSET intro_2
		call	WriteString
		call	CrLf

		mov		edx, OFFSET ec_1
		call	WriteString
		call	CrLf
		call	CrLf

		mov		edx, OFFSET prompt_1
		call	WriteString
		mov		edx, [ebp+8]
		mov		ecx, name_size
		call	ReadString

		mov		edx, OFFSET greeting_1
		call	WriteString
		mov		edx, [ebp+8]
		call	WriteString
		mov		edx, OFFSET greeting_2
		call	WriteString
		call	CrLf
		call	CrLf

		; instructions
		mov		edx, OFFSET instructions_1
		call	WriteString
		call	CrLf

		popad
		pop 	ebp

		ret		4

intro ENDP

;---------------------------------------------------------

  ; getData

  ; Get the request from the user and validate that is is
  ; between 10 and 200 inclusive
  ; Receives: offset of 'request' variable
  ; Returns:  user entered number in 'request' variable
  ; Preconditions: none
  ; Registers changed: edx, ecx, eax, ebx, ebp

;---------------------------------------------------------

getData PROC

	; get the number of composites from user
		push 	ebp
		mov 	ebp, esp
		pushad
		mov 	ecx, [ebp+8]
	getNumber:
		mov		edx, OFFSET prompt_2
		call	WriteString
		call	ReadDec

		push 	eax
		call	validate
		cmp 	ebx, 0
		jle		getNumber

		mov		[ecx], eax

		call	CrLf
		mov		edx, OFFSET result_1
		call	WriteString
		call	CrLf

		popad
		pop 	ebp

		ret		4

getData ENDP

;---------------------------------------------------------

  ; validate

  ; Validate that a number in eax is within a range
  ; Receives: the number in eax
  ; Returns:  1 if valid, 0 if invalid in ebx
  ; Preconditions: range boundaries stored in min and max
  ; constants
  ; Registers changed: ecx, edx, ebx, ebp

;---------------------------------------------------------

validate PROC

		; jump to invalid if number is smaller than 10
		push 	ebp
		mov 	ebp, esp
		push 	edx
		push	ecx
		mov		ecx, [ebp+8]

		cmp		ecx, min
		jl		invalid

		; jump to valid if number is 200 or smaller
		cmp		ecx, max
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
		pop		ecx
		pop 	edx
		pop 	ebp

		ret 	4

validate ENDP

;---------------------------------------------------------

  ; fillArray

  ; Fills an array passed by reference with random values,
  ; inspired by ArrayFill, page 298 of Irvine book
  ; Receives: offset of array and size of array
  ; Returns: nothing, fills array as side effect
  ; Preconditions: none
  ; Registers changed: eax, edx, ecx, ebp, esi

;---------------------------------------------------------

fillArray PROC

		push	ebp
		mov		ebp, esp
		pushad

		mov		esi, [ebp+12]
		mov		ecx, [ebp+8]
		cmp		ecx, 0
		je		endFill

	fillLoop:
		mov		eax, hi
		inc		eax
		sub		eax, lo

		call	RandomRange
		add		eax, lo
		mov		[esi], eax
		add		esi, TYPE DWORD
		loop	fillLoop

	endFill:
		popad
		pop		ebp

		ret		8

fillArray ENDP

;---------------------------------------------------------

  ; printArray (by row, EXTRA CREDIT)

  ; Prints to the screen an array passed by reference
  ; Receives: offset of array, size of array and array
  ; title (string) to be displayed
  ; Returns: nothing, prints array as side effect
  ; Preconditions: none
  ; Registers changed: eax, edx, ecx, ebp, esi

  ; NOTE: uncomment the printArray function below, and
  ; comment this one out to see ordering by column

;---------------------------------------------------------

printArray PROC

		push	ebp
		mov		ebp, esp
		pushad

		mov		ecx, [ebp+8]
		cmp		ecx, 0
		je		endPrint

		call 	CrLf
		mov		edx, OFFSET title_preamble
		call	WriteString
		mov		edx, [ebp+16]
		call	WriteString
		call	CrLf

		mov 	eax, 10

  addingLoop:
		mov		ebx, 0
		mov		esi, [ebp+12]

		printLoop:
			mov 	edx, ebx
			add 	edx, eax

			push 	interval
			push 	esi
			push 	edx
			call	printNum

			add		esi, TYPE DWORD
			inc 	ebx
			cmp 	ebx, ecx
			jb		printLoop

		dec		eax
		call	CrLf
		cmp		eax, 0
		ja 		addingLoop

	endPrint:
		popad
		pop		ebp

		ret		12

printArray ENDP


;---------------------------------------------------------

  ; printArray (by column, original, no EC)

  ; Prints to the screen an array passed by reference
  ; Receives: offset of array, size of array and array
  ; title (string) to be displayed
  ; Returns: nothing, prints array as side effect
  ; Preconditions: none
  ; Registers changed: eax, edx, ecx, ebp, esi

;---------------------------------------------------------

 ;printArray PROC
;
 		;push	ebp
 		;mov		ebp, esp
 		;pushad
;
 		;mov		esi, [ebp+12]
 		;mov		ecx, [ebp+8]
 		;cmp		ecx, 0
 		;je		endPrint
 		;call 	CrLf
 		;mov		edx, OFFSET title_preamble
 		;call	WriteString
 		;mov		edx, [ebp+16]
 		;call	WriteString
 		;call	CrLf
;
 	;printLoop:
 		;mov		eax, [esi]
 		;call	WriteDec
 		;mov		edx, OFFSET space
 		;call	WriteString
 		;call	WriteString
 		;call	WriteString
;
 		;push	interval
 		;push	[ebp+8]
 		;call	lineBreak
;
 		;add		esi, TYPE DWORD
 		;loop	printLoop
;
 	;endPrint:
 		;popad
 		;pop		ebp
;
 		;ret		12
;
 ;printArray ENDP

;---------------------------------------------------------

  ; printNum (used by printArray by row)

  ; Checks if the current iteration of the loop is a
  ; multiple of a certain interval and prints the appropriate
  ; items to achieve row ordering
  ; Receives: variable that holds the current interval, and
  ; the array by reference
  ; Returns: nothing, prints an item as side effect
  ; Preconditions: none
  ; Registers changed: eax, ebp, ebx, edx

;---------------------------------------------------------

printNum PROC

		push	ebp
		mov		ebp, esp
		pushad

 		mov 	eax, [ebp+8]
		sub		edx, edx ; clean edx for division
		mov		ebx, [ebp+16] ; move interval into ebx
 		div		ebx
 		cmp 	edx, 0
 		jne		noPrint; if the current number of printed items is not divisible by 10, skip adding the space

		mov 	esi, [ebp+12]
		mov		eax, [esi]
		call	WriteDec

		mov		edx, OFFSET space
		call	WriteString
		call	WriteString
		call	WriteString

	noPrint:
		popad
		pop		ebp

		ret		12

printNum ENDP

;---------------------------------------------------------

  ; lineBreak (used by printArray by column)

  ; Checks if the current iteration of the loop is a
  ; multiple of a certain interval and inserts a page break
  ; Receives: variable that holds the interval for a break
  ; Returns: nothing, adds a line break as a side effect
  ; Preconditions: none
  ; Registers changed: eax, ebp, ecx, ebx, edx

;---------------------------------------------------------

lineBreak PROC

		push	ebp
		mov		ebp, esp
		pushad

 		mov 	eax, [ebp+8]
 		sub		eax, ecx ; place the current number of printed items in eax
 		cmp		eax, 0
 		je		noLineBreak ; do not insert line break if this is the first iteration in the loop

 		inc		eax
		sub		edx, edx ; clean edx for division
		mov		ebx, [ebp+12] ; move divisor into ebx
 		div		ebx
 		cmp 	edx, 0
 		jne		noLineBreak ; if the current number of printed items is not divisible by 10, skip adding the space
 		call 	CrLf

	noLineBreak:
		popad
		pop		ebp

		ret		8

lineBreak ENDP

;---------------------------------------------------------

  ; sortArray

  ; Sorts an array passed by reference, with a simple
  ; bubble sort algorithm
  ; Receives: offset of array and size of array
  ; Returns: nothing, sorts array as side effect
  ; Preconditions: none
  ; Registers changed: eax, edx, ecx, ebp, esi

;---------------------------------------------------------

sortArray PROC ; receives the array to be sorted and the size

		push	ebp
		mov		ebp, esp
		pushad

	sortLoop:
		mov		esi, [ebp+12]
		mov		ecx, [ebp+8]
		dec		ecx
		cmp		ecx, 0
		jbe		endSort
		mov		edx, 0 ; flag to see if a swap happened in an iteration of the outer while loop

		swapLoop:
			mov		eax, [esi]
			cmp		eax, [esi+4]
			jae		dontSwap

			push	esi
			call	swap
			mov		edx, 1 ; set flag when swap happens

		dontSwap:
			add		esi, TYPE DWORD
			loop	swapLoop

		cmp		edx, 1
		je		sortLoop ; jump back and sort again if a swap was made this iteration

	endSort:
		popad
		pop		ebp

		ret		8

sortArray ENDP

;---------------------------------------------------------

  ; swap

  ; Swaps the value in a provided offset with the following
  ; value in a DWORD array
  ; Receives: offset of value to be swapped
  ; Returns: nothing, swaps values as side effect
  ; Preconditions: value needs to be in an array of DWORD
  ; Registers changed: eax, ebx, ebp, esi

;---------------------------------------------------------

swap PROC ; receives the two array items to be swapped by reference

		push	ebp
		mov		ebp, esp
		pushad

		mov		esi, [ebp+8]
		mov		ebx, [esi]
		mov		eax, [esi+4]
		mov		[esi+4], ebx
		mov		[esi], eax

		popad
		pop		ebp

		ret		4

swap ENDP

;---------------------------------------------------------

  ; printMedian

  ; Calculates the median of a set of values in an array,
  ; and prints it to the screen
  ; Receives: offset of array and size of array
  ; Returns: nothing, prints the median as side effect
  ; Preconditions: none
  ; Registers changed: eax, ebx, edx, ebp, esi

;---------------------------------------------------------

printMedian PROC

		push	ebp
		mov		ebp, esp
		pushad

		mov		esi, [ebp+12] ; array offset to esi
		mov		eax, [ebp+8] ; size to eax
		mov		ebx, 2

		sub		edx, edx ; clean edx to divide ??
		div		ebx ; divide the number of items in the array by 2
		push	edx ; save remainder to cmp later

		mov		ebx, 4
		mul		ebx
		add		esi, eax
		mov		eax, [esi]

		pop		edx ; restore edx
		cmp		edx, 0
		jne		printResult

		; if number of items is even

		sub		esi, 4
		add		eax, [esi]
		mov		ebx, 2
		div		ebx
		;jmp		printResult

	;odd:
		; if number of items is odd
		;add		esi, eax*4
		;mov		eax, [esi]

	printResult:
		call	CrLf
		mov		edx, OFFSET median_is
		call	WriteString
		call	WriteDec
		call	CrLf

		popad
		pop		ebp

		ret		8

printMedian ENDP

;---------------------------------------------------------

  ; farewell

  ; Displays a message to say good bye to the user
  ; Receives: offset of user_name variable
  ; Returns:  none
  ; Preconditions: user's name stored in user_name
  ; Registers changed: edx, ebp

;---------------------------------------------------------

farewell PROC

	call	CrLf
	mov		edx, OFFSET good_bye
	call	WriteString
	call	CrLf

	ret

farewell ENDP

END main
