; Asm Assignment #3 Part 2

INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

.data
	vals   DWORD 0, 2, 5, 9, 10 	; an array of DWORD vals
	result DWORD 0					      ; sum of all the gaps between elements
	
.code
main PROC
	mov edi, OFFSET vals			    ; store a ptr to beginning of vals array
	mov ecx, LENGTHOF vals			  ; store the number of elements in vals array
	sub ecx, 1						        ; will take 1 less iteration than number of elements to add differences

	mov eax, 0						        ; clear eax

L1:
	add edi, TYPE vals				    ; raise destination index to next val
	mov eax, [edi]					      ; store this val in eax
	sub edi, TYPE vals				    ; lower destination back to previous val
	sub eax, [edi]					      ; subtract this val from eax (find difference of this val and next one)

	add result, eax					      ; add difference to result

	add edi, TYPE vals				    ; raise destination index to next val
	
	loop L1							          ; loop until all differences have been found and added together
	
	mov eax, result					      ; display final result in eax


	call DumpRegs					        ; display registers in console
exit
main ENDP
END main
