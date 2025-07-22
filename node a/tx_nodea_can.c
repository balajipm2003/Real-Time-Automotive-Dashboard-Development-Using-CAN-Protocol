#include<lpc21xx.h>
#include"header.h"
int speed;
//int vout,ta;
CAN1 v1,v2,v3,v4;
//u8 c1=0,c2=0,c3=0;
unsigned int flag=0,flag1=0,flag2=0;

int main()
{
unsigned int adc_val1;
//unsigned int adc_val2;
//int vout,ta;
//int speed;

can1_init();

adc_init();

config_timer0();
config_vic_for_timer0();


Config_eint0();
Config_vic_for_eint0();

Config_eint1();
Config_vic_for_eint1();

Config_eint2();
Config_vic_for_eint2();

v1.id=0x055;
v1.rtr=0;
v1.dlc=4;

//v2.id=0x100;
//v2.rtr=0;
//v2.dlc=4;

v2.id=0x201;
v2.rtr=0;
v2.dlc=4;

v3.id=0x202;
v3.rtr=0;
v3.dlc=4;

v4.id=0x203;
v4.rtr=0;
v4.dlc=4;

while(1)
{

adc_val1=adc_read(2);
//adc_val2=adc_read(1);

speed=(180*adc_val1)/1023;//speed
 //vout=(adc_val2 *3.3)/1023;
 //ta=(vout-0.05)/0.01;

}
}
