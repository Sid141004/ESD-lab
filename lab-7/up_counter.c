#include<lpc17xx.h>
int i;
int j;
int main(){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0=0;
	LPC_GPIO0->FIODIR=0XFF<<4;
	while(1){
		for(i=0;i <= 255; i++){
			LPC_GPIO0->FIOPIN=i<<4;
			for(j=0;j<1000000;j++);
		}
	}
}
