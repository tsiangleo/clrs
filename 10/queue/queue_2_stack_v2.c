#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int head;
    int tail;
    int *base;
    int maxSize;
} queue_t;

typedef struct {
    queue_t *q1;
    queue_t *q2;
    int size; /* the number of elements currently in the stack. */
} Stack;


/* Create a queue whose size is MaxSize. on error return NULL. */
static queue_t * 
init_queue(int maxSize){
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    if(q != NULL)
    {
        q->head = q->tail = 0;
        q->base = (int *)malloc(maxSize * sizeof(int));
        q->maxSize = maxSize;
        if(q->base == NULL)
        { 
            free(q);
            return NULL;
        }
        return q;
    }
    return NULL;
}

/* if queue q is empty,retun 1; else return 0. */
static int 
queue_empty(queue_t *q)
{
    if(q->head == q->tail)
        return 1;
    else
        return 0;
}

/* if queue q is full,retun 1; else return 0. */
static int 
queue_full(queue_t *q)
{
    if((q->tail + 1) % q->maxSize == q->head)
        return 1;
    else
        return 0;
}

/* on success,return the size of the queue, return -1 on error. */
static int 
queue_size(queue_t *q)
{
    int size = -1;
    if(q != NULL)
    {
        size = (q->tail - q->head + q->maxSize) % q->maxSize;
    }
    return size;
}

/* push e into queue. on success return 0, return -1 if failed. */
static int 
enqueue(queue_t *q,int e)
{
    if(queue_full(q))
        return -1;
    *(q->base + q->tail) = e;
    q->tail = (q->tail + 1) % q->maxSize;
    return 0;
}

/* pop element from queue. on success, the value of status is 0, otherwise is -1. */
static int 
dequeue(queue_t *q,int *status)
{
    int e;
    if(queue_empty(q))
    {
        if(status != NULL)
            *status = -1;
        return -1;
    }

    e = *(q->base + q->head);    
    q->head = (q->head + 1) % q->maxSize;
    if(status != NULL)
        *status = 0;
    return e;
}

static void
destory_queue(queue_t *q)
{
    if(q != NULL)
    {
        if(q->base != NULL)
        {
            free(q->base);
        }
        free(q);
    }
}

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
//    if(stack == NULL)
  //      stack  = (Stack *)malloc(sizeof(Stack));
    if(stack != NULL)
    {
        stack->q1 = init_queue(maxSize);
        stack->q2 = init_queue(maxSize);
        stack->size = 0;
    }
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    enqueue(stack->q1, element);
    stack->size++;
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    while(queue_size(stack->q1) > 1)
    {
        enqueue(stack->q2,dequeue(stack->q1,NULL));
    }
    dequeue(stack->q1,NULL);
    
    while(!queue_empty(stack->q2))
    {
        enqueue(stack->q1,dequeue(stack->q2,NULL));
    }
    
    stack->size--;
}

/* Get the top element */
int stackTop(Stack *stack) {
    int e = -1;
    
    while(queue_size(stack->q1) > 1)
    {
        enqueue(stack->q2,dequeue(stack->q1,NULL));
    }
    e = dequeue(stack->q1,NULL);
    enqueue(stack->q2,e);
     
    while(!queue_empty(stack->q2))
    {
        enqueue(stack->q1,dequeue(stack->q2,NULL));
    }
    return e;
}

/* Return whether the stack is empty */
int stackEmpty(Stack *stack) {
    return stack->size == 0 ? 1: 0;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    if(stack != NULL)
    {
        destory_queue(stack->q1);
        destory_queue(stack->q2);
        //free(stack);
    }
}


int
main()
{
	int i;
	Stack s;
	stackCreate(&s,120);

	printf("empty: %d\n",stackEmpty(&s));

	for( i=1;i<=50;i++)
		stackPush(&s,i);

	for(i = 1;i <= 50;i++)
	{
		printf("%5d",stackTop(&s));
		stackPop(&s);
	}
	printf("\n");

	stackDestroy(&s);
	return 0;
}

