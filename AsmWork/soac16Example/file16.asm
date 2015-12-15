INCLUDE soac16.inc

.data
	file BYTE "data.txt",0
	fileW BYTE "data1.txt",0
	buffR BYTE 501 DUP(?)
	buffW BYTE "Syed Owais Ali Chishti", 0
.code
main PROC
	mov ax,@data
	mov ds,ax      ;these two lines required for 16-bit programs

	; Create new empty file
	invoke CreateFile, ADDR file
	
	; Reading from file
	invoke ReadFile, ADDR file, ADDR buffR, LENGTHOF buffR
	mov dx, OFFSET buffR
	call WriteString
	call Crlf

	; Writing in file
	invoke WriteFile, ADDR file, ADDR buffW, SIZEOF buffW
	mov dx, OFFSET buffW
	call WriteString
	call Crlf
	
	; Reading from file
	invoke ReadFile, ADDR file, ADDR buffR, LENGTHOF buffR
	mov dx, OFFSET buffR
	call WriteString		
	call Crlf
	
	;invoke DeleteFile, ADDR file
	
	exit
main ENDP
END main