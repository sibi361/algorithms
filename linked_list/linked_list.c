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
int getLength(node *head);
int *search(node *head, int query);
int contains(node *head, int query);

void main()
{
    int test_array[] = {-3, 10, -3, 20, 0, -3, 55, -3},
        searchQuery,
        *found_indexes,
        search_i;

    node *list = createListFromArray(
        sizeof(test_array) / sizeof(test_array[0]),
        test_array);

    printf("Printing linked list:\n");
    traverseList(list);

    printf("\nLength of linked list: %d\n\n", getLength(list));

    // search
    searchQuery = -3;
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

int getLength(node *n)
{
    int i = 1;
    while ((n = n->next) != NULL)
        i++;
    return i;
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
