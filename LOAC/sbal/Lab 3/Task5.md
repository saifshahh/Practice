## TASK 5

```asm
INCLUDE irvine32.inc

.data
	a DWORD 11h
	b DWORD 10h
	x DWORD 30h
	d DWORD 40h
.code 
main PROC
	mov eax,a
	add eax,b
	mov ecx,a
	sub ecx,b
	mov ebx, eax
	sub ebx,ecx
	add ebx,x
	add ebx,d
	call DumpRegs
	exit
main ENDP
END main
```

## OUTPUT
![{4FCC09DF-CB75-445C-892E-A63DC580F6C4}](https://github.com/user-attachments/assets/740ab270-e79e-4f97-8148-86ea01c1f28e)
