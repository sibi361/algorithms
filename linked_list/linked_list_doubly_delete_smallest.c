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
node *initLinkedList(int firstDataElement);
node *createLinkedListFromArray(int length, int array[]);
int getLength(node *head);
node *insert(node *head, int index, int item);
void append(node *head, int item);
void traverseLinkedList(node *head);
node *deleteSmallest(node *head);

void main()
{
    int test_array[] = {5, 10, 15, 20, 0, -3, 55, 9};
    // int test_array[] = {5};

    // creating
    node *list = createLinkedListFromArray(
        sizeof(test_array) / sizeof(test_array[0]),
        test_array);

    printf("\nOriginal list:\n");
    traverseLinkedList(list);

    list = deleteSmallest(list);

    printf("List after deleting smallest element:\n");
    traverseLinkedList(list);
}

node *createNode(node *previous, int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->previous = previous;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node *initLinkedList(int firstDataElement)
{
    return createNode(NULL, firstDataElement);
}

node *createLinkedListFromArray(int length, int array[])
{
    if (length == 0)
    {
        printf("Array should have at least one element\n");
        exit(0);
    }

    node *head = initLinkedList(array[0]);

    for (int i = 1; i < length; i++)
        append(head, array[i]);

    return head;
}

int getLength(node *head)
{
    node *n = head;
    int length = 1;

    while ((n = n->next) != NULL)
        length++;

    return length;
}

node *insert(node *head, int index, int item)
{
    // returns pointer to head just in case element inserted at head

    if (index < 0 || index > getLength(head))
    {
        printf("Given index %d outside range\n", index);
        exit(0);
    }

    node *n = head;
    int i = 1;

    if (index == 0)
    {
        node *newNode = createNode(NULL, item);
        newNode->next = head;
        head = newNode;
    }
    else
    {
        while (i++ < index)
            n = n->next;

        node *newNode = createNode(n, item);
        newNode->next = n->next;
        n->next = newNode;
    }

    return head;
}

void append(node *head, int item)
{
    insert(head, getLength(head), item);
}

void traverseLinkedList(node *head)
{
    node *n = head;

    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n\n");
}

node *deleteSmallest(node *head)
{
    if (!head || !head->next)
    {
        free(head);
        return NULL;
    }

    node *n, *smallest, *toDelete;
    n = smallest = head;

    // finding smallest node
    while (n = n->next)
        if (n->data < smallest->data)
            smallest = n;

    if (smallest->previous)
        smallest->previous->next = smallest->next;
    else // if head is the smallest element
    {
        head->next->previous = NULL;
        head = head->next;
    }

    if (smallest->next)
        smallest->next->previous = smallest->previous;
    else // if tail is the smallest element
        smallest->previous->next = NULL;

    free(smallest);
    return head;
}
