#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__

/**
  * putChar
  * 
  * Method to place a single character on the current
  * cursor position
  *
  * @param letter {char} The character to be included 
  */
void fb_putChar(char letter);

/**
  * setCursorPosition
  * 
  * Method to the change the cursor position
  *
  * @param col {char} The new column number (0 to 79)
  * @param row {char} The new row number (0 to 24)
  */
void fb_setCursorPosition(char col, char row);

/**
  * write
  * 
  * Write a buffer content to the framebuffer
  *
  * @param buffer {char *} The source buffer to be shown on screen
  * @param row {char} The number of bytes to be shown from the buffer
  */
void fb_write(char *buffer, unsigned int len);

/**
  * write
  * 
  * Clears the framebuffer
  */
void fb_clear();

#endif