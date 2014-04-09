#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "common.h"
#include "arch.h"


struct labelOrbegin
{
	char * string;
	int line;
	struct labelOrbegin * next;
	struct labelOrbegin * prev;
};
typedef struct labelOrbegin lNode;

struct labelList
{
	lNode * head;
	lNode * tail;
	int size;
};
typedef struct labelList lList;


lList * createList ();

lNode * initNode(char *, int);

int addNode(lList * theList, char * label, int line);

int printList(lList * theList);
