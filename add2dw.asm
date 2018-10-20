; Assembly program to add two (dw) numbers in NASM 
; Author:  Gh. Dastghaibyfard dstghaib@shirazu.ac.ir  (Shiraz University)
; Date:    Esfand 1396,  To Compile, Link and Execute see readme.txt file

%include "io.h"           ; header file for input/output

%define newline 0xA
%define SYS_EXIT 0x001

        SEGMENT .data		; read-write data

msg1	db  "Assembly program to add two (dw) numbers i.e.", newline
        db  "from -2^15  (-32768) TO 2^15 -1 (32767)", 0

	msg2	db  newline, "Please Enter 1st word number: ", 0
	msg3	db  newline, "Please Enter 2nd word number: ", 0
	prtsum  db  newline, "Sum of ",
	times 6 db  ' ',
	        db  " + ",
	times 6 db  ' ',
	        db  " = ",
	times 6 db  ' ',
	        db  newline, 0
	string  times 20 db ' ' 
	num1	dw  0
	num2	dw  0

	
	SEGMENT .bss		; uninitialized data

	
	SEGMENT .text   ; start of main program code
	global main
main:	call   _main
exit:	mov    eax, SYS_EXIT	; system call number (SYS_EXIT) 
	xor    ebx, ebx         ; set exit code to 0
	int    0x80 		; syscall
	
_main:			; Main Program
	output  msg1			; message for what this program do
	output  msg2			; message to read first number
	input   string,15		; read ASCII characters
	atoi    string			; convert ASCII character to word
	mov     [num1],ax		; store in memory

	output  msg3			; message to read second number
	input   string,15		; read ASCII characters
	atoi    string			; convert ASCII character to word
	mov     [num2],ax		; store in memory
	
	mov     ax,[num1]    	; move first number to AX
	add     ax,[num2]    	; add second number to AX

	itoa    prtsum+08,[num1]; convert word to ASCII characters
	itoa    prtsum+17,[num2]; convert word to ASCII characters
	itoa    prtsum+26,ax	; convert word to ASCII characters
	output  prtsum
	;; output  prtsum, 10	; output prtsum
	ret						; return
