ENTRY(loader)               /* Sets the entrypoint as being the loader label */

SECTIONS {
    . = 1M;                 /* Our loader code should be place at the memory
                               location of 1MB or more */

    .text ALIGN (0x1000) :  /* sets a 4Kb alignment for the .text area */
    {
        *(.text)            /* places the .text section of all input files
                               in this output .text section */ 
    } 

    .rodata ALIGN (0x1000) :  /* sets a 4Kb alignment for the .rodata area */
    {
        *(.rodata*)            /* places the .rodata section of all input files
                               in this output .rodata section */ 
    } 

    .data ALIGN (0x1000) :  /* sets a 4Kb alignment for the .data area */
    {
        *(.data)            /* places the .data section of all input files
                               in this output .data section */ 
    } 

    .bss ALIGN (0x1000) :  /* sets a 4Kb alignment for the .bss area */
    {
        *(COMMON)          /* places the .COMMON and bss sections of all */
        *(.bss)            /* input files in this output .bss section */                                
    } 
}