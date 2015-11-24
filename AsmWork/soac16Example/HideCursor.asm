Include irvine16.inc
Include soac16.inc
.code
main PROC
    mov ax, @data
    mov ds, ax
        
    mov al, 10h ; 640x350 16
    call InitMode        
    
    ;call ShowCursor
    call HideCursor
        
    mov ah,4Ch
    int 21h
main ENDP
END main