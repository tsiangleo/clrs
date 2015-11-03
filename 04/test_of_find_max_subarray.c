#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 10

int find_maximum_subarray(int a[],int low,int high,int *result,int *max_left,int *max_right);
int find_maximum_subarray2(int a[],int low,int high,int *result,int *max_left,int *max_right);

void print(int *a,int length)
{
	int i = 0;
	for(;i<length;i++)
	{
		printf("%8d",a[i]);
	}
	printf("\n");
}


int
main(void)
{

	
	int a[ARRAY_SIZE];
	const int max = 20;

	int i = 0;
	for(;i < ARRAY_SIZE;i++)
	{
		if(i % 2 == 0)
			a[i] = -(random() % max);
		else
			a[i] = random() % max;
	}

//	int a[ARRAY_SIZE] = {-10,-3,-4,-5,-2,-6,-8,-9,-7,-1};

	print(a,ARRAY_SIZE);
	
	
	int result = 0;
	int max_left = 0;
	int max_right = 0;

	find_maximum_subarray2(a,0,ARRAY_SIZE - 1,&result,&max_left,&max_right);
	printf("result = %d, left = %d,right = %d\n",result,max_left,max_right);
	return 0;

}
