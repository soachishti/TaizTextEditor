Include soac16.inc

.code
main PROC
    mov ax, @data
    mov ds, ax
                
    mov al, 10h ; 640x350 16
    call InitMode        
       
    mov dl, 60
    mov dh, 20
    call GetMeToXY
    
    mov al, 'b'
    call PrintChar      
    
    mov ah,4Ch
    int 21h
main ENDP
END main