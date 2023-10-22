#ifndef _BSP_IIC_H
#define _BSP_IIC_H
# include "main.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
//IO口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))  

// //IO口地址映射
// #define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
// #define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
// #define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
// #define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
// #define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
// #define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
// #define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

// #define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
// #define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
// #define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
// #define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
// #define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
// #define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
// #define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 

// #define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
// #define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

// #define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
// #define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

// #define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
// #define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入 


// //IO方向设置
// #define SDA_IN()  {GPIOA->CRH&=0XFFFFFFF0;GPIOA->CRH|=8<<0;}
// #define SDA_OUT() {GPIOA->CRH&=0XFFFFFFF0;GPIOA->CRH|=3<<0;}

// //IO操作函数	 
// #define IIC_SCL    PAout(11) //SCL
// #define IIC_SDA    PAout(8) //SDA	 
// #define READ_SDA   PAin(8)  //输入SDA 

# define IIC_SCL_PIN        GPIO_Pin_10
# define IIC_SCL_PORT       GPIOB
# define IIC_SCL_CLK        RCC_APB2Periph_GPIOB

# define IIC_SDA_PIN        GPIO_Pin_11
# define IIC_SDA_PORT       GPIOB
# define IIC_SDA_CLK        RCC_APB2Periph_GPIOB

# define IIC_W_SCL(x)       GPIO_WriteBit(IIC_SCL_PORT, IIC_SCL_PIN, (BitAction)(x))
# define IIC_W_SDA(x)       GPIO_WriteBit(IIC_SDA_PORT, IIC_SDA_PIN, (BitAction)(x))

# define IIC_R_SCL          GPIO_ReadInputDataBit(IIC_SCL_PORT, IIC_SCL_PIN)
# define IIC_R_SDA          GPIO_ReadInputDataBit(IIC_SDA_PORT, IIC_SDA_PIN)

//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(uint8_t Byte);			//IIC发送一个字节
uint8_t IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
uint8_t IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

// void IIC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
// uint8_t IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);	 
// uint8_t I2C_Readkey(unsigned char I2C_Addr);

unsigned char I2C_ReadOneByte(unsigned char I2C_Addr,unsigned char addr);
unsigned char IICwriteByte(unsigned char dev, unsigned char reg, unsigned char data);
uint8_t IICwriteBytes(uint8_t dev, uint8_t reg, uint8_t length, uint8_t* data);
uint8_t IICwriteBits(uint8_t dev,uint8_t reg,uint8_t bitStart,uint8_t length,uint8_t data);
uint8_t IICwriteBit(uint8_t dev,uint8_t reg,uint8_t bitNum,uint8_t data);
uint8_t IICreadBytes(uint8_t dev, uint8_t reg, uint8_t length, uint8_t *data);

uint8_t i2cWrite(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *data);
uint8_t i2cRead(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf);

#endif

//------------------End of File----------------------------
