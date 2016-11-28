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
set_min equ 3
set_max equ 13

printString MACRO buffer

	push edx
	mov edx, OFFSET buffer
	call WriteString
	pop edx

ENDM

.data

; global variable definitions
intro_1 BYTE "Hi, my name is Pedro Torres Picon", 0
intro_2 BYTE "This program is called Combinations Quizzer", 0
ec_1 BYTE "**EXTRA CREDIT: Each problem is numbered, score is kept", 0
ec_2 BYTE "**EXTRA CREDIT: Factorials are computed in the floating point unit", 0
instructions BYTE "I will ask you to calculate the number of combinations of r items taken from a set of n items. You give me your best guess, and I'll let you know if you're right.", 0
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
error_1	BYTE "Whoops! Input must be an unsigned positive integer. Please try again.", 0
error_2 BYTE "Hm, looks like you entered an empty string. Please try again.", 0
prompt_again BYTE "Would you like another problem? (y/n)", 0
error_3 BYTE "Uh oh, I don't know what that means", 0
score_1 BYTE "************ FINAL SCORE ************", 0
score_2 BYTE "  RIGHT ANSWERS: ", 0
score_3 BYTE "  WRONG ANSWERS: ", 0
score_4 BYTE "*************************************", 0
good_bye BYTE "That's all for now. Until next time! Good bye", 0

space BYTE " ", 0

problem_num DWORD 0
set_size DWORD ? ; n
subset_size DWORD ? ; r
input BYTE input_size DUP(?) ; the user's raw string input
answer DWORD ? ; the user's answer
result DWORD ? ; the actual result
score DWORD 0
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

	call  Randomize ; seed for random numbers
	call  intro

	; quizLoop:
    push  OFFSET problem_num
    push  OFFSET set_size
    push  OFFSET subset_size
    call  showProblem

    push  OFFSET answer
    push  input_size
    push  OFFSET input
    call  getData

    ; cmp   play_again, 0
    ; jne   quizLoop

	call  farewell
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

	printString ec_2
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

    mov		eax, set_max
    sub		eax, set_min
    call	RandomRange
    add		eax, set_min
    mov		[ebp+12], eax ; set size

    call	RandomRange
    inc		eax
    mov		[ebp+8], eax ; subset size

    printString title_1
	mov		esi, [ebp+16]
	mov		eax, [esi]
	inc		eax
    call	WriteDec
	mov		[esi], eax
    printString title_2
    call 	CrLf

    printString prompt_1
    mov		eax, [ebp+8]
    call	WriteDec
    printString prompt_2
    mov		eax, [ebp+12]
	call	WriteDec
    printString prompt_3
    call 	CrLf

    popad
    pop		ebp

	ret		8

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
    je		emptyString

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
    loop	checkDigits

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
    loop	parseNum
    jmp		allDone

  notDigits:
    pop		ecx
    printString error_1
    jmp		getInput

  emptyString:
    printString error_2
    jmp		getInput

  allDone:
    call	WriteDec

    popad
    pop		ebp

  	ret		12

getData ENDP

;---------------------------------------------------------

  ; farewell

  ; Displays a message to say good bye to the user
  ; Receives: none
  ; Returns:  none
  ; Preconditions: none
  ; Registers changed: edx

;---------------------------------------------------------

farewell PROC

	call	CrLf
	printString good_bye
	call	CrLf

	ret

farewell ENDP

END main
