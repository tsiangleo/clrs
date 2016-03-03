#include "test.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

/* 断言数组是否有序. */
void assert_assend_order(int a[],int size)
{
	assert(a != NULL && size > 0);
	if(size < 2)
		return;
	int i;
	for(i = 1;i < size;i++)
	{
		assert(a[i] >= a[i-1]);
	}
}

void print_array(int a[],int size)
{
	assert(a != NULL && size > 0);
	
	int i = 0;
	for(;i < size;i++)
	{
		printf("%8d",a[i]);
	}
	printf("\n");
}

/* 随机产生一个数组.数组元素的取值不超过maxNum */
void random_array(int a[],int size, int maxNum)
{
	int i = 0;
	
	srand((int)time(0));
	
	for(;i < size;i++)
		a[i] = random() % maxNum;
}

