#ifndef _STACK_H_
#define _STACK_H_

/* default max number of elements that the stack can holds. */
#define DEFAULT_STACK_DEPTH 10

/* the increment that add to the stack when it is about to overflow. */
#define STACK_INCREMENT 2 

/* the data type that the stack holds. */
typedef void* elem_t;

typedef struct stack
{
	elem_t		*base; 	/* the base address of array elem_t[]. */
	int 		depth; 	/* max number of elements that the stack can holds. */
	int 		top; 	/* stack pointer, intial value is -1. */

}stack_t;


/* on success return a pointer to stack_t, return NULL if failed. */
stack_t * init_stack();

/* return 1, if the stack is full; else return 0.  */
int stack_full(stack_t *s);

/* return 1, if the stack is empty; else return 0.  */
int stack_empty(stack_t *s);

/* on success return 0; return -1 if the stack overflow. */
int push(stack_t *s, elem_t e);

/*
 *  if the stack is about to overflow,this function will automatically increse the stack size.
 *  on success return 0; return -1 if realloc() failed.   
 */
int push_v2(stack_t *s, elem_t e);
	
/* status - on sucess,its value is 0; its value is -1 if failed. */
elem_t pop(stack_t *s,int *status);

void stack_traverse(stack_t *s, void (*visit)(elem_t));

void destory_stack(stack_t *s);

#endif

