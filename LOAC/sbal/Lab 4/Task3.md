## TASK 3

```asm
INCLUDE Irvine32.inc

.data
	varB BYTE +10
	varW WORD -150
	varD DWORD 600

.code
main PROC
	movsx eax, varB
	movsx ebx, varW
	mov ecx, varD
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT:
![image](https://github.com/user-attachments/assets/637ed63d-96fc-4db9-83de-90987509ebce)
