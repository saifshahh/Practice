## TASK 4 (1)

```asm
INCLUDE Irvine32.inc

.data
	Val1 DWORD 25h
	Val2 BYTE 36o
	Val3 WORD 20d

.code
main PROC
	mov eax, 89
	add eax, 75Fh
	sub eax, 46o
	sub eax, 28
	add eax, 1101b
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT:
![image](https://github.com/user-attachments/assets/5e63fb5d-0324-439a-97e9-d29461f07430)

## (2)
```asm
INCLUDE Irvine32.inc

.data
	Val1 DWORD 25h
	Val2 BYTE 36o
	Val3 WORD 20d

.code
main PROC
	mov eax, Val1
	movzx ebx, Val2
	add eax, ebx
	sub eax, 654h
	movzx ebx, Val3
	add eax, ebx
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT:
![image](https://github.com/user-attachments/assets/5eb86559-77d3-434b-91d9-6581b89ef812)
