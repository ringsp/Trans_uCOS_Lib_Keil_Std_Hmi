/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2008                         */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Flash Programming Functions adapted                   */
/*               for Philips LPC2xxx 256kB Flash                       */
/*               using Flash Boot Loader with IAP                      */
/*                                                                     */
/***********************************************************************/

#include "FlashOS.H"        // FlashOS Structures
unsigned long base_adr;

// Memory Mapping Control
#define MEMMAP   (*((volatile unsigned char *) 0xE01FC040))

// Phase Locked Loop (PLL)
#define PLLCON   (*((volatile unsigned char *) 0xE01FC080))
#define PLLCFG   (*((volatile unsigned char *) 0xE01FC084))
#define PLLSTAT  (*((volatile unsigned short*) 0xE01FC088))
#define PLLFEED  (*((volatile unsigned char *) 0xE01FC08C))

#define M8(adr)  (*((volatile unsigned char  *) (adr)))
#define M16(adr) (*((volatile unsigned short *) (adr)))
#define M32(adr) (*((volatile unsigned long  *) (adr)))

#define STACK_SIZE     64      // Stack Size

#define SET_VALID_CODE 1       // Set Valid User Code Signature

/* VLSI�������ߣ�VPB����Ƶ�Ĵ��� */
#define VPBDIV          (*((volatile unsigned char *) 0xE01FC100))

union fsreg {                  // Flash Status Register
  struct b  {
    unsigned int q0:1;
    unsigned int q1:1;
    unsigned int q2:1;
    unsigned int q3:1;
    unsigned int q4:1;
    unsigned int q5:1;
    unsigned int q6:1;
    unsigned int q7:1;
  } b;
  unsigned int v;
} fsr;

extern unsigned long base_adr;
unsigned long CCLK;            // CCLK in kHz

struct sIAP {                  // IAP Structure
  unsigned long cmd;           // Command
  unsigned long par[4];        // Parameters
  unsigned long stat;          // Status
  unsigned long res;           // Result
} IAP;


/*
 * IAP Execute
 *    Parameter:      pIAP:  Pointer to IAP
 *    Return Value:   None (stat in IAP)
 */

void IAP_Execute (struct sIAP *pIAP);


/*
 * Get Sector Number
 *    Parameter:      adr:  Sector Address
 *    Return Value:   Sector Number
 */

unsigned long GetSecNum (unsigned long adr) {
  unsigned long n;

  n = (adr >> 13) & 0x1F;                      // Pseudo Sector Number
  if (n >= 24) {                               // High Small 8kB Sectors
    n -= 14;
  }
  else if (n >= 8) {                           // Large 64kB Sectors
    n  = 8 + (n >> 4);
  }

  return (n);                                  // Sector Number
}


/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

//CCLK /=  1000;                               // Clock Frequency in kHz
  CCLK  = (1049*(clk >> 10)) >> 10;            // Approximate (no Library Code)

//  PLLCON  = 0x00;                              // Disable PLL (use Oscillator)
//  PLLFEED = 0xAA;                              // Feed Sequence Part #1
//  PLLFEED = 0x55;                              // Feed Sequence Part #2

//  MEMMAP  = 0x01;                              // User Flash Mode

  return (0);
}

