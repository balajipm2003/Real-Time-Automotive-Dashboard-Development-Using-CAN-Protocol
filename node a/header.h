typedef unsigned int u32 ;
typedef unsigned char u8 ;
//typedef u32 unsigned int;

typedef struct CAN1_MSG{

	u32 id;

	u32 byteA;

	u32 byteB;

	u8 rtr;

	u8 dlc;

}CAN1;


extern void can1_tx(CAN1 v);

extern void can1_init(void);

extern void adc_init(void);
extern unsigned int adc_read(int ch_num);
extern void config_timer0(void);

extern void config_vic_for_timer0(void);


extern void Config_eint0(void);
extern void Config_vic_for_eint0(void);

extern void Config_eint1(void);
extern void Config_vic_for_eint1(void);

extern void Config_eint2(void);
extern void Config_vic_for_eint2(void);
