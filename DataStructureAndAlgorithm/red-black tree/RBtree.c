#include <stdio.h>
#include <malloc.h>

typedef struct node* pnode;
typedef unsigned char BOOL;
#define TRUE 1
#define FALSE 0
typedef int KEY;
typedef int VAL;

int key_compare(KEY x, KEY y){
	return x - y;
}

struct node{
	KEY k;
	VAL v;
	BOOL red;
	pnode parent; // parent node없이 해보는 방법도 생각해보기 pure 하게 functional
	pnode left, right;
};

pnode node_create(KEY k, VAL v){
	pnode n = (pnode)malloc(sizeof(struct node));
	n->k = k;
	n->v = v;
	n->red = TRUE;
	n->parent = n->left = n->right = NULL;
	return n;
}

void node_print(pnode root, int depth){
	if (root != NULL){
		node_print(root->left, depth + 1);
		for (int i = 0; i < depth; i++){
			printf("	");
		}
		printf("%c: %d\n", root->red ? 'R' : 'B', root->k);
		node_print(root->right, depth + 1);
	}
	else{
		for (int i = 0; i < depth; i++){
			printf("	");
		}
		printf("NIL\n");
	}
}

//pnode node_insert(pnode root, pnode n){ // 1. ordering invariance를 만족시키도록 insert //, 2. balancing invariance, 3. coloring invariance
//	if (root == NULL){
//		n->parent = NULL;
//		return n;
//	}
//	else{
//		int cmp = key_compare(n->k, root->k);
//		if (cmp < 0){
//			root->left = node_insert(root->left, n);
//			root->left->parent = root;
//			
//		}
//		else{
//			root->right = node_insert(root->right, n);
//			root->right->parent = root;
//		}
//		//node_insert_fixup(root, n);
//		return root;
//	}
//}
pnode right_rotation(pnode grandParent){
	pnode parent = grandParent->left;
	parent->right = grandParent;
	grandParent->left = parent->right;
	return parent;
}

pnode left_rotation(pnode grandparent){
	pnode parent = grandparent->right;
	parent->left = grandparent;
	grandparent->right = parent->left;
	return parent;
}

void color_flip(pnode root){
	if (root->right == NULL || root->left == NULL)
		return;
	else if (root->red == TRUE && root->right->red == TRUE && root->left->red == TRUE){
		if (root->parent != NULL)
			root->red = TRUE;
		root->right->red = FALSE;
		root->left->red = FALSE;
	}
}

//pnode find_uncle(pnode n){
//
//}

void node_insert_fixup(pnode root){
	
	// left-left
	if (root->left->red == TRUE && root->left->left->red == TRUE){
		root->red = TRUE;
		root->left->red = FALSE;
		root = right_rotation(root);
	}
	//right-right
	else if (root->right->red == TRUE && root->right->right == TRUE){
		root->red = TRUE;
		root->right->red = FALSE;
		root = left_rotation(root);
	}
	//left-right
	else if (root->left == TRUE && root->left->right == TRUE){
		root->red = TRUE;
		root->left->right->red = FALSE;
		root->left = left_rotation(root->left);
		root = right_rotation(root);
	}
	//right-left
	else if (root->right == TRUE && root->right->left == TRUE){
		root->red = TRUE;
		root->right->left = FALSE;
		root->right = right_rotation(root->right);
		root = left_rotation(root);
	}

}
pnode node_insert(pnode root, pnode n){
	if (root == NULL){
		n->parent = NULL;
		return root = n;
	}
	else{
		int cmp = key_compare(n->k, root->k);
		if (cmp < 0){
			root->left = node_insert(root->left, n);
			root->left->parent = root;			
		}
		else{
			root->right = node_insert(root->right, n);
			root->right->parent = root;
		}

		color_flip(root);
		node_insert_fixup(root);
	}

	
	//return root;
	
}

typedef struct search_tree* psearch_tree;
struct search_tree{
	pnode root;
};

psearch_tree bst_create(){
	psearch_tree bst = (psearch_tree)malloc(sizeof(sizeof (struct search_tree)));
	bst->root = NULL;
	return bst;
}

void bst_print(psearch_tree bst){
	node_print(bst->root, 0);
}

int main(){
	psearch_tree bst = bst_create();
	bst->root = node_insert(bst->root, node_create(1, 1));
	
	bst->root = node_insert(bst->root, node_create(2, 2));
	bst->root = node_insert(bst->root, node_create(3, 3));

	bst_print(bst);
	return 0;
}