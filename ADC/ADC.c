#include <18F4550.H>
#device adc=8 //10 quiere decir que es de 10bits
#fuses HSPLL,PLL5,USBDIV,VREGEN,CPUDIV1,WRTB,PUT,NOWDT,NOPROTECT,NOPBADEN,MCLR
#use delay(clock=48000000)



#byte porta= 0x0F80
#byte portb= 0x0F81
#byte portc= 0x0F82
#byte portd= 0x0F83
#byte porte= 0x0F84

int8 dato;
void main(void)
{
   /////configuracion de adc
    setup_adc(ADC_CLOCK_DIV_64);//VELOCIDAD DE CONVERCION
    setup_adc_ports(AN0);
    set_adc_channel(0); 
   
   //configuracion de entradas/salidas
    set_tris_b(0X00);//0 out ...  1 in 0000 0000 --> b7 b6 b5 .. b0
    
   while(TRUE)
   {
      delay_us(1000);
      dato = read_adc();
      
      portb = dato;
   }
}
