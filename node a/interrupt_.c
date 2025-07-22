#include<lpc21xx.h>
#include"header.h"
extern unsigned int flag,flag1,flag2;
extern u8 c1,c2,c3;
extern CAN1 v1,v2,v3,v4;
extern int speed;
//IODIR=0xff;

/*timer interrupt*/
void Timer0_handler(void)__irq
{
 
 v1.byteA=speed;

 can1_tx(v1);

 //v2.byteA=ta;

 //can1_tx(v2);
 T0IR|=1;
 VICVectAddr=0;
}

void config_vic_for_timer0(void)
{

 VICIntSelect=0;
 VICIntEnable|=(1<<4);
 VICVectCntl0=4|(1<<5);
 VICVectAddr0=(int)Timer0_handler;
}

void config_timer0(void)
{
 T0PC=0;
 T0PR=15000000-1 ;
 T0TC=0;
 T0MCR=3;
 T0MR0=1;
 T0TCR=1;

}

//ext interrupt 0
void EINT0_Handler(void)__irq{
   flag^=1;
   if(flag)
   {
   v2.byteA=0x10;
   }
   else
	{
	v2.byteA=0x11;
	}
   can1_tx(v2);
   EXTINT|=1;
   VICVectAddr=0;
   }
void Config_vic_for_eint0(void){
VICIntSelect=0;
VICVectAddr1=(int)EINT0_Handler;
VICVectCntl1=14|(1<<5);
VICIntEnable|=(1<<14);
}
void Config_eint0(void)
{
PINSEL1|=1;	//p0.16
EXTMODE|=1;
EXTPOLAR|=0;
}
//ext interrupt 1
void EINT1_Handler(void)__irq{
   flag1^=1;
   if(flag1)
   {
   if(flag2)
  {
   flag2=0;
	v3.byteA=0x12;
	}
	else
		v3.byteA=0x12;
		
	}
	else
	{
	v3.byteA=0x13;
	}
	 can1_tx(v3);
   EXTINT|=2;
   VICVectAddr=0;
   }
void Config_vic_for_eint1(void){
VICIntSelect|=0;
VICVectAddr2=(int)EINT1_Handler;
VICVectCntl2=15|(1<<5);
VICIntEnable|=(1<<15);
}
void Config_eint1(void)
{
PINSEL0|=0x20000000;	//p0.14
EXTMODE|=2;
EXTPOLAR|=0;
}


//ext interrupt 2

 void EINT2_Handler(void)__irq{
   flag2^=1;
   if(flag2)
   {
   if(flag1)
   {
   flag1=0;
   v4.byteA=0x14;
   }
	 else
	v4.byteA=0x14;	 
   }
   else
   {
   v4.byteA=0x15;
   }
   can1_tx(v4);

   EXTINT|=4;
   VICVectAddr=0;
   }
void Config_vic_for_eint2(void){
VICIntSelect|=0;
VICVectAddr3=(int)EINT2_Handler;
VICVectCntl3=16|(1<<5);
VICIntEnable|=(1<<16);
}
void Config_eint2(void)
{
PINSEL0|=0x80000000;//p0.15
EXTMODE|=4;
EXTPOLAR|=0;
}
 

