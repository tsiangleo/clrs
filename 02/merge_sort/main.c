#include "merge_sort.h"
#include "test.h"

#include<stdio.h>

#define ARRAY_SIZE 10


int main(void)
{
	int a[ARRAY_SIZE];

	random_array(a,ARRAY_SIZE,1000);

	puts("before sort:");
	print_array(a,ARRAY_SIZE);

	merge_sort(a,ARRAY_SIZE);
	assert_assend_order(a,ARRAY_SIZE);

	puts(" after sort:");
	print_array(a,ARRAY_SIZE);
	
	return 0;
}


