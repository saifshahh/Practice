```asm
INCLUDE Irvine32.inc

.data
    source BYTE "Raghib", 0
    target BYTE 6 DUP(?) 

.code
main PROC         
    mov ecx, LENGTHOF source
    mov esi, 0
L1:
    mov al, source[esi]
    mov target[esi], al
    inc esi
    loop L1

    mov ecx, LENGTHOF target
    mov esi, 0
output:
    mov al, target[esi]
    call WriteChar
    inc esi
    loop output

    exit
main ENDP
END main
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/2d8b9e08-0d38-41a1-9ffc-84a3bd80c1b0)
