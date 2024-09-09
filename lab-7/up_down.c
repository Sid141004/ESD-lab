#include<lpc17xx.h>
int i=0;
int j;
int x;
//cnb-1->switch p2.12
int main(){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0=0;
	LPC_GPIO0->FIODIR=0XFF<<4;
	
	while(1){
		x = LPC_GPIO2->FIOPIN;
		x = x & 1<<12;
		if(x==0){
			LPC_GPIO0->FIOPIN=i<<4;
			i+=1;
			if(i==255){
				i=0;
			}
		}
		else{
			LPC_GPIO0->FIOPIN=i<<4;
			i-=1;
			if(i==0){
				i=255;
			}
		}
		for(j=0;j<1000000;j++);
	}
}
