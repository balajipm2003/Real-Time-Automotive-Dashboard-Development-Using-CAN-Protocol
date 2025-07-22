#include<LPC21XX.H>
#include"header.h"
void lcd_data(unsigned char data)
{
IOCLR0=0X7FF;
IOSET0=data;
IOSET0=1<<8;
IOCLR0=1<<9;
IOSET0=1<<10;
delay_ms(2);
IOCLR0=1<<10;
}
void lcd_cmd(unsigned char cmd)
{
IOCLR0=0X7FF;
IOSET0=cmd;
IOCLR0=1<<8;
IOCLR0=1<<9;
IOSET0=1<<10;
delay_ms(2);
IOCLR0=1<<10;
}
void lcd_init()
{
IODIR0=0X7FF;
lcd_cmd(0x38);
lcd_cmd(0x0e);
lcd_cmd(0x01);
}
void lcd_string(char *ptr)
{
while(*ptr!=0)
{
 lcd_data(*ptr);
 ptr++;
 }
 }

  void lcd_cgram()
 {
 int i;
int a1[]={0x04,0x02,0x01,0x1f,0x01,0x02,0x04,0x00};
int a2[]={0x04,0x08,0x10,0x1f,0x10,0x08,0x04,0x00};
 lcd_cmd(0x40);
 for(i=0;i<8;i++)
 {
 lcd_data(a1[i]);
 }

 lcd_cmd(0x48);
 for(i=0;i<8;i++)
 {
 lcd_data(a2[i]);
 }
 }

