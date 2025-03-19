## TASK 3

```asm
INCLUDE irvine32.inc

.data
	list WORD 1h,2h,3h
.code
main PROC
	mov ax, [list]
	mov bx, [list+2]
	mov cx, [list+4]
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT
![{8A017B86-C0CE-4D43-B31E-7F99C18447FA}](https://github.com/user-attachments/assets/885c708b-f649-44f8-8490-5859a44c49e8)
