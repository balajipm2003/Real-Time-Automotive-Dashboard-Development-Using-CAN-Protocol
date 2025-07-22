typedef unsigned int u32 ;
typedef unsigned char u8 ;
//typedef u32 unsigned int;
extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);
extern void lcd_init(void);
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_string(char *ptr);
extern void lcd_cgram(void);
//extern void can1_init(void);


typedef struct CAN1_MSG{

	u32 id;

	u32 byteA;

	u32 byteB;

	u8 rtr;

	u8 dlc;

}CAN1;

extern void can1_init(void);
extern void can1_rx(CAN1 *ptr);
extern void config_vic_for_can1(void );


