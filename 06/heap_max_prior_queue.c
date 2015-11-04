#include<stdio.h>
#include<stdlib.h>


void max_heapify(int a[], int heapsize,int i);


int
heap_maximum(int a[])
{
	return a[1];
}

int
heap_extract_max(int a[],int heapsize)
{

	int max;

	if(heapsize < 1)
	{
		fprintf(stderr,"heap underflow\n");
		return -1;
	}

	max = a[1];
	a[1] = a[heapsize];
	heapsize--;
	max_heapify(a,heapsize,1);

	return max;
}

void
heap_increase_key(int a[],int i,int key)
{
	int temp;

	if(key < a[i])
	{
		fprintf(stderr,"new key is smaller than current key\n");
		exit(EXIT_FAILURE);
	}

	a[i] = key;
	while(i > 1 && a[i/2] < a[i])
	{
		temp = a[i];
		a[i] = a[i/2];
		a[i/2] = temp;
		i = i / 2;
	}
}

void 
max_heap_insert(int a[],int key,int heapsize)
{
	heapsize++;
	a[heapsize] = -99999;
	heap_increase_key(a,heapsize,key);
}