/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {
  return (0);
}


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseChip (void) {

  IAP.cmd    = 50;                             // Prepare Sector for Erase
  IAP.par[0] = 0;                              // Start Sector
  IAP.par[1] = 16;                             // End Sector
  IAP_Execute (&IAP);                          // Execute IAP Command
  if (IAP.stat) return (1);                    // Command Failed

  IAP.cmd    = 52;                             // Erase Sector
  IAP.par[0] = 0;                              // Start Sector
  IAP.par[1] = 16;                             // End Sector
  IAP.par[2] = CCLK;                           // CCLK in kHz
  IAP_Execute (&IAP);                          // Execute IAP Command
  if (IAP.stat) return (1);                    // Command Failed

  return (0);                                  // Finished without Errors
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {
  unsigned long n;

  n = GetSecNum(adr);                          // Get Sector Number

  IAP.cmd    = 50;                             // Prepare Sector for Erase
  IAP.par[0] = n;                              // Start Sector
  IAP.par[1] = n;                              // End Sector
  IAP_Execute (&IAP);                          // Execute IAP Command
  if (IAP.stat) return (1);                    // Command Failed

  IAP.cmd    = 52;                             // Erase Sector
  IAP.par[0] = n;                              // Start Sector
  IAP.par[1] = n;                              // End Sector
  IAP.par[2] = CCLK;                           // CCLK in kHz
  IAP_Execute (&IAP);                          // Execute IAP Command
  if (IAP.stat) return (1);                    // Command Failed

  return (0);                                  // Finished without Errors
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  unsigned long n;

#if SET_VALID_CODE != 0                        // Set valid User Code Signature
  if (adr == 0) {                              // Check for Interrupt Vectors
    n = *((unsigned long *)(buf + 0x00)) +     // Reset Vector
        *((unsigned long *)(buf + 0x04)) +     // Undefined Instruction Vector
        *((unsigned long *)(buf + 0x08)) +     // Software Interrupt Vector
        *((unsigned long *)(buf + 0x0C)) +     // Prefetch Abort Vector
        *((unsigned long *)(buf + 0x10)) +     // Data Abort Vector
        *((unsigned long *)(buf + 0x18)) +     // IRQ Vector
        *((unsigned long *)(buf + 0x1C));      // FIQ Vector
    *((unsigned long *)(buf + 0x14)) = 0 - n;  // Signature at Reserved Vector
  }
#endif

  n = GetSecNum(adr);                          // Get Sector Number

  IAP.cmd    = 50;                             // Prepare Sector for Write
  IAP.par[0] = n;                              // Start Sector
  IAP.par[1] = n;                              // End Sector
  IAP_Execute (&IAP);                          // Execute IAP Command
  if (IAP.stat) return (1);                    // Command Failed

  IAP.cmd    = 51;                             // Copy RAM to Flash
  IAP.par[0] = adr;                            // Destination Flash Address
  IAP.par[1] = (unsigned long)buf;             // Source RAM Address
  IAP.par[2] = 512;                           // Fixed Page Size
  IAP.par[3] = CCLK;                           // CCLK in kHz
  IAP_Execute (&IAP);                          // Execute IAP Command
  if (IAP.stat) return (1);                    // Command Failed

  return (0);                                  // Finished without Errors
}
int Initext (unsigned long adr, unsigned long clk, unsigned long fnc) {
  base_adr = adr;
/* ����ϵͳ������ʱ�� */
/* Set system timers for each component */
    PLLCON = 1;
    VPBDIV = 0;

    PLLCFG = 0;
    PLLFEED = 0xaa;
    PLLFEED = 0x55;
    while((PLLSTAT & (1 << 10)) == 0);
    PLLCON = 3;
    PLLFEED = 0xaa;
    PLLFEED = 0x55;
  return (0);
}
unsigned char WordProgram(unsigned long Addr, unsigned long Data) 
{
//  volatile unsigned short *ip;
  int i,j;
  for (i = 0; i < 2; i++)  
  {
    // Start Program Command
    M16(base_adr + (0x5555 << 1)) = 0xAA;
    for(j=0;j<500;j++)
    {
        ;
    }
    M16(base_adr + (0x2AAA << 1)) = 0x55;
    for(j=0;j<500;j++)
    {
        ;
    }
    M16(base_adr + (0x5555 << 1)) = 0xA0;
    for(j=0;j<500;j++)
    {
        ;
    }
    M16(Addr) = Data;
    Data = (Data>>16);
    if (Polling(Addr) != 0)
    { 
    return (1);
    }
    Addr += 2;
  }
    return (0);
}
 
/*
 * Check if Program/Erase completed
 *    Parameter:      adr:  Block Start Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int Polling (unsigned long adr) {
  unsigned int q6;

  // Check Toggle Bit
  do {
    fsr.v = M16(adr);
    q6 = fsr.b.q6;
    fsr.v = M16(adr);
  } while (fsr.b.q6 != q6);
  return (0);                  // Done
}
