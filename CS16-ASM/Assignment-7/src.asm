; Assignment #7

.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD



INCLUDE Irvine32.inc

.data
	titleStr BYTE "Assignment 7", 0

	; SQUARE - Question 1
	bufLength DWORD 21
	; Top and bottom
	horizontalLine BYTE 42, 32, 42, 32, 42, 32, 42, 32, 42, 32, 42, 32, 42, 32, 42, 32, 42, 32, 42, 32, 42
	startPointTop COORD <45, 11>
	startPointBottom COORD <45, 21>
	
	; Sides
	verticalLine BYTE 42, 19 DUP(32), 42
	startPoint12 COORD <45, 12>
	startPoint13 COORD <45, 13>
	startPoint14 COORD <45, 14>
	startPoint15 COORD <45, 15>

	verticalLine16 BYTE 42, 3 DUP(32), 42, 32, 42, 32, 42, 11 DUP(32), 42
	startPoint16 COORD <45, 16>
	verticalLine17 BYTE 42, 3 DUP(32), 42, 3 DUP(32), 42, 3 DUP(32), 42, 32, 42, 32, 42, 3 DUP(32), 42
	startPoint17 COORD <45, 17>
	verticalLine18 BYTE 42, 3 DUP(32), 42, 3 DUP(32), 42, 3 DUP(32), 42, 3 DUP(32), 42, 3 DUP(32), 42
	startPoint18 COORD <45, 18>
	verticalLine19 BYTE 42, 3 DUP(32), 42, 3 DUP(32), 42, 3 DUP(32), 42, 32, 42, 32, 42, 3 DUP(32), 42
	startPoint19 COORD <45, 19>
	verticalLine20 BYTE 42, 3 DUP(32), 42, 3 DUP(32), 42, 11 DUP(32), 42
	startPoint20 COORD <45, 20>

	writeCount DWORD 0
	stdioHandle HANDLE ?

	; TRIANGLE - Question 2
	triangleTip BYTE 42, 3 DUP(32), 42, 32, 42, 32, 42
	triangleTipStart COORD <55, 5>
	slantedLine6 BYTE 42, 3 DUP(32), 42, 32, 42, 3 DUP(32), 42
	startPoint6 COORD <53, 6>
	slantedLine7 BYTE 42, 7 DUP(32), 42, 3 DUP(32), 42
	startPoint7 COORD <51, 7>
	slantedLine8 BYTE 42, 11 DUP(32), 42, 32, 42
	startPoint8 COORD <49, 8>
	slantedLine9 BYTE 42, 15 DUP(32), 42
	startPoint9 COORD <47, 9>
	slantedLine10 BYTE 42, 19 DUP(32), 42
	startPoint10 COORD <45, 10>

	; SMALL SQUARE - Question 4
	smallBufLength DWORD 9
	smallHorizontal BYTE 42, 32, 42, 32, 42, 32, 42, 32, 42
	smallVertical BYTE 42, 7 DUP(32), 42

	smallSquareStart COORD <>
	smallSquareStartX WORD ?
	smallSquareStartY WORD ?

	timeToMove DWORD ?


.code
main PROC
	INVOKE SetConsoleTitle, ADDR titleStr
	INVOKE GetStdHandle, STD_OUTPUT_HANDLE
	mov stdiohandle, eax
	
	; Move Square - Question 4 (10 random movements)
	mov ecx, 10
	L1:	
		push ecx
		; Randomize location
		call Randomize
		mov eax, 30
		call RandomRange
		mov smallSquareStart.X, ax
		mov eax, 30
		call RandomRange
		mov smallSquareStart.Y, ax
		
		; Randomize delays - Extra Credit
		mov eax, 90
		call RandomRange
		add eax, 10
		mov timeToMove, eax

		; Draw small square
		mov eax, timeToMove
		call Delay
		INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET smallHorizontal, smallBuflength, smallSquareStart, OFFSET writeCount
		inc smallSquareStart.Y
		INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET smallVertical, smallBufLength, smallSquareStart, OFFSET writeCount
		inc smallSquareStart.Y
		INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET smallVertical, smallBufLength, smallSquareStart, OFFSET writeCount
		inc smallSquareStart.Y
		INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET smallVertical, smallBufLength, smallSquareStart, OFFSET writeCount
		inc smallSquareStart.Y
		INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET smallHorizontal, smallBuflength, smallSquareStart, OFFSET writeCount
		mov eax, timeToMove
		call Delay
		call Clrscr

		; get around jump destination error
		pop ecx
		dec cx
		jnz L1

	;
	;	House blended in within square and triangle drawings
	;

	; Draw Square - Question 1
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET horizontalLine, buflength, startPointTop, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET verticalLine, buflength, startPoint12, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET verticalLine, buflength, startPoint13, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET verticalLine, buflength, startPoint14, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET verticalLine, buflength, startPoint15, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET verticalLine16, buflength, startPoint16, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET verticalLine17, buflength, startPoint17, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET verticalLine18, buflength, startPoint18, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET verticalLine19, buflength, startPoint19, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET verticalLine20, buflength, startPoint20, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET horizontalLine, buflength, startPointBottom, OFFSET writeCount

	; Draw Triangle - Question 2
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET triangleTip, 9, triangleTipStart, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET slantedLine6, 11, startPoint6, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET slantedLine7, 13, startPoint7, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET slantedLine8, 15, startPoint8, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET slantedLine9, 17, startPoint9, OFFSET writeCount
	INVOKE WriteConsoleOutputCharacter, stdioHandle, OFFSET slantedLine10, 21, startPoint10, OFFSET writeCount

exit
main ENDP


END main
	
