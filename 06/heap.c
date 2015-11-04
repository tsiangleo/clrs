
/**
 * a - an array represent the heap. whose index start with 1, a[0] is not used.
 * heapsize - the number of elements in heap.
 * i - the index of the element to be heapify.
 *
 * notice: before call this function, must ensure the subtrees whose root are the childre of i are already max_heap. 
 * 
 */
void max_heapify(int a[], int heapsize,int i)
{
	int left = 2 * i,right = 2 * i + 1;
	int largest,temp;

	if(left <= heapsize && a[left] > a[i])
		largest = left;
	else 
		largest = i;
	if(right <= heapsize && a[right] > a[largest])
		largest = right;

	if(largest != i)
	{
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;

		max_heapify(a,heapsize,largest);
	}
}

/**
 * build_max_heap
 *
 * a,length - same as max_heapify.
 *
 */
void build_max_heap(int a[],int length)
{
	int i,heapsize = length;
	
	for(i = heapsize / 2;i >= 1;i--)
	{
		max_heapify(a,heapsize,i);
	}
}



/**
 *
 * a - the array to be sort, whose index start with 1.
 *
 * NOTE:  初始的时候，length和heapsize应该是相等的。随着堆排序的进行，heapsize不断减小，以进行堆调整；而length则一直保持不变。
 *
 */
void heap_sort(int a[],int length)
{
	int i,temp;
	int heapsize = length;

	build_max_heap(a,length);
	
	for(i = length; i >= 2;i--)
	{
		/* exchange a[1] with a[i]  */
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;
	
		heapsize--;
		
		max_heapify(a,heapsize,1);
	}

}
