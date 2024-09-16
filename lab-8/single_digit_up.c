//p1.23 to p1.26 - i/p lines. p0.4 to p0.11 data lines

#include "LPC17xx.h"
int seven_seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
int i=0,j=0;

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0=0;
	LPC_PINCON->PINSEL3=0;
	LPC_GPIO0->FIODIR=0XFF<<4;
	LPC_GPIO1->FIODIR=0XF<<23;
	LPC_GPIO1->FIOPIN=0;//LSB
	while(1){
	for(i=0;i<16;i++){
		LPC_GPIO0->FIOPIN=seven_seg[i]<<4;
		for(j=0;j<8000000;j++);
	}
}
}
