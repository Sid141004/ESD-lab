#include "LPC17xx.h"
int seven_seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};



int main(void)
{
	unsigned int row=0,col=0,keycode=0,count=0,i=0,j=0;
	int x;
	SystemInit();
	SystemCoreClockUpdate();
	
	
	LPC_PINCON->PINSEL0=0;
	LPC_PINCON->PINSEL1=0;
	LPC_PINCON->PINSEL3=0;
	LPC_PINCON->PINSEL4=0;
	LPC_GPIO0->FIODIR=0X78FF0;//FOR P0.
	LPC_GPIO1->FIODIR=0;//I/P FOR COLS
	LPC_GPIO2->FIOPIN=0XF<<10;//O/P FOR ROWS
	
	while(1){
		for(row = 0; row<4; row++){
			LPC_GPIO2->FIOPIN = 1 << (10 + row );
			for(j=0;j<100;j++);
			x = LPC_GPIO1->FIOPIN;
			x = (x>>23) & 0xF;
			if(x!=0){
				if ( x == 1){
					col=0;
				}else if( x == 2){
					col=1;
				}else if( x == 4){
					col=2;
				}else if(x == 8){
					col=3;
				}
			
				//row=0;col=0;
				keycode = 4*row + col;
				}
				LPC_GPIO0->FIOMASK=0x78000;
				LPC_GPIO0->FIOPIN=seven_seg[keycode]<<4;
				for(i=0;i<10000000;i++);
			
		}	
	}
}
