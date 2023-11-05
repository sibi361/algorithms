/*
Split a given Singly Linked Lists into two separate lists
by alternately choosing elements
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
void split(node *head, node **head_a, node **head_b);

void main()
{
    int test_array[] = {1, 2, 3, 4, 5, 6, 7};

    node *list,
        *a, *b;

    // creating
    list = createLinkedListFromArray(
        sizeof(test_array) / sizeof(test_array[0]),
        test_array);
    a = b = NULL;

    printf("\nPrinting original linked list:\n");
    traverseLinkedList(list);

    split(list, &a, &b);

    printf("\nPrinting split linked list A:\n");
    traverseLinkedList(a);

    printf("\nPrinting split linked list B:\n");
    traverseLinkedList(b);
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
    int i = 0;

    while (n != NULL)
    {
        i++;
        n = n->next;
    }

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
    printf("\n");
}

void split(node *head, node **head_a, node **head_b)
{
    node *n, *n1, *n2;
    n = head;

    if (head)
    {
        *head_a = createNode(n->data);
        if (n = n->next)
            *head_b = createNode(n->data);
        else
            return;
    }
    else
        return;

    n1 = *head_a;
    n2 = *head_b;

    while (n->next && n->next->next)
    {
        n = n->next;
        n1 = n1->next = createNode(n->data);
        n = n->next;
        n2 = n2->next = createNode(n->data);
    }

    if (n = n->next)
        n1->next = createNode(n->data);
}
