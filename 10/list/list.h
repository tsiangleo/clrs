#ifndef _LIST_H_
#define _LIST_H_

/* the element type that the list holds. */
typedef void * elem_t;

/* the definition of list node. */
typedef struct list_node
{
	struct list_node *prev;
	struct list_node *next;
	elem_t data;
} lnode_t;

typedef struct list
{
	lnode_t *head,*tail;
	int size; /* the number of elements that the list currently contains.*/
} list_t;


/* return a intialed list if OK, else return NULL. */
list_t * init_list();

/* find the fist node in the list,whose key is equal to the given key. 
 * return a pointer to the node if found, otherwise return NULL.  */
lnode_t *list_search(list_t *list,elem_t key);

/* insert the given list node into the end of the list. return 0 if OK, -1 on error. */
int list_insert(list_t *list, lnode_t *node);

/* delete the given list node from the list. return 0 if OK, -1 on error. */
int list_delete(list_t *list,lnode_t *node);

void list_destroy(list_t *list);

void list_traverse(list_t *list,void (*visit)(lnode_t *));

#endif
