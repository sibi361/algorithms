/*
Linked list implementation has to use malloc() since simple struct
node initialisation might not allocate new memory addresses
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_ node;
struct node_
{
    int data;
    node *next;
};

node *createNode(int data);
node *createListFromArray(int length, int array[]);
void traverseList(node *head);

void main()
{
    int test_array[] = {10, -3, 20, 0, 55};

    node *list = createListFromArray(
        sizeof(test_array) / sizeof(test_array[0]),
        test_array);

    traverseList(list);

    printf("\n");
}

node *createNode(int data)
{
    /*
    unlike local variables, variables initialised with malloc()
    are not destroyed after function exit
    they also have new memory addresses as compared to doing:
    node temp;
    */
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->next = NULL;
    return temp;
}

node *createListFromArray(int length, int array[])
{
    if (length == 0)
    {
        printf("Array should have at least one element\n");
        exit(0);
    }

    node *previousNode = createNode(array[0]);
    node *head = previousNode;

    for (int i = 1; i < length; i++)
    {
        node *currentNode = createNode(array[i]);
        previousNode->next = currentNode;
        previousNode = currentNode;
    }

    return head;
}

void traverseList(node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}
