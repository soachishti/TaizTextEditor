Include soac16.inc
.code
main PROC
    mov ax, @data
    mov ds, ax
    mov al, 10h 	; 640x350 16 colors
    call InitMode        

	mov al, 'A'
	call PrintChar 
	mov al, 'B'
	call PrintChar 	; Print in same place ERROR
    	
	mov ah, 4Ch
    int 21h
main ENDP
END main
