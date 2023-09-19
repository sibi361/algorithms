/*
Concatenation of two given Linked Lists
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
node *initLinkedList(int firstDataElement);
node *createLinkedListFromArray(int length, int array[]);
int getLength(node *head);
node *insert(node *head, int index, int item);
void append(node *head, int item);
void traverseLinkedList(node *head);
void concat(node *head_a, node *head_b);

void main()
{
    int test_array_a[] = {-3, 2};
    int test_array_b[] = {10, 20, -99};

    // creating
    node *list_a = createLinkedListFromArray(
        sizeof(test_array_a) / sizeof(test_array_a[0]),
        test_array_a);
    node *list_b = createLinkedListFromArray(
        sizeof(test_array_b) / sizeof(test_array_b[0]),
        test_array_b);

    // traversing
    printf("\nPrinting linked list A:\n");
    traverseLinkedList(list_a);
    printf("Length of linked list: %d\n\n", getLength(list_a));

    printf("\nPrinting linked list B:\n");
    traverseLinkedList(list_b);
    printf("Length of linked list: %d\n\n", getLength(list_b));

    concat(list_a, list_b);

    printf("\nPrinting linked list A after concatenating with linked list B:\n");
    traverseLinkedList(list_a);
    printf("Length of linked list: %d\n\n", getLength(list_a));

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

node *initLinkedList(int firstDataElement)
{
    return createNode(firstDataElement);
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
    int i = 1;

    while ((n = n->next) != NULL)
        i++;

    return i;
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
    node *newNode = createNode(item);

    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        while (i++ < index)
            n = n->next;

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

void concat(node *head_a, node *head_b)
{
    node *n = head_a;

    while (n->next != NULL)
        n = n->next;

    n->next = head_b;
}
