#include <18f4550.h>
#fuses HSPLL,PLL5,USBDIV,VREGEN,CPUDIV1,PUT,MCLR,WRTB,NOWDT,NOPROTECT,NOPBADEN
#use delay(clock=48000000)
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7)

#define LED1 PIN_B0

#byte portb = 0x0F81
//#locate dato=0x0005

void main(void)
{
   char dato = 0X00;
   set_tris_b(0x00);
   
   while(TRUE)
   {
     dato = getc();//TOMAR LOS DATOS QUE SE ENCUENTRAN EN MI BLUETOOTH
     
     if (dato == 'x')//EL DATO MANDADO DE APP INVENTOR DEL BOTON ON
         output_high(LED1); //PRENDER LED
         
     if (dato == 'z')//EL DATO ENVIADO DE APP INVENTOR DEL BOTON OFF
        output_low(LED1);//APAGAR LED
   }
}

