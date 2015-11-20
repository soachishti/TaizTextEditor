Include Irvine16.inc

.code
main PROC
	mov ax, @data
	mov ds, ax
	call DumpRegs
	
	exit
main ENDP
END main