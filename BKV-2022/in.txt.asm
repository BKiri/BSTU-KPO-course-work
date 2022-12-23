.586
.model flat, stdcall
includelib userlib.lib
includelib kernel32.lib
includelib libucrt.lib

ExitProcess PROTO : DWORD
strl PROTO : DWORD
random PROTO : DWORD
outstr PROTO : DWORD
outbool PROTO : DWORD
outchar PROTO : DWORD
outuint PROTO : DWORD
outint PROTO : SDWORD
strcon PROTO : DWORD, : DWORD 
intToUint PROTO : SDWORD
uintToInt PROTO : DWORD
.stack 4096
.const
	overflow db 'ERROR: VARIABLE OVERFLOW', 0 
	null_division db 'ERROR: DIVISION BY ZERO', 0
	l0 SDWORD 5
	l1 SDWORD 0
	l2 BYTE 1
	l3 BYTE 0
	l4 BYTE 99
	l10 BYTE "Строка", 0
	l11 SDWORD 2
	l12 SDWORD 1
	l13 SDWORD 0
.data
	compareresult SDWORD 0
	funresult SDWORD 0
	mainb SDWORD 0
	maint BYTE 0
	mainf BYTE 0
	mainc BYTE 0
	mainone DWORD ?
	mainfunc SDWORD 0
.code

compare22_proc PROC, comparestr1 : DWORD, comparestr2 : DWORD
	pop ebx
	pop eax
	sub eax, ebx
	jo EXIT_OVERFLOW
	push eax
	pop compareresult
	push compareresult

	jmp EXIT
	EXIT_DIV_ON_NULL:
	push offset null_division
	call outstr
	push - 1
	call ExitProcess

	EXIT_OVERFLOW:
	push offset overflow
	call outstr
	push - 2
	call ExitProcess

	EXIT:
	pop eax
	ret 8

compare22_proc ENDP

fun1_proc PROC, funa : SDWORD
	push funa
	pop eax
	pop ebx
	add eax, ebx
	jo EXIT_OVERFLOW
	push eax
	push l0
	pop funresult
	push funresult

	jmp EXIT
	EXIT_DIV_ON_NULL:
	push offset null_division
	call outstr
	push - 1
	call ExitProcess

	EXIT_OVERFLOW:
	push offset overflow
	call outstr
	push - 2
	call ExitProcess

	EXIT:
	pop eax
	ret 4

fun1_proc ENDP

main PROC
	push l1
	pop mainb
	push offset l2
	pop dword ptr maint
	push offset l3
	pop dword ptr mainf
	push offset l4
	pop dword ptr mainc
	 mov mainone,offset l10
	push mainb
	call outint
	push dword ptr mainc
	call outchar
	push offset maint
	call outbool
	push dword ptr mainone
	call outstr
	pop mainfunc
	push l11
	pop mainb
	metkal12:
	push mainfunc
	call outint
	 pop l12
	push mainb
	pop eax
	pop ebx
	add eax, ebx
	jo EXIT_OVERFLOW
	push eax
	push l11
	pop ebx
	pop eax
	 cmp ebx, eax
	jb  metkal12

	jmp EXIT
	EXIT_DIV_ON_NULL:
	push offset null_division
	call outstr
	push - 1
	call ExitProcess

	EXIT_OVERFLOW:
	push offset overflow
	call outstr
	push - 2
	call ExitProcess

	EXIT:
	push 0
	call ExitProcess

main ENDP
end main