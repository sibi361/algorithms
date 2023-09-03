#include <stdio.h>
#include <stdlib.h>

typedef struct node_ node;
struct node_
{
    node *previous;
    int data;
    node *next;
};

node *createNode(node *previous, int data);
node *createListFromArray(int length, int array[]);
node *getTail(node *head);
void traverseListForwards(node *head);
void traverseListBackwards(node *tail);
int getLength(node *head);
int *search(node *head, int query);
int contains(node *head, int query);

void main()
{
    int test_array[] = {5, 10, 15, 20, 0, -3, 55, 9},
        searchQuery,
        *found_indexes,
        search_i;

    node *list = createListFromArray(
        sizeof(test_array) / sizeof(test_array[0]),
        test_array);

    printf("\nTraversing Forwards:\n");
    traverseListForwards(list);

    node *listTail = getTail(list);

    printf("\nTraversing Backwards:\n");
    traverseListBackwards(listTail);

    printf("\nLength of doubly linked list: %d\n\n", getLength(list));

    // search
    searchQuery = 15;
    found_indexes = search(list, searchQuery);

    if (found_indexes[0] == -1)
        printf("%d NOT found\n", searchQuery);
    else
    {
        printf("%d found at the following indexes:\n", searchQuery);
        search_i = 0;
        while (found_indexes[search_i] != -1)
            printf("%d ", found_indexes[search_i++]);
        printf("\n");
    }

    printf("\ncontains(%d): %d\n", 2, contains(list, 2));
    printf("contains(%d): %d\n", -3, contains(list, -3));

    printf("\n");
}

node *createNode(node *previous, int data)
{
    /*
    unlike local variables, variables initialised with malloc()
    are not destroyed after function exit
    they also have new memory addresses as compared to doing:
    node temp;
    */
    node *temp = (node *)malloc(sizeof(node));

    temp->previous = previous;
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

    node *previousNode = createNode(NULL, array[0]);
    node *head = previousNode;

    for (int i = 1; i < length; i++)
    {
        node *currentNode = createNode(previousNode, array[i]);
        previousNode->next = currentNode;
        previousNode = currentNode;
    }

    return head;
}

node *getTail(node *n)
{
    do
        n = n->next;
    while (n->next != NULL);
    return n;
}

void traverseListForwards(node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void traverseListBackwards(node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->previous;
    }
    printf("\n");
}

int getLength(node *n)
{
    int length = 1;
    while ((n = n->next) != NULL)
        length++;
    return length;
}

int *search(node *n, int query)
{
    int i = 0,
        *found,
        found_i;

    i = found_i = 0;
    found = (int *)malloc(getLength(n));

    while (n != NULL)
    {
        if (n->data == query)
            found[found_i++] = i;
        n = n->next;
        i++;
    }

    found[found_i] = -1;
    return found;
}

int contains(node *n, int query)
{
    while (n != NULL)
    {
        if (n->data == query)
            return 1;
        n = n->next;
    }
    return 0;
}
