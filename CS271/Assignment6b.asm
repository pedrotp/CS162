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

macStr MACRO buffer

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

		; call Randomize ; needed?

		call intro

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

		mov		edx, OFFSET ec_2
		call	WriteString
		call	CrLf
		call	CrLf

		; instructions
		mov		edx, OFFSET instructions
		call	WriteString
		call	CrLf
		call 	CrLf

		popad

		ret

intro ENDP

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
