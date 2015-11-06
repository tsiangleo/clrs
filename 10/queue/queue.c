#include<stdlib.h>
#include<stdio.h>
#include"queue.h"

/**
 * initialize a queue.
 * on success return a pointer to queue_t, return NULL if failed.
 */
queue_t * init_queue()
{
	queue_t *q;
	q = (queue_t *)malloc(sizeof(queue_t));
	if(q == NULL)
		return NULL;
	
	q->head = q->tail = 0;
	q->length = DEFAULT_QUEUE_SIZE;
	q->base = (elem_t *)malloc((q->length + 1)* sizeof(elem_t)); /* if the queue wants to hold n elemnts, must allocate n+1 memory.*/
	
	if(q->base == NULL)
	{
		free(q);
		return NULL;
	}

	return q; 
}

int queue_empty(queue_t *q)
{
	if(q->head == q->tail)
		return 1;
	else
		return 0;
}

int queue_full(queue_t *q)
{
	int array_size = q->length + 1;

	if( ( (q->tail + 1) % array_size) == q->head)
		return 1;
	else
		return 0;
}

/**
 * on success return 0; return -1 if the queue overflow.
 */
int enqueue(queue_t *q,elem_t e)
{
	int array_size = q->length + 1;

	if(queue_full(q))
	{
		return -1;
	}

	*(q->base + q->tail) = e;
	q->tail= (q->tail + 1) % array_size;
	return 0;
}

int enqueue_v2(queue_t *q,elem_t e)
{
	int array_size;
	elem_t *newbase;

	if(queue_full(q))
	{
		newbase = realloc(q->base,(q->length + 1 + QUEUE_INCREMENT)*sizeof(elem_t));
		if(newbase != NULL)
		{
			printf("\n add %d new space. ",QUEUE_INCREMENT);
			q->base = newbase;
			q->length += QUEUE_INCREMENT;
		}
		else
			return -1;
	}

	array_size = q->length + 1;
	
	*(q->base + q->tail) = e;
	q->tail= (q->tail + 1) % array_size;
	return 0;
		
}

/**
 * status - on sucess,its value is 0; its value is -1 if failed.
 */
elem_t dequeue(queue_t *q,int *status)
{
	elem_t x;
	int array_size = q->length + 1;

	if(queue_empty(q))
	{
		*status = -1;
		return (elem_t)0;
	}

	x = *(q->base + q->head);
	q->head = (q->head + 1) % array_size;
	*status = 0;
	return x;
}

void queue_traverse(queue_t *q, void (*visit)(elem_t))
{
	int i,h;
	int array_size = q->length + 1;
	int elem_number = (q->tail - q->head + array_size ) % array_size; 

	elem_t e;

	for(h = q->head,i = 1; i <= elem_number;i++,h++)
	{
		if(h == array_size)
			h = 1;
		e = *(q->base + h);
		visit(e);
	}

}

void destory_queue(queue_t *q)
{
	if(q != NULL)
	{
		if(q->base != NULL)
		{
			free(q->base);
			q->base = NULL;
		}

		free(q);
	}
}
