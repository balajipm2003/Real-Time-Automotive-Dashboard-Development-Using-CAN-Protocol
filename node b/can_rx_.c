#include <LPC21xx.H>
#include<stdio.h>
#include "header.h"

extern CAN1 r1;

extern u32 flag;
//extern int f1,f2;

unsigned int *ptr=(unsigned int*)0xE0038000;

void can1_init(void){

	PINSEL1|=0x40000;//P0.25-->RD1

	VPBDIV=1;//PCLK==60MHz

	C1MOD=0x1;//Select reset mode

	C1BTR=0x001C001D;//125Kbps baudrate

	

	/*AF setting for INI testing*/
	/*
	ptr[0]=0x20002055;

	ptr[1]=0x21002201;

	ptr[2]=0x22022203;
	  */

	/*AF setting for embC testing*/

	ptr[0]=0x00000055;

	ptr[1]=0x01000201;

	ptr[2]=0x02020203;

	

	SFF_sa=0;

	SFF_GRP_sa=0xC;

	EFF_sa=0xC;

	EFF_GRP_sa=0xC;

	ENDofTable=0x0C;

	AFMR=0x0;//Enable AF sertings

	C1MOD=0x0;//Release reset mode

}




void CAN1_Rx_Handler(void) __irq{

//	char s[20];
//	int vout;
	r1.id=C1RID;

	r1.dlc=(C1RFS>>16)&0xF;//extract dlc

	r1.rtr=(C1RFS>>30)&1;//extract rtr

	if(r1.rtr==0){//if data-frame

		r1.byteA=C1RDA;

		r1.byteB=C1RDB;

	}
//     if(r1.id==0x55){
// 				vout=(int)r1.byteA;
//				sprintf(s,"Speed:%dkm/h",vout);
//				lcd_cmd(0xc0);
//				lcd_string(s);
//         }

	C1CMR=(1<<2);	

	flag=1;

  VICVectAddr=0;

}


void config_vic_for_can1(void){

	VICVectAddr5=(u32)CAN1_Rx_Handler;

	VICVectCntl5=26|(1<<5);//Assign CAN1 Rx intr to slot5

	VICIntEnable=(1<<26);//En CAN1 Rx Intr in VIC peripheral

	C1IER=1;//En CAN1 Rx intr in CAN1 Peri	

}


/*void can1_init(void){

	VPBDIV=1;

	PINSEL1|=0x40000;

	C1MOD=0x1;//reset mode

	AFMR=2;//accept all incoming msgs

	C1BTR=0x001C001D;//125Kbps baudrate

	C1MOD=0;//release reset mode

}*/


#define RBS (C1GSR&1)

void can1_rx(CAN1 *ptr){

	while(RBS==0);//waiting for DF /RF to receive

	ptr->id=C1RID;

	ptr->dlc=(C1RFS>>16)&0xF;//extract dlc

	ptr->rtr=(C1RFS>>30)&1;//extract rtr

	if(ptr->rtr==0){//if data-frame

		ptr->byteA=C1RDA;

		ptr->byteB=C1RDB;

	}

	C1CMR=(1<<2);//*release rxbuf	

}
