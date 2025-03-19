## TASK 6

```asm
include irvine32.inc
.data
	a DWORD 00010001b
	b DWORD 00010000b
	x DWORD 00110000b
	d DWORD 01000000b
.code
main proc
	mov ebx, a
	add ebx, b
	sub ebx, a
	add ebx, b
	add ebx, x
	add ebx, d
	call DumpRegs
exit
main endp
end main
```

## OUTPUT
![{6F50ECE1-9B8E-426B-AEE7-2D930382CC94}](https://github.com/user-attachments/assets/282412e7-ad03-4b43-a547-ae5577433ef1)
