#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
	int i;
	
	List * list = (List *) malloc(sizeof(List));
	if(!list)
	{
		printf("Allocation error \n");
		exit(1);
	}

	list->size = 0;
	list->first = NULL;

	for(i=0; i<9; i++)
	{
		printf("Enter stuff to add \n");
		Data * data = (Data *) malloc(sizeof(Data));
		input(data);
		insertFirst(list, *data);
	}

	Node * temp = NULL;
	Node * lynch = NULL;
	int len=0;

	for(temp = list->first; temp->next != NULL; temp = temp->next)
	{
		len++;

		if (len == 4)
			lynch = temp;
	}

	temp->next = lynch;

	printf("%d \n", isCycle(list));

	return 0;
}
