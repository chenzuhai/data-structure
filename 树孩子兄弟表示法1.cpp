#include<iostream>
using namespace std;
typedef int Element;
typedef struct CSNode
{
	Element data;
	struct CSNode * firstchild;
	struct CSNode * nextsibling;
}*CSTree;

#define MAXSIZE 100
CSTree q[MAXSIZE];

int count = 0;

void init_cstree(CSTree &tree)
{
	tree->firstchild = NULL;
	tree->nextsibling = NULL;
}

void creat_cstree(CSTree &T)
{
	
}