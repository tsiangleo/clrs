#include<stdlib.h>
#include<stdio.h>
#include"list.h"

/**
 * 不带头结点的实现。
 */

list_t * init_list()
{
	list_t *list = (list_t *)malloc(sizeof(list_t));
	if(list == NULL)
		return NULL;
	
	list->head =  NULL;
	list->tail =  NULL;
	list->size = 0;
	return list;
}

/* find the fist node in the list,whose key is equal to the given key. 
 * return a pointer to the node if found, otherwise return NULL.  */
lnode_t *list_search(list_t *list,elem_t key)
{
	if(list == NULL)
		return NULL;

	lnode_t *p = list->head;

	while(p && p->data != key)
		p = p->next;
	return p;
}

/* insert the given list node into the end of the list. return 0 if OK, -1 on error. */
int list_insert(list_t *list, lnode_t *node)
{
	if(list != NULL && node != NULL)
	{
		if(list->size == 0)
		{
			node->next = NULL;
			node->prev = NULL;
			list->head = node;
			list->tail = node;
			list->size++;
			return 0;
		}
		else
		{
			node->next = NULL;
			node->prev = list->tail;
			list->tail->next = node;
			list->tail = node;
			list->size++;
			return 0;
		}
	}
	return -1;
}

/* delete the given list node from the list. return 0 if OK, -1 on error. */
int list_delete(list_t *list,lnode_t *node)
{
	if(list != NULL && node != NULL)
	{		
		if(node->prev != NULL)
			node->prev->next = node->next;
		else
			list->head = node->next;

		if(node->next != NULL)
			node->next->prev = node->prev;
		else
			list->tail = node->prev;

		free(node);
		list->size--;
		return 0;
	}
	return -1;
}

void list_destroy(list_t *list)
{
	lnode_t *p;
	if(list != NULL)
	{
		p = list->head;
		while(p)
		{
			free(p);
			p = p->next;
		}
		free(list);
	}
}

void list_traverse(list_t *list,void (*visit)(lnode_t *))
{
	lnode_t *p;
	if(list != NULL )
	{
		p = list->head;

		while(p)
		{
			visit(p);
			p = p->next;
		}
	}

}

