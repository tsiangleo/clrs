#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<stdlib.h>

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

/* recursivly serach. */
tnode_t * tree_search_v1(searchTree_t t ,elem_t key)
{
	if(t != NULL)
	{
		if(t->data == key)
			return t;
		else if(key > t->data)
			return tree_search_v1(t->rchild,key);
		else
			return tree_search_v1(t->lchild,key);
	}
	return NULL;
}

tnode_t * tree_search_v2(searchTree_t t ,elem_t key)
{
	tnode_t *p = t;

	while(p)
	{
		if(key == p->data)
			return p;
		else if(key > p->data)
			p = p->rchild;
		else
			p = p->lchild;
	}
	return NULL;
}

tnode_t * tree_max(searchTree_t t)
{	
	tnode_t *p = t,*q = NULL;

	while(p)
	{
		q = p;
		p = p->rchild;
	}
	return q;
}

tnode_t * tree_min(searchTree_t t)
{
	tnode_t *p = t,*q = NULL;
	
	while(p)
	{
		q = p;
		p = p->lchild;
	}
	return q;
}

/* find the one before node n*/
tnode_t * tree_predecessor(tnode_t *n)
{

}

/* find the one after node n*/
tnode_t * tree_successor(tnode_t *n)
{
/*	if(t->rchild != NULL)
		return tree_min(n->rchild);
	else
*/		//...
}


/* 
 * insert an node into tree t, return the root of the tree if SUCCESS, NULL on error.
 */
searchTree_t tree_insert(searchTree_t t, tnode_t *node)
{
	tnode_t *p,*q;

	if(node == NULL)
		return NULL;

	if(t == NULL)
	{
		/*
 		tnode_t *root;
		root = malloc(sizeof(tnode_t));
		if(root == NULL) 
			return NULL;
		root->data = node->data;
		return root;
		*/
		return node;
	}

	p = t;
	q = NULL;

	/* find the postion that the new node should be. q points to the position. */
	while(p != NULL)
	{
		q = p;
		if(node->data > p->data)
			p = p->rchild;
		else
			p = p->lchild;
	}	
	
	/* q now is the parent of the new node. */
	if(node->data > q->data)
		q->rchild = node;
	else
		q->lchild = node;

	return t;
}

int tree_delete(searchTree_t t, tnode_t *node);

void tree_destroy(searchTree_t t)
{
	if(t != NULL)
	{
		free(t->lchild);
		free(t->rchild);
		free(t);
	}
}

void inorder_walk_tree(searchTree_t t,void (*visit)(tnode_t *))
{
	if(t != NULL)
	{
		inorder_walk_tree(t->lchild,visit);
		visit(t);
		inorder_walk_tree(t->rchild,visit);
	}
}

void print_tnode(tnode_t *n)
{
	if(n != NULL)
		printf("%10d",n->data);
}


int main()
{
	tnode_t *n;
	searchTree_t root = NULL;;
	
	int loops = 80000000;
	int i,rd;
	int max = 99999999;


	srand(time(NULL));
	for(i = 1;i<= loops;i++)
	{
		rd = rand() % max + 1;
//		printf("rd:%d\n",rd);
	
		n = malloc(sizeof(tnode_t));
		n->data = rd;

		root = tree_insert(root,n);
		if(root == NULL)
			printf("insert error\n");
//		inorder_walk_tree(root,print_tnode); printf("\n");
	}
		
	inorder_walk_tree(root,print_tnode); printf("\n");

	struct timeval start,end;

	gettimeofday(&start,NULL);
	tnode_t *r =  tree_search_v1(root , 9999998);
	gettimeofday(&end,NULL);

	if(r == NULL)
		printf("not found\n");
	else
		printf("found %d at 0x%x\n",r->data,(unsigned int)r);

	printf("it takes %ld seconds,%ld micorseconds in v1\n",(long)(end.tv_sec - start.tv_sec),(long)(end.tv_usec - start.tv_usec));


	r = NULL;
	gettimeofday(&start,NULL);
	r =  tree_search_v2(root , 9999998);
	gettimeofday(&end,NULL);

	if(r == NULL)
		printf("not found\n");
	else
		printf("found %d at 0x%x\n",r->data,(unsigned int)r);

	printf("it takes %ld seconds,%ld micorseconds in v2\n",(long)(end.tv_sec - start.tv_sec),(long)(end.tv_usec - start.tv_usec));


	tnode_t * min = tree_min(root);
	if(min != NULL)
		printf("min is %d\n",min->data);

	tnode_t * mx = tree_max(root);
	if(mx != NULL)
		printf("max is %d\n",mx->data);

	tree_destroy(root);
}
