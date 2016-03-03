#include "merge_sort.h"
#include "test.h"
#include <stdio.h>
#include <assert.h>

// pre-declaration
void merge(int *a,int p,int r,int q);
void merge2(int *a,int p,int r,int q);
void merge_sort_range(int *a,int left,int right);

/**
 * merge_sort
 *
 */
void merge_sort(int a[],int size)
{
	assert(a != NULL && size > 0);
	merge_sort_range(a,0,size-1);
}

/* left和right是数组下标，从0开始. */
void merge_sort_range(int *a,int left,int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		merge_sort_range(a,left,mid);
		merge_sort_range(a,mid+1,right);
		//merge2(a,left,mid,right);
		merge(a,left,mid,right);
	}
}


/**
 *
 * [p,...,r] & [r+1,...,q]
 *
 * 不使用哨兵.
 *
 * This is the answer for Exercise 2.3-2 on page 22.
 * 
 * NOT TRUE
 */
void merge2(int a[],int p,int r,int q)
{
	int left[20];
	int right[20];
	
	int left_size = r-p+1;
	int right_size = q-r;				   
	int i,j,key;

	for(i = 0;i<left_size;i++)
		left[i] = a[p+i];
    
	for(i = 0;i<right_size;i++)
	    right[i] = a[r+1+i];
	
	printf("a is\n");
	print_array(a+p,q-p+1);
	printf("left\n");
	print_array(left,left_size);
	printf("right\n");
	print_array(right,right_size);

	for(i = 0,j = 0,key = p;key <= q;)
	{
		if(left[i] <= right[j])
		{
			a[key++] = left[i++];
			continue;
		}
		if(left[i] > right[j])
		{
			a[key++] = right[j++];
			continue;
		}
		if(i == left_size - 1)
		{
			while(j < right_size)
				a[key++] = right[j++];
			break;
		}
		if(j == right_size - 1)
		{
			while(i < left_size)
				a[key++] = left[i++];
			break;
		}
	}
	printf("after\n");
	print_array(a+p,q-p+1);

}
/*
 * [p,...,r] & [r+1,...,q]
 *
 */
void merge(int a[],int p,int r,int q)
{
	int left[20];
	int right[20];
	int flag_end = 999999;

	int left_size = r-p+1;
	int right_size = q-r;
	int i,j,key;

	for(i = 0;i<left_size;i++)
		left[i] = a[p+i];
	left[i] = flag_end;

	for(i = 0;i<right_size;i++)
		right[i] = a[r+1+i];
	right[i] = flag_end;

	printf("a is\n");
	print_array(a+p,q-p+1);
	printf("left\n");
	print_array(left,left_size+1);
	printf("right\n");
	print_array(right,right_size+1);
	
	for(i = 0,j = 0,key = p;key <= q;)
	{
		if(left[i] <= right[j])
			a[key++] = left[i++];
		else
			a[key++] = right[j++];
	}
	printf("after\n");
	print_array(a+p,q-p+1);
}

