; Asm Assignment #3 Part 1

INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

.data
	vals WORD 100h, 200h, 300h, 400h, 500h, 600h, 700h, 800h
	
.code
main PROC
	mov edi, OFFSET vals		; store a ptr to beginning of vals array
	mov ecx, LENGTHOF vals / 2	; store the number of elements in vals array, divided by 2 to target 4 pairs


L1:
	mov eax, 0					; clear eax
	mov ax, [edi]				; store first val of pair in ax
	add edi, TYPE vals			; raise destination index to second val of pair
	xchg ax, [edi]				; swap ax val and second val of pair
	sub edi, TYPE vals			; lower destination index back to first val of pair
	xchg ax, [edi]				; swap ax val and first val of pair

	add edi, 2*TYPE vals		; raise destination index to the next pair

	loop L1						; continue until all pairs have been swapped



	call DumpRegs				; display registers in console

exit
main ENDP
END main
