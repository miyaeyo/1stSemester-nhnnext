/* RED-BLACK TREE
*  151008 ���¹�
* node�� �ϳ��� insert�Ͽ� red-black tree�� �����ϰ�, node�� �ϳ��� delete��
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char BOOL;
#define TRUE 1
#define FALSE 0
typedef int KEY;
typedef int VAL;
typedef struct node* pnode;
struct node{  
	KEY k;
	VAL v;
	BOOL red;
	pnode parent; 
	pnode left, right;
};
typedef struct search_tree* psearch_tree;
struct search_tree{
	pnode root;
};


int key_compare(KEY, KEY); // key �� �� �Լ�
pnode node_search(pnode, KEY); // key������ �ش� node�� ã�� �Լ�
pnode node_create(KEY, VAL); // key���� value������ node�� ����� �Լ�
pnode find_min(pnode);// tree�� min���� ã�� �Լ�
void node_print(pnode, int); // node�� print�ϴ� �Լ� infix������� print
pnode right_rotation(pnode); // right rotation ���� �Լ�
pnode left_rotation(pnode); // left rotation ���� �Լ�
pnode node_insert_fixup(pnode); // node insert�� �� red-black tree���ǿ� �°� fixup�ϴ� �Լ�
pnode node_insert(pnode, pnode, int); // node insert �����Լ�
pnode node_delete(pnode, pnode);// node delete�����Լ�
pnode node_transplant(pnode, pnode, pnode); // tree���� �ش� node�� ����� ���ڸ��� fixupnode�� �ٲ��ִ� �Լ�
pnode node_delete_fixup(pnode, pnode); // node�� delete�� �� red-black tree ���ǿ� �°� fixup�ϴ� �Լ�
psearch_tree rbt_create(); // red-black tree create
void rbt_print(psearch_tree); // red-black tree print