#ifndef _TREE_H_
#define _TREE_H_

/* the element type that the tree holds. */
typedef void * elem_t;

/* the definition of tree node. */
typedef struct tree_node
{
	struct tree_node *lchild;
	struct tree_node *rchild;
	elem_t data;
} tnode_t;

typedef tnode_t * searchTree_t;


tnode_t * tree_search(searchTree_t t ,elem_t key);
tnode_t * tree_max(searchTree_t t);
tnode_t * tree_min(searchTree_t t);
tnode_t * tree_predecessor(searchTree_t t);
tnode_t * tree_successor(searchTree_t t);


int tree_insert(searchTree_t t, tnode_t *node);
int tree_delete(searchTree_t t, tnode_t *node);

void tree_destroy(searchTree t);

void inorder_walk_tree(searchTree t,void (*visit)(tnode_t *));

#endif
