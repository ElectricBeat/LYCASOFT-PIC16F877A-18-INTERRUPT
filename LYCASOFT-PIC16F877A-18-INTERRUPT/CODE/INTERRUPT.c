#include <pic.h>
#include <htc.h>
#define _XTAL_FREQ 20e6
__CONFIG(0X3F3A);

void interrupt ISR()
{
	if(INTF==1)
	{
		RC1=~RC1;
		INTF=0;
	}
}

void main()
{
	TRISB=0X01;
	PORTB=0X00;
	TRISC=0X00;
	PORTC=0X00;

	INTCON=0X90;

   	while(1)
	{
		RC0=~RC0;
		__delay_ms(10);
   	}
}