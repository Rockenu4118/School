; Assignment #4



.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD

INCLUDE Irvine32.inc

.data
	array SWORD 50 DUP(?)			    ; Question 1
	sentinel SWORD 0FFFFh

	val1 DWORD ?					        ; Question 4

	grade DWORD ?					        ; Question 5
	
.code
main PROC
	call proc_one					        ; can test out all the different procedures
	call proc_two
	call proc_three
	call proc_four
	call test_CalcGrade

	call DumpRegs					        ; display registers in console
exit
main ENDP

proc_one PROC						        ; Question 1
	mov esi, OFFSET array
	mov ecx, LENGTHOF array

L1:	cmp WORD PTR [esi], 0			  ; check for zero
	jnz nonZero						        ; jump if zero flag was not set (located first non-zero val)

	add esi, TYPE array				    ; increment esi to point to next val
	loop L1							          ; loop

	mov esi, DWORD PTR sentinel		; value not found, point esi to sentinel
	ret								            ; exit procedure

nonZero:
	ret								            ; exit procedure when non-zero val has been located
proc_one ENDP

proc_two PROC						        ; Question 2
	cmp ebx, ecx					        ; check if ebx is less than ecx
	ja return						          ; if not, jump to return

	mov eax, 5						        ; if true move 5 to eax
	mov edx, 6						        ; and 6 to edx

return:
	ret								            ; exit procedure
proc_two ENDP

proc_three PROC						      ; Question 3
	cmp ebx, ecx					        ; check if ebx is less than or equal to ecx
	jnle return						        ; if not, jump to return

	cmp ecx, edx					        ; check if ecx is greater than edx
	jng return						        ; if not, jump to return

	mov eax, 5						        ; if true move 5 to eax
	mov edx, 6						        ; and 6 to edx

return:
	ret							            	; exit procedure

proc_three ENDP

proc_four PROC						      ; Question 4
	while_loop: cmp ebx, val1		  ; check if ebx is less than or equal to val1
		ja return					          ; if not, jump to return

		add ebx, 5					        ; if true, add 5 to ebx
		dec val1					          ; and dec val1

		jmp while_loop				      ; continue loop

		ret							            ; exit procedure

return:
	ret								            ; exit procedure

proc_four ENDP

CalcGrade PROC
	cmp grade, 90					        ; check if grade is above or equal to 90
	jae gradeA						        ; if so, jump to grade A
	
	cmp grade, 80					        ; check if grade is above or equal to 80
	jae gradeB          			    ; if so, jump to grade B
	
	cmp grade, 70					        ; check if grade is above or equal to 70
	jae gradeC          			    ; if so, jump to grade C
	
	cmp grade, 60					        ; check if grade is above or equal to 60
	jae gradeD          			    ; if so, jump to grade D

	jmp gradeF						        ; grade must be F if none else

gradeA:
	mov al, 'A'						        ; move respective grades into al
	ret

gradeB:
	mov al, 'B'
	ret

gradeC:
	mov al, 'C'
	ret

gradeD:
	mov al, 'D'
	ret

gradeF:
	mov al, 'F'
	ret

CalcGrade ENDP

test_CalcGrade PROC
	call Randomize					      ; reseed randomizer

	mov eax, 51						        ; move random range from 0 to 51 into eax
	call RandomRange				      ; generate random int
	add eax, 50						        ; add 50 to eax to get int from 51 to 101

	mov grade, eax					      ; move eax into grade
	call calcGrade					      ; calcGrade

									              ; repeat 9 more times
	mov eax, 51						
	call RandomRange				
	add eax, 50						

	mov grade, eax			
	call calcGrade					

	mov eax, 51						
	call RandomRange				
	add eax, 50		

	mov grade, eax				
	call calcGrade				

	mov eax, 51						
	call RandomRange				
	add eax, 50						

	mov grade, eax				
	call calcGrade				

	mov eax, 51						
	call RandomRange			
	add eax, 50						

	mov grade, eax				
	call calcGrade					

	mov eax, 51						
	call RandomRange				
	add eax, 50					

	mov grade, eax					
	call calcGrade					

	mov eax, 51						
	call RandomRange				
	add eax, 50						

	mov grade, eax				
	call calcGrade					

	mov eax, 51					
	call RandomRange				
	add eax, 50						

	mov grade, eax			
	call calcGrade				

	mov eax, 51						
	call RandomRange				
	add eax, 50						

	mov grade, eax					
	call calcGrade					

	mov eax, 51						
	call RandomRange			
	add eax, 50						

	mov grade, eax				
	call calcGrade					

	ret								; exit procedure

test_CalcGrade ENDP

END main
