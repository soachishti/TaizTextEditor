Include soac16.inc

.code
main PROC
    mov ax, @data
    mov ds, ax
                
    mov al, 10h ; 640x350 16
    call InitMode        
       
    mov ax, 640     ; loop
    mov cx, 0       ; x
    mov dx, 175     ; y
    call HorizontalLine
    
    mov ax, 350     ; loop
    mov cx, 320     ; x
    mov dx, 350     ; y
    call VerticalLine                   
        
    mov ah,4Ch
    int 21h
main ENDP
END main