; Task 2
.data
	myname WORD "R", "A", "G"
	myNames BYTE "R", "A", "G"
	MyNaming DWORD "R", "A", "G"
.code
main PROC
	mov eax,0
	mov ebx,0
	mov ecx,0
	mov ax, [myname]
	mov bx, [myname+1]
	mov cx, [myname+2]
	mov eax,0
	mov ebx,0
	mov ecx,0
	mov al, [myNames]
	mov bl, [myNames+1]
	mov cl, [myNames+2]
	mov eax,0
	mov ebx,0
	mov ecx,0
	mov eax, [MyNaming]
	mov ebx, [MyNaming+1]
	mov ecx, [MyNaming+2]

	call DumpRegs
	exit
main ENDP
END main

; Task 3

.data
	varB BYTE +10 
	varW WORD -150 
	varD DWORD 600 
.code
main PROC
	mov al,varB
	movzx eax,al

	mov bx,varW
	movsx ebx,bx
	
	mov ecx,varD

	call DumpRegs
	exit
main ENDP
END main


; Task 4
.data
	Val1 DWORD 25h  
	Val2 BYTE 36o  
	Val3 WORD 20d  
.code
main PROC
	; (i)
	mov eax, 0
	mov eax, 89
	add eax, 75Fh
	sub eax, 46o
	sub eax, 28
	add eax, 1101b

	; (ii)
	mov eax,0
	mov ebx,0
	mov eax, val1
	mov bl, val2
	movzx ebx, bl
	add eax,ebx
	sub eax, 654h
	mov ebx, 0
	mov bx, val3
	movzx ebx, bx
	add eax, ebx

	call DumpRegs
	exit
main ENDP
END main

; Task 6
.data
	SecondsInDay = 86400
	SecondsInDays EQU 24 * 60 * 60
.code
main PROC
	mov eax, 0
	mov ebx, 0
	mov eax,SecondsInDay
	mov ebx,SecondsInDays
	call DumpRegs
	exit
main ENDP
END main

; Task 7
.data
	A DWORD 0FF10h
	B DWORD 0E10Bh
.code
main PROC
	mov eax,0
	mov ebx,0
	mov eax,A
	mov ebx,B
	xchg eax,ebx
	mov A,eax
	mov B,ebx
	call DumpRegs
	exit
main ENDP
END main

; Task 8
.data
	 val1 BYTE 10h
	 val2 WORD 8000h
	 val3 DWORD 0FFFFh
	 val4 WORD 7FFFh
.code
main PROC
	mov eax, 0
	mov ebx, 0
	mov ecx,0

	mov ax,val2
	INC ax ; (i)

	sub ebx,val3 ; (ii)
	
	mov cx, val2
	sub cx ,val4

	call DumpRegs
	exit
main ENDP
END main
