; Unconditional Transfer(JMP) -> LOOP
INCLUDE Irvine32.inc
.code
main PROC
	mov eax,0
	L1:
		inc ax
		call DumpRegs
	loop L1
	exit
main ENDP
END main

; Conditional Transfer -> LOOP

INCLUDE Irvine32.inc
.code
main PROC
	mov eax,0
	L1:
	inc ax
	cmp ax, 9
	call DumpRegs
	JE endd
	jmp L1
	endd:
	exit
main ENDP
END main

; Increment b if a is greater otherwise break

INCLUDE Irvine32.inc
.data
	a BYTE 5h
	b BYTE 0h
.code
main PROC
	mov eax, 0
	mov al, a
	L1:
		cmp al, b
		call DumpRegs
		JG INCB
		JE endd
		jmp L1

	INCB:
		inc b
		jmp L1

	endd:
		exit
main ENDP
END main


INCLUDE Irvine32.inc
.data
	arr BYTE 1h, 2h, 3h
.code
main PROC
	mov esi,0
	mov eax,0
	mov ecx,0
	mov ebx, 0
	mov ecx, LENGTHOF arr
	L1:
		cmp ebx, ecx
		JE CHECK

		add al, arr[esi]
		inc esi
		inc ebx
		call DumpRegs
		jmp L1

	CHECK:
		exit
main ENDP
END main

INCLUDE Irvine32.inc

.data
	DASH BYTE "-", 0
.code
main PROC
	mov ecx, 0 ; By default use for loops. It decrements 1 from it and check if it is 0 or not and when it becomes 0, the loop will be terminated
	mov ecx, 255

	mov eax, 0
	mov eax, 1

	mov edx, 0
	mov edx, OFFSET DASH

	L1:
		call WriteDec
		call WriteString
		call WriteChar
		call crlf
		inc al
	loop L1
main ENDP
END main
