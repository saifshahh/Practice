; REMAINING

; OFFSET OPERATOR

.data 
	.data
	bVal   BYTE ? 
	wVal   WORD ? 
	dVal   DWORD ? 
	dVal2  DWORD ? 

.code 
main PROC
	mov esi, 0
	mov esi, OFFSET bVal
	mov esi, OFFSET wVal  ; Loads 00404001h into ESI
	mov esi, OFFSET dVal  ; Loads 00404003h into ESI
	mov esi, OFFSET dVal2 ; Loads 00404007h into ESI
	call DumpRegs
main ENDP
END main

; TYPE OPERATOR

.data 
	var1   BYTE   20h 
	var2 WORD 1000h 
	var3 DWORD ? 
	;var5 QWORD ?
	var5 SWORD ?
	var4 BYTE 10, 20, 30, 40, 50 
	msg BYTE "File not found", 0 
.code
main PROC
	mov eax, 0
	mov ax, type var1 
	mov ax, type var2 
	mov ax, type var3 
	mov ax, type var4 
	mov ax, type msg 
	mov ax, type var5
	call DumpRegs
main ENDP
END main

; PTR OPERATOR

.data 
	myDouble DWORD 12345678h 
.code
main PROC 
	mov eax, 0
	mov eax, myDouble
	mov eax, 0
	;mov ax, myDouble ; error
	mov ax, word ptr myDouble 
	mov ax, type myDouble
	mov ax, word ptr myDouble + 1 ; pointer was on 5 so +1 moves it to 3 (Jumps 1 previous element)
	mov ax, word ptr myDouble + 2 ; pointer was on 3 so +2 moves it to 1 (Jumps 1 previous element)
	mov ax, word ptr myDouble + 3 ; pointer was on 1 so +3 moves it to 0 (Jumps 1 previous element)
	mov ax, word ptr myDouble + 4 ; pointer was on 0 so +4 moves it to 0 (Jumps 1 previous element)
	mov ax, word ptr myDouble -1
	mov ax, word ptr myDouble - 2
	mov ax, word ptr myDouble - 3
	mov ax, word ptr myDouble - 4
	call DumpRegs
main ENDP
END main

; LENGTHOF OPERATOR

.data 
	val1 WORD 1000h 
	val2 SWORD 10, 20, 30 
	array WORD 10 DUP(?),0 ; 0 index included
	array2 WORD 5 DUP(3 DUP(0)) 
	msg BYTE 'File not found' ; 0 index not included
.code 
main PROC
	mov eax, 0
	mov ax, LENGTHOF val1 ; AX = 1 
	mov ax, LENGTHOF val2 ; AX = 3 
	mov ax, LENGTHOF array ; AX = 11 
	mov ax, LENGTHOF array2 ; AX = 15 
	mov ax, LENGTHOF msg; AX=14
	call DumpRegs
main ENDP
END main

; INDIRECT OPERANTS

.data 
	val BYTE 10h
.code 
main PROC
	mov esi,0
	mov eax,0
	mov ebx,0
	mov bl, 10h
	mov esi, offset val
	mov al,[esi] ; [esi] -> returning value at given address
	call DumpRegs
main ENDP
END main

; ARRAY (WAY 1)

.data 
	arrB BYTE 10h,20h,30h
.code 
main PROC
	mov esi,0
	mov eax,0
	mov esi, offset arrB
	mov al,[esi] ; returns 10h
	inc esi ; (+1 in address for 8 bit integers array), (+2 for 16 bit integers array), (+4 for 32 bit integers array)
	mov al,[esi] ; returns 20h
	call DumpRegs
main ENDP
END main

; INDEXED OPERANDS (array[ reg32 ]) -> ARRAY (WAY 2)
; reg32 can be any of the 32-bit general registers

.data 
	arrB BYTE 20h, 40h, 60h, 80h
.code 
main PROC
	mov esi, 0 
	mov eax, 0 
	mov esi, 1h
	mov al, arrB[esi] 
	inc esi 
	mov al, arrB[esi] 
	mov esi, 3 
	mov al, [arrB + esi]
	call DumpRegs
main ENDP
END main

;                                                            ******** EXERCISES ********

; TASK 1
.data
	val1 SDWORD 8000
.code
main PROC
	mov eax, 0
	mov eax, val1
	inc eax
	call DumpRegs
	exit
main ENDP ; Carry and sign flag are zero
END main

; TASK 4
.data
	arrayB BYTE 10h, 20h, 30h 
	arrayW WORD 150h, 250h, 350h
	arrayD DWORD 600h, 1200h, 1800h 
.code
main PROC
	mov eax,0
	mov esi,0h
	movzx eax,arrayB[esi]
	add eax,DWORD ptr arrayW[esi]
	add eax,arrayD[esi]
	mov eax,0
	movzx eax,arrayB[esi+1]
	add eax,DWORD ptr arrayW[esi+2]
	add eax,arrayD[esi+4]
	mov eax,0
	movzx eax,arrayB[esi+2]
	add eax,DWORD ptr arrayW[esi+4]
	add eax,arrayD[esi+8]
	call DumpRegs
	exit
main ENDP
END main
