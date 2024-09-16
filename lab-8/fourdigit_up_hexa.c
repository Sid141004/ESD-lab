//hexa from 0 to FFFF

#include "LPC17xx.h"
int seven_seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};



int main(void)
{
	unsigned int i=0,j=0,n=0,count=0;
	int x;
	SystemInit();
	SystemCoreClockUpdate();
	
	
	LPC_PINCON->PINSEL0=0;
	LPC_PINCON->PINSEL3=0;
	LPC_GPIO0->FIODIR=0XFF<<4;
	LPC_GPIO1->FIODIR=0XF<<23;
	LPC_GPIO1->FIOPIN=0;//LSB
	while(1){
		int temp=n;
		if(count==100){
			n=(n+1)%10000;
			count=0;
		}
		for(i=0;i<=3;i++){
			LPC_GPIO1->FIOPIN=i<<23;
			LPC_GPIO0->FIOPIN=seven_seg[temp%16]<<4;
			temp/=16;
			for(j=0;j<50000;j++);
			count++;
		}
	}
}
