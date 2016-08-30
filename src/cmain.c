#include "drivers/include/framebuffer.h"

void cmain(){

  clear();

  setCursorPosition(0,0);
  write("Welcome to BIRL OS!", 19);

  setCursorPosition(2,0);
  write("Loading modules...", 18);
}