//C Program to do the following - Varying intensity using Row 0 of Matrix Keyboard.

/* Intensity Level         Key Pressed
        10%                    0
        25%                    1
        50%                    2
        75%                    3
*/

#include<LPC17xx.h>

void initpwm(void);
void updatepulsewidth(unsigned int pulsewidth);
void delayms(unsigned int milliseconds);
int scan(void);
unsigned int temp3;
int pulsewidth[]={0,2500,5000,10000};
int dir=0;

int main(void)
{
    LPC_GPIO0->FIODIR = 0xf00;
    initpwm();
    while(1)
    {
        int count=scan();
        if(count==0x1)
            updatepulsewidth(pulsewidth[0]);
        else if(count==0x2)
            updatepulsewidth(pulsewidth[1]);
        else if(count==0x4)
            updatepulsewidth(pulsewidth[2]);
        else if(count==0x8)
            updatepulsewidth(pulsewidth[3]);
        delayms(10000);
    }

}

void initpwm(void)
{
    LPC_PINCON->PINSEL3|=0x8000;
    LPC_PWM1->PCR=0x1000;
    LPC_PWM1->PR=0;
    LPC_PWM1->MR0=10000;
    LPC_PWM1->MCR=2;
    LPC_PWM1->LER=0xff;
    LPC_PWM1->TCR=0x2;
    LPC_PWM1->TCR=0x9;
}

void updatepulsewidth(unsigned int pulsewidth)
{
    LPC_PWM1->MR4=pulsewidth;
    LPC_PWM1->LER=0xff;
}

void delayms(unsigned int milliseconds)
{
    LPC_TIM0->CTCR=0x0;
    LPC_TIM0->PR=2;
    LPC_TIM0->TCR=0x02;
    LPC_TIM0->TCR=0x1;
    while(LPC_TIM0->TC<milliseconds);
    LPC_TIM0->TCR=0;
}

int scan(void)
{
    LPC_GPIO0->FIOSET = 0x100;
    temp3 = LPC_GPIO0->FIOPIN;
    temp3 &= 0xf0;
    if(temp3!=0)
        return temp3>>4;
    return 1;
}






#include <LPC17xx.H>
void pwm_init(void);
void PWM1_IRQHandler(void);
unsigned long int i;
unsigned char flag,flag1;
int main(void)
{
SystemInit();
SystemCoreClockUpdate();
pwm_init();
while(1)
{
for(i=0;i<=1000;i++); // delay
}//end of while
}//end of main
void pwm_init(void)
{
LPC_SC->PCONP |= (1<<6); //PWM1 is powered
LPC_PINCON->PINSEL3 &= ~(0x0000C000); //cleared if any other
//functions are enabled
LPC_PINCON->PINSEL3 |= 0x00008000; //pwm1.4 is selected for the pin
//P1.23
//LPC_PWM1->PR = 0x00000000; //Count frequency : Fpclk
LPC_PWM1->PCR = 0x00001000; //select PWM1 single edge
LPC_PWM1->MCR = 0x00000003; //Reset and interrupt on PWMMR0
LPC_PWM1->MR0 = 30000; //setup match register 0 count
LPC_PWM1->MR4 = 0x00000100; //setup match register MR1
LPC_PWM1->LER = 0x000000FF; //enable shadow copy register
LPC_PWM1->TCR = 0x00000002; //RESET COUNTER AND PRESCALER
LPC_PWM1->TCR = 0x00000009; //enable PWM and counter
NVIC_EnableIRQ(PWM1_IRQn);
return;
}
void PWM1_IRQHandler(void)
{
LPC_PWM1->IR = 0xff; //clear the interrupts
if(flag == 0x00)
{
LPC_PWM1->MR4 += 100;
LPC_PWM1->LER = 0x000000FF;
if(LPC_PWM1->MR4 >= 27000)
{
flag1 = 0xff;
flag = 0xff;
LPC_PWM1->LER = 0x000000fF;
}
}
else if(flag1 == 0xff)
{
LPC_PWM1->MR4 -= 100;
LPC_PWM1->LER = 0x000000fF;
if(LPC_PWM1->MR4 <= 0x500)
{
flag = 0x00;
flag1 = 0x00;
LPC_PWM1->LER = 0X000000fF;
}
}
}
