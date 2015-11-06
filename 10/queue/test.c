#include<stdio.h>
#include"queue.h"
#include<assert.h>

void print(elem_t e)
{
	printf("%5d",(int)e);
}

int
main(void)
{
	int i;
	int status = -2;
	int t;
						
	queue_t *q;
	q = init_queue();
	assert(q->base != NULL);
	assert(q->head == 0);
	assert(q->tail == 0);

	printf("enqueue:\n");	
	for(i = 1;i <= 150;i++)
	{
		printf("%5d:%d",i,enqueue_v2(q,(void *)i));
	}
	printf("\ntraverse:\n");
		
	queue_traverse(q,print);
		
	printf("\ndequeue:\n");
	for(i = 1;i <= 50;i++)
	{
		t =(int) dequeue(q,&status);
		printf("%5d:%d",t,status);
	}
	printf("\n");
		
	printf("traverse - again:\n");
	queue_traverse(q,print);
	printf("\n");

	destory_queue(q);
	assert(q->base == NULL);
	q = NULL;
	assert(q == NULL);
	return 0;
}

