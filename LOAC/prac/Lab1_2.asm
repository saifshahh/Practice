TITLE My First Program (Test.asm)   
INCLUDE Irvine32.inc   

; Task 1

;.code   
;main PROC   
	;mov eax, 47
;	add eax, 39
;	add eax, 60
;	add eax, 85
;	add eax, 64
 ;   add eax, 54
  ;  sub eax, 0Ah
	;call DumpRegs   
	;exit     
;main ENDP   
;END main   

; Task 2
;.code
;main PROC
;	mov eax, 101110b
;	add eax, 50Ah
;	add eax, 6710d
;	add eax, 1010001d
;	add eax, 0Fh
;	call DumpRegs
;	exit
;main ENDP
;END main

; Task 3
.code
main PROC
	mov eax,0
	mov ebx,0
	mov ecx,0
	mov edx,0
	add edx, eax
	add edx, 1
	add edx, ebx
	sub edx, ecx
	add edx, 0Ah
	sub edx, 65o
	add edx, 73d
	call DumpRegs
	exit
main ENDP
END main
