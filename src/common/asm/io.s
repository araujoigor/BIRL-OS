section .text

 ; _outb - send a byte to an I/O port
 ; cdecl calling convention
 ; @param [esp + 8] - data - The data to be sent to the I/O port
 ; @param [esp + 4] - port - The I/O port to send the data to 
_outb:
    mov dx, [esp + 4]
    mov al, [esp + 8]
    out dx, al
    ret

; _inb - reads a byte from an I/O port
; cdecl calling convention
; @param [esp + 4] - port - The I/O port to read the data from
_inb:
    mov dx, [esp + 4]
    in al, dx
    ret