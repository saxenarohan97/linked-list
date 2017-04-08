#include <stdio.h>

// The data present in each node of the linked list
typedef struct NodeData
{
        int num;
} Data;

// A node in the linked list
typedef struct SingleNode
{
        Data data;
        struct SingleNode * next;
} Node;

// A convenient wrapper to store the head of a linked list
typedef struct LinkedList
{
        int size;
        Node * first;
} List;

// Input data into a node of the linked list
void input(Data * data);

// Print the data in the node of a linked list
void printNode(Node * node);

// Inserts a given element at the beginning of 'list'
void insertFirst(List * list, Data element);

// Deletes the first element of 'list' and returns pointer to the deleted node
Node * deleteFirst(List * list);

// prints all the elements in 'list'
void printList (List * list);

// Searches for a given element in the linked list. Returns 1 if found, 0 otherwise
int search (List * list, Data element);

/* Deletes the first node in the list that contains the element = `element` and retuns it. If the element is not found it returns an error message saying element not found. */
Node * delete (List * list, Data element);

/* Checks if 'list' is a cycle, or contains a cycle. If it does, it returns the length of the entire linked list, else returns -1 */
int isCycle(List * list);
// Uses the 'hare and tortoise approach' to solve this

// Inserts a node with the data `element` at the end of the linked list
void insertLast(List * list, Data element);
