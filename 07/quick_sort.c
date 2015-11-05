#include<stdlib.h>
/**
 * p,r - the index of array a, whose value start with 0;
 *
 */
int partition(int a[],int p,int r)
{
	int i,j,temp;

	i = p - 1;

	for(j = p;j<= r-1;j++)
	{
		if(a[j] <= a[r])
		{
			i++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}

	temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;

	return i + 1;
}

int random_partition(int a[],int p,int r)
{
	int i = random() % (r - p + 1) + p;
	int temp;

	temp = a[r];
	a[r] = a[i];
	a[i] = temp;

	return partition(a,p,r);
}


/*
 * p,r - the index of array a, whose value start with 0;
 */
int partition2(int a[],int p,int r)
{
	int x = a[p];
	int i = p,j = r,temp;

	while(1)
	{
		while(a[j] > x) // find the element who <= x, must contains =.
			j--;

		while(a[i] < x) // find the elemtn who >= x, must contains =.
			i++;

		if(i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else
		{
			return j;
		}
	}
}


void quick_sort(int a[],int p,int r)
{
	if(p < r)
	{
		int q;
		q = partition2(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}



void random_quick_sort(int a[],int p,int r)
{
	if(p < r)
	{
		int q = random_partition(a,p,r);
		random_quick_sort(a,p,q-1);
		random_quick_sort(a,q+1,r);
	}
}





















