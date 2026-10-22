#include "stm32f10x.h"                  // Device header

int main(void)
{
	//这部分是寄存器方式电灯的
	//手册上rcc章节7.3.7APB2部分
	//设置IOPCEN位4部分置1  IO端口c时钟开启
	//RCC->APB2ENR = 0X00000010 ;
	
	//手册8.22
	//	CNFy部分	配置00：通用推挽输出模式
	//  MODE部分    配置11输出模式 50MHZ
	//GPIOC->CRH = 0x00300000 ;
	
	//手册8.2.4
	//13号端口位1，其他置零，这个端口是输出什么就写什么
	//这个灯是低电平点亮的全为零就是亮，按照下面这个就是灭
	//GPIOC->ODR = 0x00002000 ;
	
	//使用标准库函数点灯
	//外设时钟
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC,ENABLE);
	//配置端口模式
	//下面的库函数需要用到结构体指针定义一个结构体先
	GPIO_InitTypeDef GPIO_InitStructure;//据说是官方推荐这样定义的
	//给这个结构体的三个函数初始化
	//都是写出函数名然后转到定义查询怎么使用
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;//其中这个定义过多，需要在下面的浏览这里找到GPIO_Pin 	member那一栏
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	//这个函数也是如此，把上面的结构体指针地址放过来
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	//置高电平
	GPIO_SetBits(GPIOC,GPIO_InitStructure.GPIO_Pin);
	//低电平
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	
	
	while (1)
	{
		
	}
}
