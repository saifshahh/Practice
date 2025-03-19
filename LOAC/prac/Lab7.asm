;Example: displays the product of three integers through a stack

INCLUDE Irvine32.inc

.data
    mult WORD 2h
.code
main PROC
    mov eax, 0
    mov ecx, 3
    L1:
        push mult
        add mult, 2
    loop L1
    mov ecx, 3
    L2:
        pop eax
        mul eax
        call WriteHex
        call crlf
        mov eax, 0
    loop L2
    exit
main ENDP
END main

;Example: To find the largest number through a stack 

INCLUDE Irvine32.inc

.data
    mult WORD 2h
.code
main PROC
    push 1h
    push 3h
    push 7h
    push 5h
    mov eax, 0
    mov edx, 0
    mov ecx, 4
    L1:
        pop edx
        cmp edx, eax
        JL SET
        mov eax, edx
        SET:
    loop L1
    exit
main ENDP
END main

; FUNCTION CALL

INCLUDE Irvine32.inc

.data
    var1 DWORD 5
    var2 DWORD 6
.code
main PROC
    call AddTwo
    call WriteInt
    call crlf
    exit
main ENDP

AddTwo PROC
    mov eax, var1
    mov ebx, var2
    add eax, ebx
    ret
AddTwo ENDP

END main
