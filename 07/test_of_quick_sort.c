#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int p,int r);
int partition2(int a[],int p,int r);
void quick_sort(int a[],int p,int r);
void random_quick_sort(int a[],int p,int r);

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
		int a[] = {2,8,7,1,3,5,6,4};
		
		print_array(a,0,8);
		
		printf("%d\n",partition(a,0,7));
		random_quick_sort(a,0,7);
		
		print_array(a,0,8);

		return 0;
}

