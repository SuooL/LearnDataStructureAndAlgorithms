#include "stdio.h"

// 递归实现
int Fbi(int i) 
{
	if( i < 2 )
		return i == 0 ? 0 : 1;  
    return Fbi(i - 1) + Fbi(i - 2); 
}  

int main()
{
	int i;
	int a[40]; 
	// 循环实现 
	printf("迭代显示斐波那契数列：\n");
	a[0]=0;
	a[1]=1;
	printf("%d ",a[0]);  
	printf("%d ",a[1]);  
	for(i = 2;i < 40;i++)  
	{ 
		a[i] = a[i-1] + a[i-2];  
		printf("%d ",a[i]);  
	} 
	printf("\n");
	
	// 递归实现
	printf("递归显示斐波那契数列：\n");
	for(i = 0;i < 40;i++)  
		printf("%d ", Fbi(i));  
    return 0;
}

