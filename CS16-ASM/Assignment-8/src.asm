; Assignment #8

.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD

INCLUDE Irvine32.inc

.data
	; Question 3
	LowerPrompt BYTE "X is lower", 0
	HigherPrompt BYTE "X is higher", 0

	X REAL8 1.2
	Y REAL8 1.5

	; Question 4
	coefficientPrompt BYTE "Please enter coefficients", 0

	imaginaryRoots BYTE "Imaginary roots", 0
	oneRoot BYTE "One root", 0
	twoRoots BYTE "Two roots", 0

	A REAL8 ?
	B REAL8 ?
	D REAL8 ?		; not allowed to use C

	fourConst REAL8 4.0
	twoConst REAL8  2.0
	zeroConst REAL8 0.0

	discriminant REAL8 ?

	root1 REAL8 ?
	root2 REAL8 ?
	
	
.code
main PROC
	
	; Question 3
	fld X
	fld Y

	fcomi ST(0), ST(1)
	jb Lower

	mov edx, OFFSET LowerPrompt
	call WriteString
	jmp continue

	Lower:
		mov edx, OFFSET HigherPrompt
		call WriteString
		
	continue:
	

	; Question 4
	
	mov edx, OFFSET coefficientPrompt
	call WriteString
	call Crlf

	call ReadFloat
	fstp A
	call ReadFloat
	fstp B
	call ReadFloat
	fstp D

	fld B
	fmul B
	fld fourConst
	fmul A
	fmul D
	fsub
	fld zeroConst
	fcomi ST(0), ST(1)
	fstp zeroConst
	fstp discriminant
	ja imaginaryCase
	jb twoRootCase

	; single root case
	mov edx, OFFSET oneRoot
	call WriteString
	call Crlf

	fld B
	fchs
	fld twoConst
	fld A
	fmul
	fdiv
	call WriteFloat
	call Crlf

	fstp root1

	jmp next
	twoRootCase:	; two root case
		mov edx, OFFSET twoRoots
		call WriteString
		call Crlf

		fld B
		fchs
		fld discriminant
		fsqrt
		fadd
		fld twoConst
		fld A
		fmul
		fdiv
		call WriteFloat
		call Crlf
		fstp root1

		fld B
		fchs
		fld discriminant
		fsqrt
		fsub
		fld twoConst
		fld A
		fmul
		fdiv
		call WriteFloat
		fstp root2

	jmp next
	imaginaryCase:	; imaginary root case
		mov edx, OFFSET imaginaryRoots
		call WriteString

	next:
		call Crlf
exit
main ENDP

END main
