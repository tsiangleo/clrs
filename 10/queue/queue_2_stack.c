#include<stdio.h>
#include"queue.h"

/**
 * use two queues to simulate a stack
 * 设有两个队列A和B，栈的push操作，直接push到A的队尾就行了。
 * 
 * 栈的pop操作时，将A中的队列依次取出放到B中，取到最后一个时，最后一个不要放到B中，直接删掉，再将B中的值依次放回A中。
 * 
 * 栈的top操作时，将A中的队列依次取出放到B中，取到最后一个时，将最后一个值记录下来，再将最后一个值放到B中，再将B中的值依次放回到A中。
 */

queue_t *q1;// init_queue();
queue_t *q2;//init_queue(); //http://blog.csdn.net/wusuopubupt/article/details/35997295

/* on success return 0, else return -1. */
int q2s_init()
{
	q1 = init_queue();
	q2 = init_queue();
	if(q1 == NULL || q2 == NULL)
	{
		return -1;
	}
	return 0;
}

/* on success return 0, else return -1. */
int q2s_push(elem_t e)
{
	return enqueue(q1,e);
}

/* stat - on sucess,its value is 0; its value is -1 if failed. */
elem_t q2s_pop(int *stat)
{
	elem_t x,ret= (elem_t)0;
	int status=-2;
	int i;
	int q1_array_size = q1->length + 1;
	int q1_elem_number = (q1->tail - q1->head + q1_array_size ) % q1_array_size; /* the number of elements in q1.*/
	
	/* move all the elements in q1 to q2,exception the last one.*/
	for(i = 1;i <= q1_elem_number - 1;i++)
	{
		//enqueue(q2,dequeue(q1,&status));
		x = dequeue(q1,&status);
		if(status == 0)
		{
			status = enqueue(q2,x);
			if(status == -1)
			{
				*stat = -1;
				return ret;
			}
		}
		else
		{
			*stat = -1;
			return ret;
		}
	}

	/* dequeue the last elements from q1. */
	status = 1;
	x = dequeue(q1,&status);
	if(status == 0)
	{
		*stat = 0;
		ret = x;
	}
	else
	{
		*stat = -1;
	}

	/* move all the elements in q2 to q1.*/
	for(i = 1;i <= q1_elem_number-1;i++)
	{
		//enqueue(q1,dequeue(q2,&status));
		x = dequeue(q2,&status);
		if(status == 0)
		{
			status = enqueue(q1,x);
			if(status == -1)
			{
				*stat = -1;
				return ret;
			}
		}
		else
		{
			*stat = -1;
			return ret;
		}

	}
	return ret;
}

int
main(void)
{
	int x;
	int i;
	int status;

	q2s_init();

	for(i = 1; i<= 12;i++)
		q2s_push((void *)i);

	for(i = 1;i<= 7;i++)
	{
		x = (int)q2s_pop(&status);
		if(status == 0)
		{
			printf("%5d",x);
		}
		else
		{
			printf("   error  ");
		}
	}
	printf("\n");

	return 0;
}
