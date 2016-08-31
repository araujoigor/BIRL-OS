#include "drivers/include/framebuffer.h"
#include "drivers/include/serialport.h"

void cmain(){

  short com0 = sp_getComFd(0);
  
  sp_init(com0, 115200);
  sp_write(com0, "BIRL OS is in control\n", 22);
  sp_write(com0, "Starting subsystems...", 22);

  fb_clear();

  fb_setCursorPosition(0,0);
  fb_write("Welcome to BIRL OS!", 19);

  fb_setCursorPosition(2,0);
  fb_write("Loading modules...", 18);

}