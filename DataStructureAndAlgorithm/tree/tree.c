#include <stdio.h>
#include <malloc.h>

typedef struct node 
{
	int val;
	struct node* left;
	struct node* right;
}Node;

Node* create_node(int val)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->right = NULL;
	node->left = NULL;
}

Node* add_node(Node* root, int val)
{
	if (val < root->val){
		if (root->left == NULL)
			root->left = create_node(val);
		else
			add_node(root->left, val);
	}
	else
	{
		if (root->right == NULL)
			root->right = create_node(val);
		else
			add_node(root->right, val);

	}
}

void print_tree(Node* n, int height) // infix style (cf. postfix, prefix)
{
	int i;
	if (n == NULL)
	{
		for (i = 0; i < height; i++){
			printf("	");
		}
		printf("(null)\n");
	}
	else
	{
		print_tree(n->left, height + 1);
		for (i = 0; i < height; i++){
			printf("	");
		}
		printf("%d\n", n->val);
		print_tree(n->right, height+1);
		
	}
}

Node* find_node(Node* root, int val)
{
	if (root == NULL)
		return NULL;
	else if (val == root->val)
		return root;
	else if (val < root->val)
		return find_node(root->left, val);
	else
		return find_node(root->right, val);
}

Node* find_min(Node* root)
{
	if (root->left != NULL)
	{
		return find_min(root->left);
	}
	else
		return root;
}

Node* del_node(Node* root, int val) 
{
	if (val == root->val)
	{
		if (root->left == NULL && root->right == NULL)
			return NULL;
		else if (root->left == NULL && root->right != NULL)
			return root->right;
		else if (root->left != NULL && root->right == NULL)
			return root->left;
		else
		{
			Node* min = find_min(root->right);
			min->right = del_node(root->right, min->val);
			min->left = root->left;
			root = min;
			return root;
		}
	}
	else if (val < root->val)
	{
		if (root->left == NULL)
			return NULL;
		else
		{
			root->left = del_node(root->left, val);
			return root;
		}
	}
	else if (val > root->val)
	{
		if (root->right == NULL)
			return NULL;
		else
		{
			root->right = del_node(root->right, val);
			return root;
		}
	}
	
}

int main()
{
	Node* n = create_node(5);
	Node* tmp;

	add_node(n, 2); 
	add_node(n, 12);
	add_node(n, -4);
	add_node(n, 3);
	add_node(n, 9);
	add_node(n, 21);
	add_node(n, 19);
	add_node(n, 25);
	tmp = find_node(n,3); // find node value = 3
	print_tree(tmp, 0);
	print_tree(n, 0); // print present tree
	n = del_node(n, 12); // delete node value = 12 
	print_tree(n, 0);// print after deletion
}

/////////////////////////////////////////////bst 추상화시킬수 있다.
struct student{
	long id;
	char name[256];
	char phone[256];
};

typedef struct student* ELEM;
typedef long KEY;

Nodeptr create_node(long id, char* name, char* phone){
	ELEM d = (ELEM)malloc(sizeof(struct student));
	d->id = id;
	strcpy(d->name, name);
	strcpy(d->phone, phone);
	Nodeptr node~~~~~
}
KEY elem_key(ELEM e){
	return e->id;
}

int key_compare(KEY x, KEY y)
{
	return x - y;
}
