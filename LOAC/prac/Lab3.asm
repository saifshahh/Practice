INCLUDE Irvine32.inc   

; Task 1
;.data
;	val1 SWORD ?
;	val2 SBYTE -11
;.code
;main PROC
;	exit
;main ENDP
;END main

; Task 2
.data
	val3 SWORD -2147483648

.code
main PROC
	exit
main ENDP
END main

; Task 3
.data
	list WORD 1000,2000,3000

.code
main PROC
	exit
main ENDP
END main

; Task 4

.data
	color BYTE "Black", 0
	A WORD 12
	B WORD 2
	C WORD 13
	D WORD 8
	E WORD 14
.code
main PROC
	exit
main ENDP
END main

; Task 5
.data
	a DWORD 11h
	b DWORD 10h
	c DWORD 30h
	d DWORD 40h
.code 
main PROC
	mov eax,a ; eax is used for 32 bit
	mov ebx,b
	add eax,ebx
	mov ecx,a
	mov edx, b
	sub ecx,edx
	add eax,ecx
	mov edx,c
	add eax,edx
	mov edx, d
	add eax,edx
	call DumpRegs
	exit
main ENDP
END main

; Task 6
.data
	a BYTE 00010001b
	b BYTE 00010000b
	c BYTE 00110000b
	d BYTE 01000000b

.code
main PROC
	mov al,a ;al is used for 8 bit 
	mov bl,b
	add al,bl
	mov cl,a
	mov dl, b
	sub cl,dl
	add al,cl
	mov dl,c
	add al,dl
	mov dl, d
	add al,dl
	call DumpRegs
	exit
main ENDP
END main

; Task 7
.data
	wArray WORD 1000h,2000h,3000h
.code
main PROC
	exit
main ENDP
END main

; Task 8
.data
	dArray DWORD 50 dup(?)
.code
main PROC
	exit
main ENDP
END main

; Task 9
.data
	string BYTE 500 dup("TEST")
.code
main PROC
	exit
main ENDP
END main

; Task 10
.data
	bArray BYTE 20 dup(0FFh)
.code
main PROC
	exit
main ENDP
END main
