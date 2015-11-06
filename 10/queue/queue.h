#ifndef _QUEUE_H_
#define _QUEUE_H_

/* the data type that the queue holds. */
typedef void * elem_t;

/* default max number of elements that the queue can holds. */
#define DEFAULT_QUEUE_SIZE 10

/* the increment that add to the queue when it is about to overflow. */
#define QUEUE_INCREMENT 2 

/* the definition of Queue, whose implemention is array. */
typedef struct queue
{
	int 	head; 		/* default is 0.*/
	int		tail;		/* default is 0.*/
	int 	length;		/* max number of elements that the queue can holds. */
	elem_t 	*base; 		/* the base address of array elem_t[]. */

}queue_t;

/* on success return a pointer to queue_t, return NULL if failed. */
queue_t * init_queue();

/* return 1, if the queue is empty; else return 0.  */
int queue_empty(queue_t *q);

/* return 1, if the queue is full; else return 0.  */
int queue_full(queue_t *q);

/* on success return 0; return -1 if the queue overflow. */
int enqueue(queue_t *q,elem_t e);

/*
 * if the queue is about to overflow,this function will automatically increse the queue size.
 * on success return 0; return -1 if realloc() failed.   
 */
int enqueue_v2(queue_t *q,elem_t e);
	
/* status - on sucess,its value is 0; its value is -1 if failed. */
elem_t dequeue(queue_t *q,int *status);

void queue_traverse(queue_t *q, void (*visit)(elem_t));

void destory_queue(queue_t *q);

#endif
