#include <18F4550.H>
#fuses HSPLL,PLL5,USBDIV,VREGEN,CPUDIV1,WRTB,PUT,NOWDT,NOPROTECT,NOPBADEN,MCLR
#use delay(clock=48000000)

#include <usb_bootloader.h> 

#byte porte= 0x0F84
#byte portb= 0x0F81

void main(void)
{
   set_tris_b(0x00);
   PORTB =0;
  
   while(TRUE)
   
  {
   portb =0B00000010;
   DELAY_MS(50);
   portb =0B00000000;
   DELAY_MS(50);
   
  }
}
