#include "stm32f10x.h"                  // Device header
//使用延时函数添加一个头文件
#include "Delay.h" 
int main()
{
	//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//初始化GPIO
	
	//首先需要定义一个GPIO结构体指定GPIO初始值，才能放进初始化函数
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;//推挽输出
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz ;//工作频率
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 ;//几号引脚
	
	//接着使用初始化函数
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//执行完这一步之后，GPIOA外设的0号引脚就被设置位推挽输出，50MHz的速度了
	//第一个参数就是把哪个外设，第二个是GPIO的参数设置
	//初始化完毕
	
	//开始使用输入输出函数
	//第一个，把这个外设的引脚0置为低电平
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	
	//第二个，高电平
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);
	
	//第三个函数，
	//（1）这里的Bit_RESET就是清空数值，置低电平
	//GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
	
	//（2）如果是高点平就输入
	//GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
	
	//实现LED闪烁，点亮一会延时一会不点亮，然后进入死循环
	while(1)
	{
		//点亮
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
		//也可以这样写,强转成bit这种类型
		//GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)0);
		
		//一定需要加上延时函数
		//加一个延时函数
		//这个是毫秒级别的延时，输入啥就延时多少毫秒
		Delay_ms(500);
		
		//延时结束后熄灭
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
		
		//GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)1);
		
		//接着一个延时，否则熄灭还没开始就执行点亮了，因为你传输
		//一个信号给外设也需要时间，而你的代码执行速度肯定比你传到外设在
		//执行置0或置1的速度快
		Delay_ms(500);
		
	}
	
}
