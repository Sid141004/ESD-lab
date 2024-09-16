

#include "LPC17xx.h"
int seven_seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};



int main(void)
{
	unsigned int i=0,j=0,m=0;
	int x;
	SystemInit();
	SystemCoreClockUpdate();
	
	
	LPC_PINCON->PINSEL0=0;
	LPC_PINCON->PINSEL3=0;
	LPC_GPIO0->FIODIR=0XFF<<4;
	LPC_GPIO1->FIODIR=0XF<<23;
	LPC_GPIO1->FIOPIN=0;//LSB
	while(1){
		x = LPC_GPIO0->FIOPIN;
		x = x & 1<<21;
		LPC_GPIO0->FIOPIN=seven_seg[i]<<4;
		if(x==0){
			i+=1;
			if(i==16){
				i=0;
			}
		}
		else{
			if(i==0){
				i=15;
			}
			i-=1;
		}
		for(j=0;j<5000000;j++);
	}
}
