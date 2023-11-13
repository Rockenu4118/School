; Assignment #5

.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD

INCLUDE Irvine32.inc

DECIMAL_OFFSET=5

.data
	decimal_one BYTE "100123456789765"
	decimal_two BYTE "56789123"
	decimal_three BYTE "91234567"

	key BYTE -2, 4, 1, 0, -3, 5, 2, -4, -4, 6
	message BYTE "1234567890"
	
.code
main PROC
	; call procs as needed

	; call proc_one
	; call test_WriteScaled
	; call proc_three

	
	call DumpRegs				; display registers in console
exit
main ENDP

proc_one PROC					; Question 1

	mov bx, ax					; move ax into bx
	shl bx, 4					; multiply bx by 16
	push bx						; save bx

	mov bx, ax					; move ax into bx
	shl bx, 3					; multiply bx 8

	shl ax, 1					; multiply ax by 2
	add ax, bx					; add current bx to ax
	
	pop bx						; retrieve old bx
	add ax, bx					; add onto current ax

proc_one ENDP

WriteScaled PROC				; Question 2
	mov ebx, ecx				; move loop counter val into ebx
	sub ebx, DECIMAL_OFFSET		; subtract decimal offset from ebx to represent position to place decimal

	write_string:
		cmp BYTE PTR[edx], 0	; check if current BYTE is 0
		jz return				; if so, end of array has been reached

		cmp ebx, 0				; check if decimal position has been reached
		jnz write_char			; if not, print current letter

		mov al, '.'				; if so, move decimal into al
		call WriteChar			; print al

		dec ebx					; dec position in array to not repeat decimal

		jmp write_string		; continue without decrementing loop counter

	write_char:
		mov al, BYTE PTR[edx]	; move current letter into al
		call WriteChar			; print al

		dec ebx					; dec position to not repeat decimals
		add edx, TYPE BYTE		; inc array element

		loop write_string		; continue

	return:
		call CrlF				; print new line
		ret						; return

WriteScaled ENDP

test_WriteScaled PROC		; Question 2
	
	mov edx, OFFSET decimal_one			; move beginning of byte array into edx
	mov ecx, LENGTHOF decimal_one		; move length of byte array into loop counter
	mov ebx, OFFSET DECIMAL_OFFSET		

	call WriteScaled		; output: "1001234567.89765"

	mov edx, OFFSET decimal_two			
	mov ecx, LENGTHOF decimal_two		
	mov ebx, OFFSET DECIMAL_OFFSET		

	call WriteScaled		; output: "567.89123"

	mov edx, OFFSET decimal_three			
	mov ecx, LENGTHOF decimal_three		
	mov ebx, OFFSET DECIMAL_OFFSET		

	call WriteScaled		; output: "912.34567"

test_WriteScaled ENDP

proc_three PROC					; Question 3

	mov esi, OFFSET key			; move beginning of key into esi
	mov edx, 0					; clear edx

	encrypt:
		cmp BYTE PTR[message + edx], 0	; check to see if reached end of array
		jz return						; if so, return

		cmp BYTE PTR[esi], 0			; check if key val is 0

		jz continue						; if so, continue
		js rotate_left					; if negative, shift left
		jns rotate_right				; if positive, shift right

	rotate_left:
		mov cl, BYTE PTR[esi]			; move key val into al
		neg cl							; get positive val of key
		rol [message + edx], cl			; shift message left by cl
		jmp continue					; continue

	rotate_right:
		mov cl, BYTE PTR[esi]			; move key val into al
		ror [message + edx], cl			; shift message right by cl
		jmp continue

	continue:
		add edx, TYPE BYTE				; point edx to next element
		add esi, TYPE BYTE				; point esi to next element

		jmp encrypt						; continue

	return:
		ret								; return

proc_three ENDP

END main
