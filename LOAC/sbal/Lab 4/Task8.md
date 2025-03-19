## TASK 8 (i)

```asm
INCLUDE Irvine32.inc
.data
	val1 BYTE 10h
	val2 WORD 8000h
	val3 DWORD 0FFFFh
	val4 WORD 7FFFh
.code
main PROC
	mov ax, val2
	inc ax
	mov val2, ax
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT 1:
![image](https://github.com/user-attachments/assets/089262e9-fe13-44f1-b825-1a11fbd842f8)

## (ii)

```asm
INCLUDE Irvine32.inc
.data
	val1 BYTE 10h
	val2 WORD 8000h
	val3 DWORD 0FFFFh
	val4 WORD 7FFFh
.code
main PROC
	mov eax, 9000h
	sub eax,val3
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT 2:
![image](https://github.com/user-attachments/assets/612a8d69-84a5-4116-a588-b6ace4f96b3f)

## (iii)

```asm
INCLUDE Irvine32.inc
.data
	val1 BYTE 10h
	val2 WORD 8000h
	val3 DWORD 0FFFFh
	val4 WORD 7FFFh
.code
main PROC
	mov ax, val2
	sub ax, val4
	mov val2, ax
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT 3:
![image](https://github.com/user-attachments/assets/7d7da1b6-5cb5-43f1-b36f-b144bcc08916)
