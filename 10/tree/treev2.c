#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<stdlib.h>

/* the element type that the tree holds. */
typedef int elem_t;
//typedef void * elem_t;

/* the definition of tree node. */
typedef struct tree_node
{
	struct tree_node *lchild;
	struct tree_node *rchild;
	struct tree_node *parent;
	elem_t data;
} tnode_t;

typedef struct searchTree
{
	int size;
	tnode_t *root;
}searchTree_t;

/* recursivly serach. */
tnode_t * tree_search_v1(tnode_t *t ,elem_t key)
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

tnode_t * tree_search_v2(tnode_t *t ,elem_t key)
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

tnode_t * tree_max(tnode_t *t)
{	
	tnode_t *p = t,*q = NULL;

	while(p)
	{
		q = p;
		p = p->rchild;
	}
	return q;
}

tnode_t * tree_min(tnode_t *t)
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
tnode_t * tree_predecessor(tnode_t *x)
{
	if(x->lchild != NULL)
		return tree_max(x->lchild);

	/* x->lchild == NULL */

	tnode_t *y = x->parent;

	/* exit when (1) x is the right child of his parent. (2) x's parent is NULL. */
	while(y != NULL && x == y->lchild)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/* find the one after node n*/
tnode_t * tree_successor(tnode_t *x)
{
	if(x->rchild != NULL)
		return tree_min(x->rchild);
	
	/* x->rchild == NULL */

	tnode_t *y = x->parent;
		
	/* exit when (1) x is the left child of his parent. (2) x's parent is NULL. */
	while(y != NULL && x == y->rchild)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/* since this operation may change the root of this tree, the parameter is a pointer to the structure searchTree, rather than a pointer of the root node.
 * insert an node into tree t, return 0 if SUCCESS, -1 on error. */
int tree_insert(searchTree_t *t, tnode_t *node)
{
	tnode_t *p,*q;

	if(node == NULL || t == NULL)
		return -1;

	if(t->root == NULL)
	{
		t->root = node;
		return 0;
	}

	p = t->root;
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
	node->parent = q;
	return 0;
}

void tree_destroy(tnode_t *root);
/* since this operation may change the root of this tree, the parameter is a pointer to the structure searchTree, rather than a pointer of the root node.
 * replace subtree u with subtree v, u's parent becomes v's.*/
static void
transplant(searchTree_t *t,tnode_t *u,tnode_t *v)
{
	tnode_t *up = u->parent;

	if(up == NULL)
		t->root = v;
	else if(u == up->lchild)
		up->lchild = v;
	else //that's  (u == up->rchild)
		up->rchild = v;

	if(v != NULL)
		v->parent = u->parent;
//	tree_destroy(u);
}

/* since this operation may change the root of this tree, the parameter is a pointer to the structure searchTree, rather than a pointer of the root node.
 * insert an node into tree t, return 0 if SUCCESS, -1 on error. */
void tree_delete(searchTree_t *t, tnode_t *node)
{
	tnode_t *y;

	if(node->lchild == NULL)
		transplant(t,node,node->rchild);
	else if(node->rchild == NULL)
		transplant(t,node,node->lchild);
	else
	{
		y = tree_min(node->rchild);
		if(y->parent != node)
		{
			transplant(t,y,y->rchild);
			y->rchild = node->rchild;
			y->rchild->parent = y;
		}
		transplant(t,node,y);
		y->lchild = node->lchild;
		y->lchild->parent = y;
	}
}

/* destroy a tree rooted with node root. */
void tree_destroy(tnode_t *root)
{
	if(root != NULL)
	{
		tree_destroy(root->lchild);
		tree_destroy(root->rchild);
		free(root);
	}
}

void inorder_walk_tree(tnode_t *root,void (*visit)(tnode_t *))
{
	if(root != NULL)
	{
		inorder_walk_tree(root->lchild,visit);
		visit(root);
		inorder_walk_tree(root->rchild,visit);
	}
}

void print_tnode(tnode_t *n)
{
	if(n != NULL)
		printf("%10d",n->data);
}

void deep_walk(tnode_t *root)
{
	tnode_t *q[4096] = {NULL},*t;
	int head = 0,tail = 0;
	int count = 0;
	int level = 0; //层数

	tnode_t NL; //用作换行
	q[tail++] = root;
	q[tail++] = &NL;


	while(head < tail)
	{
		t = q[head++];
		if(t == NULL)
		{	
			printf("  NIL ");
			continue;
		}
		else if(t == &NL)
		{
			printf("\n");
			level++;
			continue;
		}
		else
		{
			printf("%5d",t->data);
			q[tail++] = t->lchild;
			q[tail++] = t->rchild;

			//case1: 查看下一个队头元素，如果是&NIL,则说明当前节点的孩子节点就是本层的最后一个节点。
			tnode_t *next = q[head];
			if(next == &NL)
			{
				q[tail++] = &NL;
				printf("[%d]",t->data);
				continue;
			}

			//case2: 查看接下来几个连续的队头元素，如果是先连续几个NULL，然后再是&NIL，则说明当前节点的孩子节点就是本层的最后一个节点。
			int index = head;
			while(q[index] == NULL)
				index++;
			if(q[index] == &NL)
			{
				q[tail++] = &NL;
				printf("[%d]",t->data);
				continue;
			}
		}

	}
	printf("\n level: %d,head: %d,tail:%d\n",level,head,tail);
}


int main()
{
	tnode_t *n;
	searchTree_t tree;
	tree.root = NULL;
	tree.size = 0;

	int loops = 10;
	int i,rd;
	int max = 9;
	int status = -2;


	srand(time(NULL));
	for(i = 1;i<= loops;i++)
	{
		rd = rand() % max + 1;
		printf("rd:%d\n",rd);
	
		n = malloc(sizeof(tnode_t));
		n->data = rd;

		status = tree_insert(&tree,n);
		if(status == -1)
			printf("insert error\n");
//		inorder_walk_tree(tree.root,print_tnode); printf("\n");
	}
		
	inorder_walk_tree(tree.root,print_tnode); printf("\n");

	printf("deep walk\n");
	deep_walk(tree.root);
	
	struct timeval start,end;

	gettimeofday(&start,NULL);
	tnode_t *r =  tree_search_v1(tree.root , max - 1);
	gettimeofday(&end,NULL);

	if(r == NULL)
		printf("not found\n");
	else
		printf("found %d at 0x%x\n",r->data,(unsigned int)r);

	printf("it takes %ld seconds,%ld micorseconds in v1\n",(long)(end.tv_sec - start.tv_sec),(long)(end.tv_usec - start.tv_usec));


	r = NULL;
	gettimeofday(&start,NULL);
	r =  tree_search_v2(tree.root , max - 1);
	gettimeofday(&end,NULL);

	if(r == NULL)
		printf("not found\n");
	else
		printf("found %d at 0x%x\n",r->data,(unsigned int)r);

	printf("it takes %ld seconds,%ld micorseconds in v2\n",(long)(end.tv_sec - start.tv_sec),(long)(end.tv_usec - start.tv_usec));


	tnode_t * min = tree_min(tree.root);
	if(min != NULL)
		printf("min is %d\n",min->data);

	tnode_t * mx = tree_max(tree.root);
	if(mx != NULL)
		printf("max is %d\n",mx->data);
	

	tnode_t *s = tree_successor(min);
	tnode_t *pre = tree_predecessor(s);
	printf("successor of min is %d\n",s->data);
	printf("predecessor of s is %d\n",pre->data);


	tnode_t *pre2 = tree_predecessor(mx);
	tnode_t *s2 = tree_successor(pre2);
	printf("predecessor of max is %d\n",pre2->data);
	printf("successor of pre2 is %d\n",s2->data);

	tree_delete(&tree, min);
	printf("delete\n");
	inorder_walk_tree(tree.root,print_tnode); printf("\n");

	printf("deep walk\n");
	deep_walk(tree.root);
	tree_destroy(tree.root);
}
