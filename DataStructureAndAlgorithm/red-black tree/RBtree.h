/* RED-BLACK TREE
*  151008 정승미
* node를 하나씩 insert하여 red-black tree를 구현하고, node를 하나씩 delete함
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


int key_compare(KEY, KEY); // key 값 비교 함수
pnode node_search(pnode, KEY); // key값으로 해당 node를 찾는 함수
pnode node_create(KEY, VAL); // key값과 value값으로 node를 만드는 함수
pnode find_min(pnode);// tree의 min값을 찾는 함수
void node_print(pnode, int); // node를 print하는 함수 infix방식으로 print
pnode right_rotation(pnode); // right rotation 수행 함수
pnode left_rotation(pnode); // left rotation 수행 함수
pnode node_insert_fixup(pnode); // node insert한 후 red-black tree조건에 맞게 fixup하는 함수
pnode node_insert(pnode, pnode, int); // node insert 수행함수
pnode node_delete(pnode, pnode);// node delete수행함수
pnode node_transplant(pnode, pnode, pnode); // tree에서 해당 node를 지우고 그자리를 fixupnode로 바꿔주는 함수
pnode node_delete_fixup(pnode, pnode); // node를 delete한 후 red-black tree 조건에 맞게 fixup하는 함수
psearch_tree rbt_create(); // red-black tree create
void rbt_print(psearch_tree); // red-black tree print