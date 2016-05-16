#include<assert.h>
#include"list.h"
#include<stdio.h>

void print(lnode_t *node)
{
	if(node != NULL)
		printf("%5d",(int)node->data);
}

int 
main()
{
	int i;
	lnode_t *p;
	list_t *l ;
	
	l = init_list();
	assert(l != NULL);
	for(i = 1;i<= 5000;i++)
	{
		p = (lnode_t *)malloc(sizeof(lnode_t));
		assert(p != NULL);		
		p->data = (elem_t)i;
		assert(list_insert(l,p) == 0);
	}

	printf("init:\n");
	list_traverse(l,print);
	printf("\nafter delete 3:\n");
	
	p = list_search(l,3);
	assert(p != NULL);
	assert(list_delete(l,p) == 0);
	list_traverse(l,print);
	printf("\nafter delete 100:\n");

	p = list_search(l,100);
	assert(p != NULL);
	assert(list_delete(l,p) == 0);
	list_traverse(l,print);	
	printf("\n");

	list_destroy(l);
	return 0;
}
