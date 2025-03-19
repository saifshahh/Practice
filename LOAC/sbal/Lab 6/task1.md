```asm
include irvine32.inc
.code
main proc
	mov ecx, 10
	mov eax, 0
	mov ebx, 0
	call WriteInt
	mov eax, 1
	call WriteInt
	mov eax, 1
L1:
	mov edx,eax
	add eax,ebx
	mov ebx, edx
	CALL WriteInt
	loop L1
exit
main endp
end main
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/39532a20-f476-44c2-aaed-faf2b93822b3)
