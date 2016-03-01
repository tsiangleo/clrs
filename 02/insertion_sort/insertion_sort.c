#include "insertion_sort.h"
#include "test.h"
#include <stdlib.h>
#include <assert.h>


/* 
 * 升序排列.
 */
void insertion_sort(int a[],int size)
{
	int i,j,key;

	assert(a != NULL && size > 0);
	if(size < 2)
		return;

	/* 从第二个元素开始遍历 */
	for(i = 1;i < size;i++)
	{
		key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key)//asend order
		{
			a[j+1] = a[j];
			j --;

		}
		a[j+1] = key;

#ifdef DEBUG
		print_array(a,size);//打印每轮插入后的情况
#endif
	}
}

/*
 * 从后往前开始有序。
 *
 */
void insertion_sort_v2(int a[],int size)
{
	int i,j,key;
	
	assert(a != NULL && size > 0);
	if(size < 2)
		return;

	for(i = size - 2;i >= 0;i--)
	{
		key = a[i];
		
		j = i+1;
		while(j <= size -1 && a[j] < key)
		{
			a[j-1] = a[j];
			j++;
		}
		a[j-1] = key;
		
#ifdef DEBUG
		print_array(a,size);//打印每轮插入后的情况
#endif
	}
}
