#include <LPC21xx.H>
#include<stdio.h>
#include "header.h"

CAN1 r1;
u32 flag;
//int f1=0,f2=0;
main(){
  	char s[20];
	int vout;

	can1_init();//this initialization must be first
	config_vic_for_can1();
    lcd_init();
    //lcd_cmd(0x80);
	lcd_cgram();



	while(1){
	//can1_rx(&r1);//waiting for msg to receive
        if(flag==1){//any frame is received
                flag=0;//for next frame
        if(r1.rtr==0){

	   if(r1.id==0x55){
 				vout=(int)r1.byteA;
				sprintf(s,"Speed:%dkm/h",vout);
				lcd_cmd(0xc0);
				lcd_string(s);
         }
		/* if(r1.id==0x100) 
						{
						 vout=(int)r1.byteA;
						 sprintf(s,"T:%d*c",vout);
						 lcd_cmd(0xc7);
						 lcd_string(s);
						 uart0_tx_string(s);
						 }*/


       	 if(r1.id==0x201){
	            	  if(r1.byteA==0x10){
				        lcd_cmd(0x86);
                        lcd_string("***");
                       }

		                else if(r1.byteA==0x11){
				        lcd_cmd(0x86);
                        lcd_string("   ");
				        }
                       }
					   // break;
	     //case 0x202
		 if(r1.id==0x202){
		 		if(r1.byteA==0x12)
                 {
				while(1)
				 {
                 //can1_rx(&r1);
                 lcd_cmd(0x80);
				   lcd_data(1);
                 // lcd_data('<');
                  delay_ms(500);
				  lcd_cmd(0x80);
                   lcd_data(' ');
                  
          if(r1.id==0x55){
 				vout=(int)r1.byteA;
				sprintf(s,"Speed:%dkm/h",vout);
				lcd_cmd(0xc0);
				lcd_string(s);
             }

				   if(r1.id==0x201){
	            	  if(r1.byteA==0x10){
				        lcd_cmd(0x86);
                        lcd_string("***");
                       }

		                else if(r1.byteA==0x11){
				        lcd_cmd(0x86);
                        lcd_string("   ");
				        }
                       }
					if((r1.id==0x203) || (r1.byteA==0x13)){
					lcd_cmd(0x80);
                    lcd_data(' ');
                    break;
					}
					}
				} 
		//else if(r1.byteA==0x13)
//		    if(r1.byteA==0x13)
//				{
//                 lcd_cmd(0x80);
//                  lcd_string("|  |");
//				  }
				  }
                  //break;
	  //case 0x203:
	  if(r1.id==0x203)
	  {
	        if(r1.byteA== 0x14)
                 {
				 while(1)
				 {
                //can1_rx(&r1);
                 lcd_cmd(0x8f);
				 //lcd_data('>');
                  lcd_data(0);
                  delay_ms(500);
				  lcd_cmd(0x8f);
                   lcd_data(' ');

          if(r1.id==0x55){
 				vout=(int)r1.byteA;
				sprintf(s,"Speed:%dkm/h",vout);
				lcd_cmd(0xc0);
				lcd_string(s);
            }				  

				   if(r1.id==0x201){
	            	  if(r1.byteA==0x10){
				        lcd_cmd(0x86);
                        lcd_string("***");
                       }

		                else if(r1.byteA==0x11){
				        lcd_cmd(0x86);
                        lcd_string("   ");
				        }
                       }

				   
                if((r1.id==0x202)||(r1.byteA==0x15))
				{
				   lcd_cmd(0x8c);
                  lcd_data(' ');
				    break;
						}
				  }

				 }
	     //	else if(r1.byteA==0x15)
//		 if(r1.byteA==0x15)
//				{
//				 
//                  lcd_cmd(0x8c);
//                  lcd_string("|  |");
//				  }
				  }
                  //break;

	        //}
         }
        }
      }
}
 

