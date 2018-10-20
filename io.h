;  This file should be attached to NASM assembly programs
;  Author:  Gh. Dastghaibyfard dstghaib@shirazu.ac.ir  (Shiraz University)
;  Date:    Esfand 1396, To Compile, Link and Execute see readme.txt file
extern  itoaproc, atoiproc, dtoaproc, atodproc
extern  puts, getns, putcs

%macro	    itoa   2	        ;; dest,source   convert integer to ASCII string
            push   ebx          ;; save EBX
            mov    bx,%2	;;
            push   bx           ;; source parameter
            mov    ebx,%1       ;; destination address
            push   ebx          ;; destination parameter
            call   itoaproc     ;; call itoaproc(source,dest)
            pop    ebx          ;; restore EBX
%endmacro

%macro      atoi  1             ;;  source;; convert ASCII string to integer in AX
                                ;; offset of terminating character in ESI
            push   ebx          ;; save EBX
            mov    ebx,%1  	;; source address to EBX
            push   ebx          ;; source parameter on stack
            call   atoiproc     ;; call atoiproc(source)
            pop    ebx          ;; parameter removed by ret
%endmacro

%macro	    dtoa   2        ;; dest,source   ;; convert double to ASCII string
            push   ebx      ;; save EBX
            mov    ebx,%2
            push   ebx      ;; source parameter
            mov    ebx,%1   ;; destination address
            push   ebx      ;; destination parameter
            call   dtoaproc ;; call dtoaproc(source,dest)
            pop    ebx      ;; restore EBX
%endmacro

%macro	    atod   1          ;;source;; convert ASCII string to integer in EAX
                              ;; offset of terminating character in ESI
            mov    eax,%1     ;; source address to EAX
            push   eax        ;; source parameter on stack
            call   atodproc   ;; call atodproc(source)
                              ;; parameter will be removed by ret
%endmacro

;------------------------------------------------------------------------------;

	; Print a null-terminated char seq
%macro  output 1		; Args: char-seq
	pushf			; Save flags
	push   eax		; Save eax, retval of puts will be in eax
	sub    esp, 4		; 16-bit align

	push   %1		; Put param on stack for subroutine
	call   puts		; Call the C subroutine
	add    esp, 8           ; Skip passed param and alignment offset

	pop    eax		; Restore eax
	popf			; Restore flags
%endmacro

	; Print %2 chars from a null-terminated char-seq %1
%macro  output 2 		; Args: char-seq, len
	pushf			; Save flags
	push   eax		; Save eax
	
	push   %2		; 2nd Arg, char-seq's len
	push   %1		; 1st Arg, pointer to char-seq
	call   putcs	; Call the C subroutine
	add    esp, 8           ; Skip passed param
	
	pop   eax		; Restore eax
	popf			; Restore flags
%endmacro 

	; Read a char-seq from stdin to a buffer(%1) of 
        ; at most %2 chars. char-seq will include newline
	; and null-char at the end.
%macro  input  2   ;; str, max_len(message + newline + nil)
	pushf			; Save flags
	push   eax		; Save eax

	push   %2		; 2nd Arg, buffer size
	push   %1		; 1st Arg, buffer pointer
	call   getns		; Call the C subroutine
	add    esp, 8   	; Skip passed param

	pop    eax		; Restore eax
	popf			; Restore flags
%endmacro


; ; print a string
; %macro outputlin 2
;   pushad
;   mov eax, 4	;; FILE PRINT SERVICE
;   mov ebx, 1	;; 1 = STD OUTPUT (MONITOR)
;   mov ecx, %1	;; POINTER TO OUTPUT BUFFER
;   mov edx, [%2]	;; OUTPUT BUFFER SIZE --->%2IF NOT EQU PROBLEM????
;   int 80h
;   popad
; %endmacro 


; 	; READ A STRING
; %macro inputlin 2   ;; str, max len
; 	PUSHAD	
; 	PUSHF
; 	MOV EAX,3 	;; FILE READ SERVICE
; 	MOV EBX,0  	;; 0 = STD INPUT(KEYBOARD)
; 	MOV ECX,%1  ;; POINTER TO INPUT BUFFER
; 	MOV EDX,%2 	;; INPUT BUFFER SIZE
; 	INT 0X80	
; 	DEC EAX
; ;	MOV [%3],EAX ; LENGTH OF STRING READ
; 	MOV BYTE[ECX+EAX], 0 ; NULL POINTER
; 	POPF
; 	POPAD
; %endmacro
