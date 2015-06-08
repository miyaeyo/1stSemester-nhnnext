#include "RBtree.h"

/************************************************main****************************************************/
int main(){
	int numOfnode = 0;
	int i , j;
	/* key값을 random하게 받아서 하나씩 RB tree에 insert, delete 할 node의 index를 random하게 받아서 하나씩 delete*/
	int key[15];
	int delNodeIndex[8];
	int size = sizeof(key) / sizeof(int);
	int delSize = sizeof(delNodeIndex) / sizeof(int);
	
	psearch_tree rbt = rbt_create();
	pnode delNode;
	srand((unsigned)time(NULL));
	printf("[ ");
	for (i = 0; i < size; i++){
		key[i] = rand() % 100;  // key 값은 유일함
		j = 0;
		while (j < i){
			if (key[i] == key[j]){ 
				key[i] = rand() % 100;
				j = 0; continue;
			}
			j++;
		}
		
		printf("%d ", key[i]);
		rbt->root = node_insert(rbt->root, node_create(key[i], key[i]), numOfnode++); // 여기서는 일단 value를 key값이랑 동일하게 setting.
	}
	printf("]\n");
	puts("[Red-Black Tree]");
	rbt_print(rbt);  // 만들어진 RBtree print
	
	for (i = 0; i < delSize; i++){ // delete할 node의 갯수만큼 random하게 index 생성. delete가 잘 되는지 확인하기 위해
		delNodeIndex[i] = rand() % size;
		j = 0;
		while (j < i){
			if (delNodeIndex[i] == delNodeIndex[j]){
				delNodeIndex[i] = rand() % size;
				j = 0;
				continue;
			}
			j++;
		}
	}
	
	for (i = 0; i < delSize; i++){ 
		delNode = node_search(rbt->root, key[delNodeIndex[i]]); // 지우고자하는 key값으로 node를 찾음
		rbt->root = node_delete(rbt->root, delNode); // 지우고자하는 node를 delete
		printf("\n[key = %d node delete]\n", key[delNodeIndex[i]]);
		rbt_print(rbt); // delete후 결과 출력
	}
	

	return 0;
}
/********************************************key compare********************************************************/
int key_compare(KEY x, KEY y){
	return x - y;
}
/*************************************************node search***************************************************/
pnode node_search(pnode root, KEY key){
	if (root == NULL)
		return NULL;
	else if (key == root->k)
		return root;
	else if (key < root->k)
		return node_search(root->left, key);
	else
		return node_search(root->right, key);

}
/*********************************************find min*******************************************************/
pnode find_min(pnode root)
{
	if (root->left != NULL)
	{
		return find_min(root->left);
	}
	else
		return root;
}
/*************************************************node delete***************************************************/
pnode node_delete(pnode root, pnode n){
	BOOL nodeColor = n->red;
	pnode fixupNode, successor;
	
	if (n->left == NULL){
		fixupNode = n->right;
		root = node_transplant(root, n, fixupNode);
	}
	else if (n->right == NULL){
		fixupNode = n->left;
		root = node_transplant(root, n, fixupNode);
	}
	else{
		successor = find_min(n->right); 
		nodeColor = successor->red;
		fixupNode = successor->right;
		if (successor->parent == n){
			if (fixupNode)
				fixupNode->parent = successor;
		}
		else{
			root = node_transplant(root, successor, fixupNode);
			successor->right = n->right;
			successor->right->parent = successor;
		}
		root = node_transplant(root, n, successor);
		successor->left = n->left;
		successor->left->parent = successor;
		successor->red = n->red;
	}
	if (nodeColor == FALSE && fixupNode != NULL){
		root = node_delete_fixup(root, fixupNode);
	}
		
	free(n);
	return root;
}
/*********************************************node transplant*******************************************************/
pnode node_transplant(pnode root, pnode old, pnode new){
	if (old->parent == NULL)
		root = new;
	else if (old == old->parent->left)
		old->parent->left = new;
	else
		old->parent->right = new;
	
	if (new)
		new->parent = old->parent;
	
	return root;
}
/*******************************************node delete fixup*********************************************************/
pnode node_delete_fixup(pnode root, pnode n){
	pnode sibling;
	while (n != root && n->red == FALSE){
		if (n == n->parent->left){
			sibling = n->parent->right;
			if (sibling->red == TRUE){
				sibling->red = FALSE;
				n->parent->red = TRUE;
				root = left_rotation(root, n->parent);
				sibling = n->parent->right;
			}
			if (sibling->left != NULL && sibling->right !=NULL && sibling->left->red == FALSE && sibling->right->red == FALSE){
				sibling->red = TRUE;
				n = n->parent;
			}
			else if (sibling->right !=NULL && sibling->right->red == FALSE){
				sibling->left->red = FALSE;
				sibling->red = TRUE;
				root = right_rotation(root, sibling);
				sibling = n->parent->right;
			}
			if (n->parent){
				sibling->red = n->parent->red;
				n->parent->red = FALSE;
				sibling->right->red = FALSE;
				root = left_rotation(root, n->parent);
			}
			n = root;
		}
		else{
			sibling = n->parent->left;
			if (sibling->red == TRUE){
				sibling->red = FALSE;
				n->parent->red = TRUE;
				root = right_rotation(root, n->parent);
				sibling = n->parent->right;
			}
			if (sibling->right->red == FALSE && sibling->left->red == FALSE){
				sibling->red = TRUE;
				n = n->parent;
			}
			else if (sibling->left->red == FALSE){
				sibling->right->red = FALSE;
				sibling->red = TRUE;
				root = left_rotation(root, sibling);
				sibling = n->parent->left;
			}
			if (n->parent){
				sibling->red = n->parent->red;
				n->parent->red = FALSE;
				sibling->left->red = FALSE;
				root = right_rotation(root, n->parent);
			}
			n = root;
		}

	}
	n->red = FALSE;

	return root;
}
/**********************************************node create******************************************************/
pnode node_create(KEY k, VAL v){
	pnode n = (pnode)malloc(sizeof(struct node));
	n->k = k;
	n->v = v;
	n->red = TRUE;
	n->parent = n->left = n->right = NULL;
	return n;
}

