#include <18F4550.H>
#fuses HSPLL,PLL5,USBDIV,VREGEN,CPUDIV1,WRTB,PUT,NOWDT,NOPROTECT,NOPBADEN,MCLR
#use delay(clock=48000000)

void main (void)
{
   set_tris_b(0x00);//0000 0000
   while(TRUE)
   {
      output_high(PIN_B0);
      delay_ms(100);
      output_low(PIN_B0);
      delay_ms(100);
   }
}
