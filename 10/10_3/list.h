#ifndef _LIST_H_
#define _LIST_H_

/* the element type that the list holds. */
typedef void * elem_t;

#define MAX_SZIE 1024

typedef struct list
{
	int prev[MAX_SIZE];
	int next[MAX_SIZE];
	elem_t data[MAX_SIZE];
	int free;
	int head;
	int before;
} list_t;

list_t list;

void init_list()
{
	int i;
	list.head = -1;
	list.before = -1;
	list.free = 0;
	for(i = 0;i<= MAX_SIZE - 2;i++) //建立初始的空闲列表
	{
		list.next[i] = i + 1;
		list.prev[i] = -1;
	}
	list.next[MAX_SIZE -1] = -1;
	list.prev[MAX_SIZE -1] = -1;
}

/* find the fist node in the list,whose key is equal to the given key. 
 * return a pointer to the node if found, otherwise return NULL.  */
int list_search(elem_t key)
{
	int index = -1;
	index  = list.head;
	while(index != -1 && data[index] != key)
		index = next[list.head];
	return index;
}
/* on success return the index(0 <= index <= MAX_SIZE - 1), return -1 if failed.*/
int allocate_object()
{
	int x = -1;
	if(list.free = -1)
		return -1;
	else
	{
		x = list.free;
		list.free = list.next[x];
		return x;
	}
}
/* insert the given list node into the end of the list. return 0 if OK, -1 on error. */
int list_insert(elem_t data)
{
	int index = allocate_object();
	if(index == -1)
		return -1;
	list.data[index] = data;
	list.next[index] = -1;
	list.prev[index] = list.before;

	if(list.before != -1)
		list.next[list.before] = index;
	list.before = index;

	return 0;
}

/* delete the given list node from the list. return 0 if OK, -1 on error. */
/* index(0<= index <= MAX_SIZE-1)*/
int list_delete(int index);
{
	if(index < 0 || index >= MAX_SIZE)
		return -1;
	
}

void list_destroy(list_t *list);

void list_traverse(list_t *list,void (*visit)(lnode_t *));

#endif
