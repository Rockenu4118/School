; Assignment #6

.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD

INCLUDE Irvine32.inc

DifferentInputs PROTO,			; Question 2
	val1: DWORD, 
	val2: DWORD, 
	val3: DWORD

strConcat PROTO,				; Question 3
	target: PTR BYTE,
	source: PTR BYTE

.data
	targetString BYTE "ABCDE", 10 DUP(0)
	sourceString BYTE "FGH", 0
		
.code
main PROC
	; call test_DifferentInputs		
	
	INVOKE strConcat, ADDR targetString, ADDR sourceString 
	mov edx, OFFSET targetString								
	call WriteString											
	
	;call DumpRegs						; display registers in console
exit
main ENDP

;
; Answer to question 1
; 510
;

DifferentInputs PROC USES ebx,			; Question 2
	val1: DWORD,
	val2: DWORD,
	val3: DWORD
								; test all vals against eachother
	mov ebx, val1						; if any of them are equal to eachother,
	cmp ebx, val2						; jump to return 0
	jz return0						; or else just run into return 1

	cmp ebx, val3
	jz return0

	mov ebx, val2
	cmp ebx, val3
	jz return0
	
	return1:
		mov eax, 1
		ret

	return0:
		mov eax, 0
		ret
DifferentInputs ENDP

test_DifferentInputs PROC				; Test Question 2

	INVOKE DifferentInputs, 10h, 30h, 20h
	INVOKE DifferentInputs, 10h, 10h, 10h
	INVOKE DifferentInputs, 'a', 'b', 'c'
	INVOKE DifferentInputs, 40, 40, 50
	INVOKE DifferentInputs, 'f', '4', 'f'

test_DifferentInputs ENDP

strConcat PROC USES eax edx edi esi,	; Question 3
	target: PTR BYTE,
	source: PTR BYTE

	mov edi, target
	mov esi, source

	L1:
		mov al, [edi]					; move target chars into al
		cmp al, 0					; see if end has been reached
		jz L2						; if so, start concatenating
				
		inc edi						; if not, find end
		jmp L1
	L2:	
		mov dl, [esi]					; move source string char into dl
		mov [edi], dl					; copy over dl to target string

		inc esi						; inc esi to next char from source
		cmp BYTE PTR [esi], 0				; see if all chars have been copied
		jz return					; if so, return
		
		inc edi						; if not, keep copying

		jmp L2
	return:
		ret

strConcat ENDP

END main
	
