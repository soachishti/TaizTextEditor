Include soac16.inc

.code
main PROC
    mov ax, @data
    mov ds, ax
                
    mov al, 10h ; 640x350 16
    call InitMode        
       
    invoke Square, 200, 300, 200       
        
    mov ah,4Ch
    int 21h
main ENDP
END main