#include <18f4550.h>
#fuses HSPLL,PLL5,USBDIV,VREGEN,CPUDIV1,PUT,MCLR,WRTB,NOWDT,NOPROTECT,NOPBADEN
#use delay(clock=48000000)
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7)

#define LED1 PIN_B0
#define LED2 PIN_B1
#define LED3 PIN_B2
#define LED4 PIN_B3

#byte portb = 0x0F81
//#locate dato=0x0005

void main(void)
{
   char Bdato = 0X00;
   set_tris_b(0x00);
   
   while(TRUE)
   {
     Bdato = getc();//TOMAR LOS DATOS QUE SE ENCUENTRAN EN MI BLUETOOTH
     
     switch (Bdato)
     {
         case 'Y':
             output_high(LED1); //PRENDER LED
             break;
         case 'Z':
             output_high(LED2); //PRENDER LED
             break;
         case 'L':
             output_high(LED3); //PRENDER LED
             break;
         case 'M':
             output_high(LED4); //PRENDER LED
             break;
             
             default :
             output_low(LED1);
             output_low(LED2);
             output_low(LED3);
             output_low(LED4);
     }
     
   }
}

