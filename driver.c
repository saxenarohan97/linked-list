/* An illustration on how to use the linkedlist implementation */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
	int i;

	List * list = (List *) malloc(sizeof(List));
	list->size = 0;
	list->first = NULL;

	for(i=0; i<5; i++)
	{
		Data * temp = (Data *) malloc(sizeof(Data));
		input(temp);
		insertLast(list, *temp);
	}

	for(i=0; i<3; i++)
		deleteFirst(list);

	Data * temp = (Data *) malloc(sizeof(Data));
	if(temp == NULL)
	{
		printf("Allocation error \n");
		exit(1);
	}

	printf("Enter element to search for: \n");
	input(temp);

	printf("%d \n", search(list, *temp));

	printf("Enter number to delete: ");

	temp = (Data *) malloc (sizeof(Data));
	input(temp);

	delete(list, *temp);

	return 0;
}
