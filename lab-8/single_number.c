#include<lpc17xx.h>
int i=0;
int n=6;
int j;
int x;
int seven_seg[]= {0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
//cnb-1->switch p2.12
int main(){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0=0;
	LPC_PINCON->PINSEL3=0;
	LPC_GPIO0->FIODIRL= 0XFF0;
	LPC_GPIO1->FIODIR=0XF<<23;
	LPC_GPIO1->FIOPIN=0;
	while(1){
	LPC_GPIO0->FIOPIN= seven_seg[6] << 4;
	for(i=0;i<1000000;i++);
	}
}
