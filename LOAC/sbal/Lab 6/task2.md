# TASK 2 (i)
```asm
INCLUDE Irvine32.inc

.code
main PROC
    mov eax, 1         
    mov ecx, 4  
    mov ebx, 1
L1:
    push ecx
    mov ecx, ebx
L2:
    call WriteInt
    loop L2
    call crlf
    inc ebx
    pop ecx
    loop L1
    exit
main ENDP
END main
```

# Output1:
![image](https://github.com/user-attachments/assets/f2da56ef-ca22-4d89-9c52-ba939ce09934)

# TASK 2 (ii)
```asm
INCLUDE Irvine32.inc

.code
main PROC
    mov eax, 1         
    mov ecx, 4  
    mov ebx, 4
L1:
    push ecx
    mov ecx, ebx
L2:
    call WriteInt
    loop L2
    call crlf
    dec ebx
    pop ecx
    loop L1
    exit
main ENDP
END main
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/b7e10f3c-70eb-47b4-b2d8-9351a4b01b88)

# TASK 2 (iii)
```asm
INCLUDE Irvine32.inc

.code
main PROC         
    mov ecx, 4  
    mov ebx, 4
    mov edx,4
L1:
    push ecx
    mov ecx, ebx
    mov eax,edx
L2:
    call WriteInt
    dec eax
    loop L2
    call crlf
    dec ebx
    ;dec edx
    pop ecx
    loop L1
    exit
main ENDP
END main
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/3096f74c-0d80-4f58-b8ae-839c096b73e5)

# TASK 2 (iv)
```asm
INCLUDE Irvine32.inc

.code
main PROC         
    mov ecx, 4  
    mov ebx, 4
    mov edx,1
L1:
    push ecx
    mov ecx, ebx
    mov eax,edx
L2:
    call WriteInt
    inc eax
    loop L2
    call crlf
    dec ebx
    ;dec edx
    pop ecx
    loop L1
    exit
main ENDP
END main
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/f27bda48-9c1b-4374-9d30-c021933aa4c7)