/***********************************************node print*****************************************************/
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
/********************************************right rotation********************************************************/
pnode right_rotation(pnode root, pnode x){
	pnode y = x->left;
	x->left = y->right;
	if (y->right)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->right = x;
	x->parent = y;

	return root;

}
/***********************************************left rotation*****************************************************/
pnode left_rotation(pnode root, pnode x){
	pnode y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;

	return root;
}
/*******************************************node insert fixup*********************************************************/
pnode node_insert_fixup(pnode root, pnode n){
	pnode uncle;
	while (n->parent != NULL && n->parent->red == TRUE)
	{
		if (n->parent == n->parent->parent->left){
			uncle = n->parent->parent->right;
			if (uncle != NULL && uncle->red == TRUE){
				n->parent->red = FALSE;
				uncle->red = FALSE;
				n->parent->parent->red = TRUE;
				n = n->parent->parent;
			}
			else {
				if (n == n->parent->right){
					n = n->parent;
					root = left_rotation(root, n);
				}
				n->parent->red = FALSE;
				n->parent->parent->red = TRUE;
				root = right_rotation(root, n->parent->parent);
			}
		}
		else{
			uncle = n->parent->parent->left;
			if (uncle != NULL && uncle->red == TRUE){
				n->parent->red = FALSE;
				uncle->red = FALSE;
				n->parent->parent->red = TRUE;
				n = n->parent->parent;
			}
			else {
				if (n == n->parent->left){
					n = n->parent;
					root = right_rotation(root, n);
				}
				n->parent->red = FALSE;
				n->parent->parent->red = TRUE;
				root = left_rotation(root, n->parent->parent);
			}

		}
	}
	if (n->parent == NULL)
		n->red = FALSE;

	return root;
}
/***********************************************node insert*****************************************************/
pnode node_insert(pnode root, pnode n, int numOfnode){
	pnode parent = NULL;
	pnode current = root;
	int cmp;
	while (current){
		parent = current;
		cmp = key_compare(n->k, current->k);
		if (cmp < 0)
			current = current->left;
		else
			current = current->right;
	}
	n->parent = parent;
	
	if (parent == NULL)
		root = n;
	else if (cmp = key_compare(n->k, parent->k) < 0)
		parent->left = n;
	else
		parent->right = n;

	n->left = NULL;
	n->right = NULL;
	if (numOfnode == 0)
		n->red = FALSE;
	else if (numOfnode > 1)
		root = node_insert_fixup(root, n);

	return root;
}

psearch_tree rbt_create(){
	psearch_tree bst = (psearch_tree)malloc(sizeof(sizeof(struct search_tree)));
	bst->root = NULL;
	return bst;
}

void rbt_print(psearch_tree bst){
	node_print(bst->root, 0);
}

