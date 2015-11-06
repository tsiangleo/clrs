#include<stdio.h>
#include"stack.h"
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

	stack_t *s;
	s = init_stack();

	assert(s->base != NULL);
	assert(s->top == -1);


	printf("push:\n");
	for(i = 1;i <= 250;i++)
	{
		printf("%5d:%d",i,push_v2(s,(void *)i));
	}
	printf("\n");
	stack_traverse(s,print);

	printf("\npop:\n");
	for(i = 0;i < 300;i++)
	{
		t =(int) pop(s,&status);
		printf("%5d:%d",t,status);
	}
	printf("\n");

	printf("traverse - again:\n");
	stack_traverse(s,print);	
	printf("\n");

	destory_stack(s);
	assert(s->base == NULL);
 
	s = NULL;
	assert(s == NULL);

	return 0;
}

