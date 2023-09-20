/*
Linked list implementation has to use malloc() since simple struct
node initialisation might not allocate new memory addresses
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
    int data;
    node *link;
};

node *createNode(int data);
node *initLinkedList(int firstDataElement);
node *createLinkedListFromArray(int length, int array[]);
node *createLinkedListFromUserInput();
int getLength(node *head);
node *insert(node *head, int index, int item);
void append(node *head, int item);
void traverseLinkedList(node *head);
node *reverseLinkedList(node *oldHead);

void main()
{
    int test_array[] = {-3, -2, -1, 0, 1, 2};

    // creating
    node *list = createLinkedListFromArray(
        sizeof(test_array) / sizeof(test_array[0]),
        test_array);

    // traversing
    printf("\nPrinting linked list:\n");
    traverseLinkedList(list);

    // reversing
    node *reversedList = reverseLinkedList(list);

    printf("\nLinked list after reversing:\n");
    traverseLinkedList(reversedList);
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
    temp->link = NULL;
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

    while ((n = n->link) != NULL)
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
        newNode->link = head;
        head = newNode;
    }
    else
    {
        while (i++ < index)
            n = n->link;

        newNode->link = n->link;
        n->link = newNode;
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
        n = n->link;
    }
    printf("\n\n");
}

node *reverseLinkedList(node *oldHead)
{
    node *n, *prev, *next;

    n = oldHead;
    prev = NULL; // tail's link in the reversed list

    do
    {
        // storing current node's forward link temporarily
        next = n->link;

        // reversing current node's link
        n->link = prev;

        // storing current node as the previous node for
        // the following iteration
        prev = n;

    } while ((n = next)->link != NULL);
    n->link = prev;

    return n; // new head
}
