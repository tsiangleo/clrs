#include<stdlib.h>
#include<stdio.h>
#include"stack.h"


stack_t * init_stack()
{
	stack_t *s = (stack_t *)malloc(sizeof(stack_t));
	if(s == NULL)
		return NULL;
	s->top = -1;
	s->depth = DEFAULT_STACK_DEPTH;
	s->base = malloc(s->depth*sizeof(elem_t));

	if(s->base == NULL)
	{
		free(s);
		return NULL;
	}

	return s;
}

int stack_full(stack_t *s)
{
	if(s->top + 1 == s->depth)
		return 1;
	else
		return 0;
}

int stack_empty(stack_t *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

/**
 *
 * on success return 0; return -1 if stack overflow.
 *
 */
int push(stack_t *s, elem_t e)
{
	if(stack_full(s))
	{
		return -1;
	}

	s->top++;
	*(s->base + s->top) = e;
	return 0;
}

/**
 * if the stack is about to overflow,this function will automatically increse the stack size.
 * on success return 0; return -1 if realloc() failed.
 */
int push_v2(stack_t *s, elem_t e)
{
	elem_t *newbase;

	if(stack_full(s))
	{
		newbase = (elem_t *)realloc(s->base,(s->depth + STACK_INCREMENT) *sizeof(elem_t));
		if(newbase == NULL)
			return -1;
		else
		{
			//free(s->base); /* the lib function will automaticlly free the old area. otherwise will occures: "double free or corruption" */
			s->base = newbase;
			s->depth += STACK_INCREMENT;
			printf("\n add %d new space. ",STACK_INCREMENT);
		}
	}
	s->top++;
	*(s->base + s->top) = e;
	return 0;
}

/*
 * status - on success its value is 0; if stack underflow, its value is -1.
 *
 */
elem_t pop(stack_t *s,int *status)
{
	elem_t x;
	
	if(stack_empty(s))
	{
		*status = -1;
		return (elem_t)0;
	}

	x = *(s->base + s->top);
	s->top--;
	*status = 0;
	return x;
}

void stack_traverse(stack_t *s, void (*visit)(elem_t))
{
	int i;
	elem_t x;
	if(!stack_empty(s))
	{
		for(i = s->top;i>= 0;i--)
		{
			x = *(s->base + i);
			visit(x);
		}
	}
}

void destory_stack(stack_t *s)
{
	if(s != NULL)
	{
		if(s->base != NULL)
		{
			free(s->base);
			s->base = NULL;
		}
		free(s);
		s = NULL; /* it desen't make sense, because s is local variable. */
		//*s = NULL;
	}
}

