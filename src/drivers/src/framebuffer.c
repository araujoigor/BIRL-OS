//The number of columns in the framebuffer
#define COLUMN_COUNT    80

//The number of rows in the framebuffer
#define ROW_COUNT       25

//The start address of the framebuffer memory area
#define MEMORY_START    0x000B8000

//The framebuffer struct
//Each framebuffer cell is composed of 2 bytes:
//  1 byte for the letter (LSByte)
//  1 byte for the color (MSByte)
typedef struct {
    char letter;
    char color;
} __attribute__((packed)) framebuffer;

//The current cursor position.
unsigned int rowPos = 0;
unsigned int colPos = 0;

//The current color to be used
unsigned char color = 0xF0;

//A pointer to the framebuffer memory
framebuffer *fbPtr = (framebuffer *)MEMORY_START;

void putChar(char letter){
    fbPtr[rowPos * COLUMN_COUNT + colPos].color = color;
    fbPtr[rowPos * COLUMN_COUNT + colPos].letter = letter;
}

int setCursorPosition(char row, char col){
    if(col >= COLUMN_COUNT || row >= ROW_COUNT) return -1;
    rowPos = row;
    colPos = col;
    return 0;
}

void write(char *buffer, unsigned int len){
    int i = 0, j = 0;
    for(unsigned int bufIt = 0; bufIt < len; bufIt++){
        if(colPos + i >= 80){
            j++; i = 0;
        }
        fbPtr[(rowPos + j)*COLUMN_COUNT + colPos + i].letter = buffer[bufIt];
        fbPtr[(rowPos + j)*COLUMN_COUNT + colPos + i].color = color;
        i++;
    }
}

void clear(){
    int numberOfCells = 25*80;
    short *ptr = (short *)MEMORY_START;

    for(; ptr < (short*)(MEMORY_START) + numberOfCells; ptr++)
        *ptr = 0;
    
}