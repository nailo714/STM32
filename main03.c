#include "stm32f10x.h"                  // Device header
//使用延时函数添加一个头文件
#include "Delay.h" 
int main()
{
	//开启时钟，这里的外设也可以使用按位或来选择多个外设的，因为每个外设都对应
	//了一个某个位置1，或了之后指定的那几个都为1了然后对应的外设就开启了
	//每一位对应一个外设，一次这里很多东西都可以使用按位或来同时设置对应的外设
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//初始化GPIO
	
	//首先需要定义一个GPIO结构体指定GPIO初始值，才能放进初始化函数
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;//推挽输出
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz ;//工作频率
	//LED需要用到0到7的引脚
	//这样写可以同时初始所有引脚，可以转到定义查看原理
	//也可以按位一个一个或，但是这里直接把全部引脚都搞了，
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All ;
	
	//接着使用初始化函数
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	

	while(1)
	{
		//把对应的引脚置1或0开始电灯
		//
		GPIO_Write(GPIOA, ~0x0001);//这里的~是取反的意思，然后0001这里十六进制
		//二进制每一位置1或0都可以开启或者关闭外设，
		//这里是把GPIOA的第一个引脚置低电平（取反）不取反就是置1这个函数
		Delay_ms(300);
		//引脚pa1
		GPIO_Write(GPIOA, ~0x0002);//0000 0000 0000 0010
		Delay_ms(300);
		//引脚pa2
		GPIO_Write(GPIOA, ~0x0004);//0000 0000 0000 0100
		Delay_ms(300);
		//引脚pa3
		GPIO_Write(GPIOA, ~0x0008);//0000 0000 0000 1000
		Delay_ms(300);
		//引脚pa4
		GPIO_Write(GPIOA, ~0x0010);//0000 0000 0001 0000
		Delay_ms(300);
		//引脚pa5
		GPIO_Write(GPIOA, ~0x0020);//0000 0000 0010 0000
		Delay_ms(300);
		//引脚pa6
		GPIO_Write(GPIOA, ~0x0040);
		//Delay_ms(300);
		///引脚pa7
		GPIO_Write(GPIOA, ~0x0080);
		Delay_ms(300);
	}
	
}
