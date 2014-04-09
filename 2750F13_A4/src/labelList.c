#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "labelList.h"
#include "common.h"
#include "arch.h"
/*
struct labelOrbegin
{
	char * string;
	int line;
	struct labelOrbegin * next;
};
typedef struct labelOrbegin lNode;

struct labelList
{
	lNode * head;
	lNode * tail;
	int size;
};
typedef struct labelList lList;


*/

lList * createList ()
{
	lList * theList;
	theList = malloc(sizeof(lList));
	if(theList == NULL)
	{
		printf("Error: No memory for theList.\n");
		return theList;
	}
	theList->head = NULL;
	theList->head = initNode("~dummy~", -1);
	theList->tail = NULL;
	theList->size = 0;
	return theList;
}

lNode * initNode(char * label, int line)
{
	lNode * newNode = malloc(sizeof(lNode));
	newNode->string = malloc(sizeof(char)*strlen(label)+1);
	strcpy(newNode->string, label);
	newNode->line = line;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

int addNode(lList * theList, char * label, int line)
{
	lNode * newNode;
	newNode = initNode(label, line);
	newNode->next = theList->head->next;
	theList->head->next = newNode;
	if(newNode->next != NULL)
	{
		newNode->next->prev = newNode;
	}
	return 0;
}

int printList(lList * theList)
{
	lNode * temp;
	temp = theList->head;
	while(temp != NULL)
	{
		printf("\n\nLabel: %s\nLine #: %d\n",temp->string, temp->line);
		temp = temp->next;
	}
	return 0;	
}
