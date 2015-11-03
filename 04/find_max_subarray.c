/**
 *
 * low,mid,high - the index of array a, which start with 0.
 *
 * return: on success return 0, else return -1.
 *
 */
int find_max_crossing_subarray(int a[],int low,int mid,int high,int *result,int *max_left,int *max_right)
{
	int left_sum = -9999;
	int right_sum = -9999;
	int sum = 0;
	int i,j;

	for(i = mid;i >= low;i--)
	{
		sum += a[i];
		if(sum > left_sum)
		{
			left_sum = sum;
			*max_left = i;
		}
	}

	sum = 0;
	for(j = mid+1;j<=high;j++)
	{
		sum += a[j];
		if(sum > right_sum)
		{
			right_sum = sum;
			*max_right = j;
		}
	}

	*result = left_sum + right_sum;
	return 0;
}

/*
 * low,mid,high - the index of array a, which start with 0.
 *
 * return: on success return 0, else return -1.
 *
 */
int find_maximum_subarray(int a[],int low,int high,int *result,int *max_left,int *max_right)
{
	if(high == low)
	{
		*result = a[low];
		*max_left = low;
		*max_right = high;
		return 0;
	}
	else
	{
		int mid = (low + high) / 2;
		int left_low = 0;
		int left_high = 0;
		int left_sum = 0;
		int right_low = 0;
		int right_high = 0;
		int right_sum = 0;
		int cross_low = 0;
		int cross_high = 0;
		int cross_sum = 0;

		find_maximum_subarray(a,low,mid,&left_sum,&left_low,&left_high);
		find_maximum_subarray(a,mid+1,high,&right_sum,&right_low,&right_high);
		find_max_crossing_subarray(a,low,mid,high,&cross_sum,&cross_low,&cross_high);
		
		if(left_sum >= right_sum && left_sum >= cross_sum)
		{
			*result = left_sum;
			*max_left = left_low;
			*max_right = left_high;
			return 0;
		} 
		else if(right_sum >= left_sum && right_sum >= cross_sum)
		{
			*result = right_sum;
			*max_left = right_low;
			*max_right = right_high;
			return 0;
		}
		else
		{
			*result = cross_sum;
			*max_left = cross_low;
			*max_right = cross_high;
			return 0;
		}
	}
}


/**
 *
 * this is the answer for Exercise 4.1-5 on page 42.
 *
 */
int find_maximum_subarray2(int a[],int low,int high,int *result,int *max_left,int *max_right)
{
	int max_sum = a[low];
	int index = low + 1;
	int left = low,right = low;

	while(index <= high )
	{
		/**
		 *  the maxmium subarray is in a[i..j+1] for array a[1..j+1].
		 */
		int j,sum = 0;
		for(j = index;j >= low;j--)
		{
			sum += a[j];
			if(sum > max_sum)
			{
				left = j;
				right = index;
				max_sum = sum;
			}
		}

		/*
		 * if goes there,it means:
		 * the maxminum array is in a[1..j] for array a[1..j+1].
		 *
		 */
		index ++;
	}

	*result = max_sum;
	*max_left = left;
	*max_right = right;
	
	return 0;
}
