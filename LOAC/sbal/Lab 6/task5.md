```asm
include irvine32.inc
.data
	arr DWORD 10,20,30,40,50
	qs BYTE "After reversal: ",0
	ans BYTE ", ",0
.code
main PROC
	mov ecx,lengthof arr/2
	mov esi,offset arr
	mov edi,offset arr+ sizeof arr - type arr
L1:
	mov eax,[esi]
	mov ebx,[edi]
	mov [esi],ebx
	mov [edi],eax
	add esi,type arr
	sub edi,type arr
	loop L1

	mov ecx,lengthof arr
	mov esi,0
	mov edx, OFFSET qs
	call WriteString
	call crlf
L2:
	mov eax,arr[esi]
	add esi,4
	call writedec
	mov edx,OFFSET ans
	call WriteString
	loop L2
exit  
main ENDP
END main
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/641c8525-027a-437c-887f-531d81847299)
