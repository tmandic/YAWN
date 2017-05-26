/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "user.h"
#include "system.h"
//#include <pic16lf1459.h>

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Baseline devices don't have interrupts. Note that some PIC16's 
 * are baseline devices.  Unfortunately the baseline detection macro is 
 * _PIC12 */

void interrupt isr(void)
{
    /* This code stub shows general interrupt handling.  Note that these
    conditional statements are not handled within 3 seperate if blocks.
    Do not use a seperate if block for each interrupt flag to avoid run
    time errors. */

    
    /* TODO Add interrupt routine code here. */

    /* Determine which flag generated the interrupt */
    if(INTCONbits.IOCIF)
    {
        INTCONbits.IOCIF = 0;  
        if (IOCBFbits.IOCBF5 == 1) // switch A
        {                        
            IOCBFbits.IOCBF5 = 0; // clear flag                        
            if (MUSHROOM_ON == 0)
                {
                    SW = 5;
                }
            else
                {
                    SW = 1;
                }            
        }
        //if (IOCBFbits.IOCBF7 == 1) // switch B
        //{
        //    IOCBFbits.IOCBF7 = 0; // clear flag
        //    if (MUSHROOM_ON == 0)
        //        {SW = 6;}
        //    else
        //        {SW = 2;}
        //}              
    }
    // Timer0
    //if (INTCONbits.T0IF) 
    //{
    //    INTCONbits.T0IF = 0;        // clear flag   
    //    MUSHROOM_ON = 0;
    //    SW = 0;
    //}  
    //Timer1
    if (PIR1bits.TMR1IF) 
    {
        PIR1bits.TMR1IF = 0;        // clear flag           
        TMR_CNT = TMR_CNT + 1;
        if (TMR_CNT > 16)
        {
            INTCONbits.IOCIE = 0;       // Disable IOC Interrupts     
            MUSHROOM_ON = 0;
            SW = 0;            
        }      
    }    
}

  

