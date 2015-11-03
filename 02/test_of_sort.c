#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 10

void print_array(int *a,int length);
void insert_sort_v1(int *a,int length);
void insert_sort_v2(int *a,int length);
void merge_sort(int *a,int left,int right);

int
main(void)
{
	
	int a[ARRAY_SIZE];
	const int max = 1000;

	int i = 0;
	for(;i < ARRAY_SIZE;i++)
		a[i] = random() % max;
	
	print_array(a,ARRAY_SIZE);
	//insert_sort2(a,ARRAY_SIZE);
	merge_sort(a,0,ARRAY_SIZE-1);
	print_array(a,ARRAY_SIZE);
	return 0;
}
