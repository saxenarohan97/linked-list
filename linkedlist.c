/* NOTE: Have a look at linkedlist.h to see what each method does
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void input(Data * data)
{
	printf("Enter number: ");
	scanf("%d", &(data->num));
}

void printNode(Node * node)
{
	printf("%d", (node->data).num);
}

void printList(List * list)
{
	Node * temp = NULL;

	for(temp = list->first; temp!=NULL; temp=temp->next)
	{
		printNode(temp);
		printf("\t");
	}

	if (!list->first)
		printf("List is empty");

	printf("\n");
}

void insertFirst(List * list, Data element)
{
	Node * newNode = (Node *) malloc(sizeof(Data));

	if(!newNode)
	{
		printf("Allocation error \n");
		exit(1);
	}

	newNode->data = element;
	newNode->next = list->first;
	list->first = newNode;

	printList(list);
}

void insertLast(List * list, Data element)
{
	Node * newNode = (Node *) malloc(sizeof(Data));

        if(!newNode)
        {
                printf("Allocation error \n");
                exit(1);
        }

	newNode->data = element;
	newNode->next = NULL;

	if(!(list->first))
	{
		list->first = newNode;
		return;
	}

	Node * temp;

	for(temp = list->first; (temp->next) != NULL; )
		temp = temp->next;

	temp->next = newNode;

	printList(list);
}

Node * deleteFirst(List * list)
{
	Node * deletedElement = list->first;

	if (deletedElement)
		list->first = (list->first)->next;

	printList(list);

	return deletedElement;
}

int isEqual(Data d1, Data d2)
{
	if ( d1.num == d2.num )
		return 1;

	return 0;
}

int search(List * list, Data element)
{
	Node * temp = NULL;

	for(temp=list->first; temp!=NULL; temp = temp->next)
	{
		if ( isEqual(temp->data, element) )
			return 1;
	}

	return 0;
}

Node * delete(List * list, Data element)
{
	Node * del = NULL;
	Node * prev = NULL;

	for(del=list->first; del!=NULL; prev = del, del = del->next)
	{
		if (isEqual( del->data, element ))
			break;
	}

	if (!del)
		return NULL;

	if (del == list->first)
		return deleteFirst(list);

	prev->next = del->next;
	printList(list);

	return del;
}

int isCycle(List * list)
{
	if (! (list->first) )
	{
		printf("The list is empty \n");
		exit(1);
	}

	Node * hare;
	Node * tor;
	int len = 0;
	int i = 0;

	for(hare=tor=list->first; hare != NULL && (hare == list->first || hare != tor); hare = (hare->next)->next, tor = tor->next)
		i++;

	if (!hare)
		return -1;

	for(tor = list->first; hare != tor; tor=tor->next, hare = hare->next)
		i++;

	for(hare = list->first; hare != tor; hare = hare->next, len++)
		i++;

	do
	{
		len++;
		hare = hare->next;
	} while(hare != tor);

	return len;
}
