

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const char *p = "abcdef";
	
	printf("%d\n", sizeof(p));	//p 为一个指针变量 -- 地址： 4个字节 
	printf("%d\n", sizeof(p + 1));	//p 里边 存的是 a 的地址， p + 1 是 b 的地址： 4 个字节 
	printf("%d\n", sizeof(*p));	// 第一个 元素大小 : 1 个字节 
	printf("%d\n", sizeof(p[0]));	//	第 1 个 元素大小 : 1 个字节 
	printf("%d\n", sizeof(&p));	//数组的地址 大小 为： 4个字节 	其类型 是一个 二级指针。 
	printf("%d\n", sizeof(&p + 1));	//&p ，加 1 跳过整个数组的下一个地址的大小：4个字节 
	printf("%d\n", sizeof(&p[0] + 1));	// b 字符的地址的大小 ：4 个字节 
	
	printf("%d\n", strlen(p));	//6
	printf("%d\n", strlen(p + 1));	//5 
	//printf("%d\n", strlen(*p));		//错误 
	//printf("%d\n", strlen(p[0]));	//错误 
	printf("%d\n", strlen(&p));		//随机值， 这是一个二级指针  
	printf("%d\n", strlen(&p + 1));	//随机值：&arr + 1  ，跳过整个数组，往后计算，就不知道在哪里能遇到'\0' 了 
	printf("%d\n", strlen(&p[0] + 1));	//从 b 开始往后数，5 	
	
	return 0;
	
	system("pause");
	
}
