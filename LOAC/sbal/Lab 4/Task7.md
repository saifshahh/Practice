## TASK 7

```asm
INCLUDE Irvine32.inc

.data
	A DWORD 0FF10h
	B DWORD 0E10Bh
.code
main PROC
	mov eax, A
	XCHG eax, B
	mov A, eax
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT:
![image](https://github.com/user-attachments/assets/fe09bb26-63d4-4b0b-9885-a89927a04a99)
