```asm
INCLUDE Irvine32.inc

.data
	arrayB BYTE 10, 20, 30
	arrayW WORD 150, 250, 350
	arrayD DWORD 600, 1200, 1800
	SUM1 DWORD ?
	SUM2 DWORD ?
	SUM3 DWORD ?
.code
main PROC
	mov esi, 0
	movzx eax, arrayB[esi * TYPE arrayB]
	movzx ebx, arrayW[esi * TYPE arrayW]
	add eax, ebx
	add eax, arrayD[esi * TYPE arrayD]
	mov SUM1, eax
	call WriteInt
	call crlf
	inc esi
	
	movzx eax, arrayB[esi * TYPE arrayB]
	movzx ebx, arrayW[esi * TYPE arrayW]
	add eax, ebx
	add eax, arrayD[esi * TYPE arrayD]
	mov SUM2, eax
	call WriteInt
	call crlf
	inc esi

	movzx eax, arrayB[esi * TYPE arrayB]
	movzx ebx, arrayW[esi * TYPE arrayW]
	add eax, ebx
	add eax, arrayD[esi * TYPE arrayD]
	mov SUM3, eax
	call WriteInt
	exit
main ENDP
END main
```

## OUTPUT:
![image](https://github.com/user-attachments/assets/bd84a187-60d9-4f4a-b8cc-d78850a57885)
