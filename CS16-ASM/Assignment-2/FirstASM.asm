; Asm Assignment #2

INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

.data
val1	dword 1000h
val2	dword 2000h
result1 dword ?
result2 dword ?

.code
main PROC
	mov eax, val1		; set eax to val1 (1000h)
	sub eax, val2		; subtract val2 (2000h)
	add eax, val1		; add val1 (1000h)
	add eax, val2		; add val2 (2000h)

	mov result1, eax    ; store eax value as result1 (2000h)

	mov ebx, result1	; set ebx to result1 (2000h)
	sub ebx, val1		; subtract val1 (1000h)
	sub ebx, val2		; subtract val2 (2000h)

	mov result2, ebx	; store ebx value as result2


	call DumpRegs		; display registers in console

	exit
main ENDP
END main
