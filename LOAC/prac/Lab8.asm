INCLUDE Irvine32.inc

; Finds the smallest of the three integers

.data
    var1 DWORD 50          
    var2 DWORD 25          
    var3 DWORD 103         
    final DWORD ?          

.code
main PROC
    mov eax, var1         
    mov ebx, var2          
    mov esi, var3          

    cmp eax, ebx           
    jl SETEAX              
    mov edx, ebx          
    jmp COMPARE_ESI       
SETEAX:
    mov edx, eax           

COMPARE_ESI:
    cmp edx, esi          
    jl FINALIZE
    mov edx, esi         
FINALIZE:
    mov final, edx        

    call DumpRegs         
    call Exit             
main ENDP
END main


; Whether they are equal or not

.data
	var1 BYTE 10h
	var2 BYTE 20h
	var3 BYTE 20h
	var4 BYTE 30h
	MsgYes WORD "THEY ARE EQUAL", 0
	MsgNo WORD "THEY ARE NOT EQUAL", 0
.code
main PROC
	mov eax, var1
	cmp eax, var2
	JNE NotEqual

	cmp eax, var3
	JNE NotEqual

	cmp eax, var4
	JNE NotEqual

	lea edx, MsgYes ; lea stores address
	call WriteString
	jmp ExitProgram

NotEqual:
	lea edx, MsgNo
	call WriteString

ExitProgram:
	call exit
	
main ENDP
END main

; find the first non-zero value in the given array

.data
	arr BYTE 0, 0, 0, 150, 120, 35, -12, 66, 4, 0
	msg WORD "FOUND", 0
	msgNotFound BYTE "NOT FOUND", 0 
.code
main PROC
	mov esi, OFFSET arr
	mov ecx, LENGTHOF arr
L1:
	cmp [esi], 0
	JNE SET
	inc esi
	loop L1

	lea edx, msgNotFound
    call WriteString
    jmp ExitProgram
	
SET:
	lea edx, msg
	call WriteString
	jmp EXITPROGRAM

EXITPROGRAM:
	call exit

call exit
main ENDP
END main

; USING AND OPERATOR

.data
	var1 DWORD 5
    X DWORD ?          
.code
main PROC
	mov ecx, 10
	mov edx, 6
	mov eax, var1

	cmp eax, ecx
	JL CMP1
	mov X, 1
	jmp CONTINUE

CMP1:
	cmp ecx, edx
	JGE SET

SET:
	mov X, 0

CONTINUE:
    call exit

main ENDP
END main

; TAKING INPUT FROM USER

.data
    num1 DWORD ? 
    num2 DWORD ? 
    msg BYTE "Enter a Number: ", 0
    msgEqual BYTE "All integers are equal.", 0
    msgNotEqual BYTE "Integers are not equal.", 0
.code
main PROC
    lea edx, msg
    call WriteString
    call ReadInt
    mov num1, eax

    lea edx, msg
    call WriteString
    call ReadInt
    mov num2, eax

    mov eax, num1
    cmp eax, num2
    JNE NOTFOUND

    lea edx, msgEqual
    call WriteString
    jmp ExitProgram

NOTFOUND:
    lea edx, msgNotEqual
    call WriteString

ExitProgram:
    call exit

main ENDP
END main

; If the given Character is Alphabet or Not

.data
    character DWORD ?
    msg BYTE "Write a character: ",0
    Notalpha BYTE "Not an alphabet!"
    alpha BYTE "It is an alphabet!"
.code
main PROC
    lea edx, msg
    call WriteString
    call ReadChar
    mov character, eax

    mov eax, character
    cmp eax, 'A'
    JL NotChar
    cmp eax, 'Z'
    JLE Char

    cmp eax, 'a'
    JL NotChar
    cmp eax, 'z'
    JLE Char

NotChar:
    lea edx, Notalpha
    call WriteString
    jmp Ex

Char:
    lea edx, alpha
    call WriteString

Ex:
    call exit
main ENDP
END main
