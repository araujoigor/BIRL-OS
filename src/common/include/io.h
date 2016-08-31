#ifndef __IO_H__
#define __IO_H__

/**
 *  _outb - send a byte to an I/O port
 *   
 *  @param port The I/O port to send the data to
 *  @param data The data to be sent to the I/O port 
 */
 void _outb(unsigned short port, unsigned char data);

 /**
 *  _inb - reads a byte from an I/O port
 *   
 *  @param port The I/O port to send the data to 
 */
 char _inb(unsigned short port);

#endif //__IO_H__