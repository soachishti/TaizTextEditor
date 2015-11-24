Include soac16.inc
.data 
    str1    BYTE    "Owais", 0
.code
main PROC
    mov ax, @data
    mov ds, ax
        
    mov al, 10h ; 640x350 16
    call InitMode        

    invoke PrintString, OFFSET str1
    
    mov ah,4Ch
    int 21h
main ENDP
END main