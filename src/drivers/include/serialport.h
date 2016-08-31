short sp_getComFd(int comNumber);
void sp_setBaudRate(short comFd, int baudRate);
void sp_init(short comFd, int baudRate);
char sp_canWrite(short comFd);
char sp_canRead(short comFd);
char sp_readByte(short comFd);
char sp_read(short comFd, char *buf, int len);
char sp_write(short comFd, char *buf, unsigned int len);