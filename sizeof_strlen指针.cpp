

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const char *p = "abcdef";
	
	printf("%d\n", sizeof(p));	//p Ϊһ��ָ����� -- ��ַ�� 4���ֽ� 
	printf("%d\n", sizeof(p + 1));	//p ��� ����� a �ĵ�ַ�� p + 1 �� b �ĵ�ַ�� 4 ���ֽ� 
	printf("%d\n", sizeof(*p));	// ��һ�� Ԫ�ش�С : 1 ���ֽ� 
	printf("%d\n", sizeof(p[0]));	//	�� 1 �� Ԫ�ش�С : 1 ���ֽ� 
	printf("%d\n", sizeof(&p));	//����ĵ�ַ ��С Ϊ�� 4���ֽ� 	������ ��һ�� ����ָ�롣 
	printf("%d\n", sizeof(&p + 1));	//&p ���� 1 ���������������һ����ַ�Ĵ�С��4���ֽ� 
	printf("%d\n", sizeof(&p[0] + 1));	// b �ַ��ĵ�ַ�Ĵ�С ��4 ���ֽ� 
	
	printf("%d\n", strlen(p));	//6
	printf("%d\n", strlen(p + 1));	//5 
	//printf("%d\n", strlen(*p));		//���� 
	//printf("%d\n", strlen(p[0]));	//���� 
	printf("%d\n", strlen(&p));		//���ֵ�� ����һ������ָ��  
	printf("%d\n", strlen(&p + 1));	//���ֵ��&arr + 1  �������������飬������㣬�Ͳ�֪��������������'\0' �� 
	printf("%d\n", strlen(&p[0] + 1));	//�� b ��ʼ��������5 	
	
	return 0;
	
	system("pause");
	
}
