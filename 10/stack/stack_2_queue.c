#include<stdio.h>
#include"stack.h"

/**
 * use two stack to simulate a queue.
 */

stack_t *s1;
stack_t *s2;

/* on success return 0, else return -1. */
int s2q_init()
{
	s1 = init_stack();
	s2 = init_stack();
	if(s1 == NULL || s2 == NULL)
	{
		return -1;
	}
	return 0;
}

/* on success return 0, else return -1. */
int s2q_enqueue(elem_t e)
{
	return push_v2(s1,e);
}

/* stat - on sucess,its value is 0; its value is -1 if failed. */
elem_t s2q_dequeue(int *stat)
{
	elem_t e,ret = (elem_t)0;
	int status;
	int x;

	/* move all the elements from s1 to s2.*/
	while(!stack_empty(s1) && !stack_full(s2))
	{
		e = pop(s1,&status);
		if(status == 0)
		{
			x = push(s2,e);
			if(x == -1)
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

	/* pop s2*/
	e = pop(s2,&status);
	if(status == -1)
	{
		*stat = -1;
		return ret;
	}
	else
	{
		*stat = 0;
		ret = e;
	}

	/* move all the elements from s2 to s1*/
	while(!stack_empty(s2) && !stack_full(s1))
	{
		e = pop(s2,&status);
		if(status == 0)
		{
			x = push(s1,e);
			if(x == -1)
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
	int status = 2;

	s2q_init();

	for(i = 1; i<= 200;i++)
		s2q_enqueue((void *)i);

	for(i = 1;i<= 150;i++)
	{
		x = (int)s2q_dequeue(&status);
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
