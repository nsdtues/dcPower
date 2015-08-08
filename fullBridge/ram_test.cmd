/*
//==========================================================
// FILE:    ram_test.cmd
//
// TITLE:   Linker Command File For 28335 examples that run out of RAM
*/
/* Define the memory block start/length for the F28335  

   PAGE 0 will be used to organize program sections
   PAGE 1 will be used to organize data sections
*/

MEMORY
{
PAGE 0 :
   
   BEGIN      : origin = 0x000000, length = 0x000002     /* Boot to M0 will go here                      */
   BOOT_RSVD  : origin = 0x000002, length = 0x00004E     /* Part of M0, BOOT rom will use this for stack */               
   RAMM0      : origin = 0x000050, length = 0x0003B0

   RAML0      : origin = 0x008000, length = 0x000500 
   RAML1      : origin = 0x008500, length = 0x006000 
    
   ZONE7A     : origin = 0x200000, length = 0x00FC00    /* XINTF zone 7 - program space */ 
   CSM_RSVD   : origin = 0x33FF80, length = 0x000076     /* Part of FLASHA.  Program with all 0x0000 when CSM is in use. */
   CSM_PWL    : origin = 0x33FFF8, length = 0x000008     /* Part of FLASHA.  CSM password locations in FLASHA            */
   ADC_CAL    : origin = 0x380080, length = 0x000009
   RESET      : origin = 0x3FFFC0, length = 0x000002
   IQTABLES   : origin = 0x3FE000, length = 0x000b50
   IQTABLES2  : origin = 0x3FEB50, length = 0x00008c
   FPUTABLES  : origin = 0x3FEBDC, length = 0x0006A0
   BOOTROM    : origin = 0x3FF27C, length = 0x000D44               

PAGE 1 : 
   RAMM1      : origin = 0x000400, length = 0x000400     

   RAML4      : origin = 0x00E500, length = 0x001B00    

   ZONE0      : origin = 0x004000, length = 0x001000     
   ZONE6      : origin = 0x100000, length = 0x100000     
   ZONE7B     : origin = 0x20FC00, length = 0x000400     
}
 
SECTIONS
{
   /* Setup for "boot to SARAM" mode: 
      The codestart section (found in DSP28_CodeStartBranch.asm)
      re-directs execution to the start of user code.  */
   codestart        : > BEGIN,     PAGE = 0
   ramfuncs         : > RAML0,     PAGE = 0  
/*   .text            : > ZONE7A,     PAGE = 0	*/

   .text            : > RAML1,     PAGE = 0 
   .cinit           : > RAML0,     PAGE = 0
   .pinit           : > RAML0,     PAGE = 0
   .switch          : > RAML0,     PAGE = 0
   
   .stack           : > RAMM1,     PAGE = 1
   .ebss            : > RAML4,     PAGE = 1
   .econst          : > RAML4,     PAGE = 1      
   .esysmem         : > RAMM1,     PAGE = 1

   IQmath           : > RAML1,     PAGE = 0
   IQmathTables     : > IQTABLES,  PAGE = 0, TYPE = NOLOAD 
   IQmathTables2    : > IQTABLES2, PAGE = 0, TYPE = NOLOAD 
   FPUmathTables    : > FPUTABLES, PAGE = 0, TYPE = NOLOAD 
      
   DMARAML4         : > RAML4,     PAGE = 1
   DMARAML5         : > RAML4,     PAGE = 1
   DMARAML6         : > RAML4,     PAGE = 1
   DMARAML7         : > RAML4,     PAGE = 1
   
   ZONE0DATA        : > ZONE0,     PAGE = 1  
   ZONE6DATA        : > ZONE6,     PAGE = 1  
   ZONE7DATA        : > ZONE7B,    PAGE = 1  
 
   .reset           : > RESET,     PAGE = 0, TYPE = DSECT /* not used                    */
   csm_rsvd         : > CSM_RSVD   PAGE = 0, TYPE = DSECT /* not used for SARAM examples */
   csmpasswds       : > CSM_PWL    PAGE = 0, TYPE = DSECT /* not used for SARAM examples */
   
   /* Allocate ADC_cal function (pre-programmed by factory into TI reserved memory) */
   .adc_cal     : load = ADC_CAL,   PAGE = 0, TYPE = NOLOAD
}
/* end of file */

