## TASK 6

```asm
INCLUDE Irvine32.inc

.data
	SecondsInDay = 60*60*24 
.code
main PROC
	mov eax, SecondsInDay
	call WriteInt
	call DumpRegs
exit
main ENDP
END main
```

## OUTPUT:
![image](https://github.com/user-attachments/assets/9b653896-35e9-4fab-8231-763df13e730c)
