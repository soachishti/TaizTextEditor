Include Irvine16.inc
Include MACROS.inc

.code
InitMode PROC
    ;mov al, 10h
    mov ah, 0
    int 10h
    ret
InitMode ENDP

PrintPX PROC USES ax bx
    mov ah, 0Ch
    mov al, 15       ; Color 0-16
    mov bh, 0        ; video page
    ;mov cx, 10      ; x_coord
    ;mov dx, 10      ; y_coord
    int 10h
    ret
PrintPX ENDP

PrintChar PROC
    mov ah, 9
    ;mov al, 'A'
    mov bh, 0
    mov bl, 0fh
    mov cx, 1
    int 10h
    ret
PrintChar ENDP

HideCursor PROC
    mov ah, 3
    int 10h
    or ch, 30h
    mov ah, 1
    int 10h
    ret
HideCursor ENDP

ShowCursor PROC
    mov ah, 1
    mov cx, 0607h
    int 10h
    ret
ShowCursor ENDP

GetMeToXY PROC
    mov ah, 2
    ;mov dh, 10  ; row
    ;mov dl, 20  ; columns
    mov bh, 0
    int 10h
    ret
GetMeToXY ENDP

WhereIsXY PROC
    mov ah, 3h
    mov bh, 0
    int 10h
    ;return in dh (x), dl(y)
    ret
WhereIsXY ENDP

PrintString PROC loc:WORD
    mov si, loc
    l0:
        cmp BYTE PTR [si], 0
        je return
        mov al, [si]
        call PrintChar
        inc si
        call WhereIsXY
        inc dl
        call GetMetoXY
    jmp l0
    return:
    ret
PrintString ENDP

clear PROC
    mov ax, 0600h
    mov cx, 0
    mov dx, 184Fh
    mov bh, 7
    int 10h
    
    mov ah, 2
    mov bh, 0
    mov dx, 0
    int 10h
clear ENDP

ReadPX PROC
    mov ah, 0Dh
    mov bh, 0
    ;mov cx, 100  ;x
    ;mov dx, 100  ;y
    int 10h
    ; result in al
    ret
ReadPX ENDP

VerticalLine PROC
    l0:
        call PrintPX
        dec dx
        dec ax
    cmp ax, 0
    jg l0
    ret
VerticalLine ENDP

HorizontalLine PROC
    l0:
        call PrintPX
        inc cx
        dec ax
    cmp ax, 0
    jg l0
    ret
HorizontalLine ENDP

Square PROC x:WORD, y:WORD, s:WORD
    mov ax, s     ; loop
    mov cx, x       ; x
    mov dx, y       ; y
    call HorizontalLine
    
    mov ax, s      ; loop
    mov cx, x       ; cx = x
    mov dx, y       ; y
    call VerticalLine
    
    mov ax, s      ; loop
    mov cx, x       ; x
    mov dx, y       ; y
    add cx, s
    call VerticalLine
    
    mov ax, s      ; loop
    mov cx, x       ; x
    mov dx, y       ; y
    sub dx, s
    call HorizontalLine
    
    ret
Square ENDP

ScrollUp PROC 
    mov ah, 6h  ; scroll window up
    mov al, 0   ; entire window
    mov ch, 0   ; upper left row
    mov cl, 0   ; upper left column
    mov dh, 24  ; lower right row
    mov dl, 79  ; lower right column
    mov bh, 7   ; attribute for blanked area
    int 10h
    ret
ScrollUp ENDP

ScrollDown PROC 
    mov ah, 7h   ; scroll window up
    mov al, 0   ; entire window
    mov ch, 0   ; upper left row
    mov cl, 0   ; upper left column
    mov dh, 24  ; lower right row
    mov dl, 79  ; lower right column
    mov bh, 7   ; attribute for blanked area
    int 10h
    ret
ScrollDown ENDP

; Reference http://fleder44.net/312/notes/16Files/Index.html
; Reference http://jlp.freeservers.com/files/
CreateFile PROC, fileName:PTR BYTE
	mov ah,3Ch 
    mov cx,00000000b 
    mov dx, fileName
    int 21h 
    jc quit
	; Just close it for now. May causing performance issue.
	mov bx,ax
	mov ah,3Eh
	int 21h
	ret
quit:
	mWrite "Write Failed"
	ret
CreateFile ENDP

ReadFile PROC, fileName:PTR BYTE, buffer:PTR BYTE, bufferSize:WORD
	LOCAL fileHandle:WORD
	;; open an input file for reading
	mov ah,3Dh
	mov al,0
	mov dx, fileName
	int 21h
	; Error occur if CF is set
	jc quit
	mov fileHandle,ax
	
	; read from the file
	mov ah, 3Fh
	mov bx, fileHandle
	mov cx, bufferSize
	mov dx, buffer
	int 21h
	jc quit
	
	;close the file
	mov ah,3Eh
	mov bx,fileHandle
	int 21h
	ret
quit:
	mWriteLn "Read file Failed"
	ret
ReadFile ENDP

WriteFile PROC, fileName:PTR BYTE, buffer:PTR BYTE, bufferSize:WORD
	LOCAL fileHandle:WORD
	; open an input file for reading
	mov ah,3Dh
	mov al,1	; 0 Read, 1 Write, 2 Read/Write
	mov dx, fileName
	int 21h
	; Error occur if CF is set
	jc quit
	mov fileHandle,ax
	
	; Write in file
	mov ah,40h 
    mov bx, fileHandle
    mov cx, bufferSize
    mov dx, buffer 
    int 21h 
    jc quit
	
	;close the file
	mov ah,3Eh
	mov bx,fileHandle
	int 21h
	ret
quit:
	mWriteLn "Write failed"
	ret
WriteFile ENDP

DeleteFile PROC, fileName:PTR BYTE
    mov ah,41h 
    lea dx, fileName
    int 21h 
    jc quit
quit:
	mWriteLn "Delete file failed"
	ret
DeleteFile ENDP

; Derived from irvine16.inc
startup MACRO
    mov  ax,@data
    mov  ds,ax
ENDM

.LIST