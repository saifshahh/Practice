```asm
INCLUDE Irvine32.inc

.data
    EID DWORD 5 DUP(?)
    Ename BYTE 5 DUP(30 DUP(?)) 
    Ebirth DWORD 5 DUP(?)
    Esalary DWORD 5 DUP(?)
    totalSalary DWORD ?

    qs1 BYTE "Enter your ID: ",0
    qs2 BYTE "Enter your name: ",0
    qs3 BYTE "Enter your DOB: ",0
    qs4 BYTE "Enter your salary: ",0
    qs5 BYTE "Total Annual Salary of All Employees: ", 0
.code
main PROC         
    mov ecx, 5  
    mov esi, 0
L1:
    mov edx,OFFSET qs1
    call WriteString
    call ReadInt
    mov EID[esi * 4],eax

    mov edx, OFFSET qs2
    call WriteString
    mov edx, OFFSET Ename
    mov eax, esi
    imul eax, 30
    add edx, eax
    call ReadString
    
    mov edx,OFFSET qs3
    call WriteString
    call ReadInt
    mov Ebirth[esi * 4],eax

    mov edx,OFFSET qs4
    call WriteString
    call ReadInt
    mov Esalary[esi * 4],eax

    add totalSalary,eax

    inc esi
    loop L1

    mov edx, OFFSET qs5
    call WriteString
    mov eax, totalSalary
    call WriteInt
exit
main ENDP
END main
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/575abe8b-3298-4c43-8814-2e20236e3541)
