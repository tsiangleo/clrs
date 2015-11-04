#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 10

void heap_sort(int a[],int size);
	

void print_array(int a[],int start,int length)
{
		int i = start;
		int end = start + length;

		for(;i < end;i++)
		{
			printf("%8d",a[i]);
		}
		printf("\n");
}

int
main(void)
{
		int a[] = {0,4,1,3,2,16,9,10,14,8,7};

		print_array(a,1,10);
		heap_sort(a,10);
		print_array(a,1,10);
		return 0;
}	
