## TASK 2

```asm
INCLUDE irvine32.inc

.data
	val3 SDWORD -2147483647
.code
main PROC
	mov eax, val3
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT
![{7E578E87-4562-428A-A7A3-7415F8A4B4F3}](https://github.com/user-attachments/assets/a855bc94-170d-4fe1-8a38-5fbc9f5091c0)
