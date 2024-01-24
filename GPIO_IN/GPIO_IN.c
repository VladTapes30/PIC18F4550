#include <18F4550.H>
#fuses HSPLL,PLL5,USBDIV,VREGEN,CPUDIV1,WRTB,PUT,NOWDT,NOPROTECT,NOPBADEN,MCLR
#use delay(clock=48000000)

//#include <bootloader.h>
#byte porta= 0x0F80 //0000 1111 1000 0100
#byte portb= 0x0F81
#byte portc= 0x0F82
#byte portd= 0x0F83
#byte porte= 0x0F84

void main(void)
{
  // set_tris_b(0x00);//si 1 son entradas, 0 salidas//0000 0000
   PORTB = 0;//0 esta apagado 1 esta prendido
   
   while(TRUE)
   {
        if (input(PIN_B1))//estado del pin
        {
            output_high(PIN_B0);//prender
            DELAY_MS(500);
        }
        else
        {
           output_low(PIN_B0);//apagar
           DELAY_MS(500);  
        }
       
   }
}
