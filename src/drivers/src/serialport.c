#include "../../common/include/io.h"

#define BASE_BAUD_RATE              115200

#define BIOS_COM_PORTS_ADDR         0x0400;

#define DATA_PORT(baseAddr)         (baseAddr)
#define FIFO_CTRL_PORT(baseAddr)    (baseAddr + 2)
#define LINE_CTRL_PORT(baseAddr)    (baseAddr + 3)
#define MODEM_CTRL_PORT(baseAddr)   (baseAddr + 4)
#define LINE_STATUS_PORT(baseAddr)  (baseAddr + 5)
#define MODEM_STATUS_PORT(baseAddr) (baseAddr + 6)
#define SCRATCH_PORT(baseAddr)      (baseAddr + 7)

#define LINE_ENABLE_DLAB            0x80

//Disables DLAB and set the control line with 
//no parity and one stop bit
#define LINE_DISABLE_DLAB           0x03

short sp_getComFd(int comNumber){
    return (comNumber > 3) ? -1 :
        *((short *)0x0400 + comNumber);
}

void sp_setBaudRate(short comFd, int baudRate){
    if(comFd < 0 || !baudRate || BASE_BAUD_RATE % baudRate) return;

    short baudRateDivisor = BASE_BAUD_RATE / baudRate;

    _outb(LINE_CTRL_PORT(comFd), LINE_ENABLE_DLAB);
    _outb(DATA_PORT(comFd), baudRateDivisor >> 8 & 0x00FF);
    _outb(DATA_PORT(comFd), baudRateDivisor & 0xFF);

    _outb(LINE_CTRL_PORT(comFd), LINE_DISABLE_DLAB);
}

void sp_init(short comFd, int baudRate){
    if(comFd < 0) return;

    sp_setBaudRate(comFd, baudRate);

    _outb(FIFO_CTRL_PORT(comFd), 0xC7);
    _outb(MODEM_CTRL_PORT(comFd), 0x03);
}

char sp_canWrite(short comFd){
    return _inb(LINE_STATUS_PORT(comFd)) & 0x20;
}

char sp_canRead(short comFd){
    return _inb(LINE_STATUS_PORT(comFd)) & 1;
}

char sp_readByte(short comFd){
    if(!sp_canRead(comFd)) return -1;
    return _inb(DATA_PORT(comFd));
}

char sp_read(short comFd, char *buf, int len){
    if(!sp_canRead(comFd)) return -1;
    
    while(len){
        *buf = sp_readByte(comFd);
        buf++; len--;
    }

    return 1;
}

char sp_write(short comFd, char *buf, unsigned int len){
    if(!sp_canWrite(comFd)) return -1;
    
    while(len){
        _outb(DATA_PORT(comFd), *buf);
        buf++; len--;
    }

    return 1;
}