Include soac16.inc

.code
main PROC
    mov ax, @data
    mov ds, ax
                
    mov al, 10h ; 640x350 16
    call InitMode        
    
    mov cx, 200
    l0:
        mov dx, 100
        call PrintPX
    loop l0        
    
    mov ah,4Ch
    int 21h
main ENDP
END main