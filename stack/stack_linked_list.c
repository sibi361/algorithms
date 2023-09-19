#include <stdio.h>
#include <stdlib.h>

// Stack using Singly Linked List instead of Array

// for demonstration purpose
#define MAX_SIZE 5
#define DUMMY_VALUE -98765

typedef struct node_ node;
struct node_
{
    int data;
    node *next;
};

node *createNode(int data);
node *initStackUsingLinkedList();
int getLinkedListSize(node *head, node *top);
node *insert(node *head, node *top, int index, int item);
node *append(node *head, node *top, int item);
void traverseLinkedList(node *head, node *top);
node *getPreviousNode(node *stack, node **n);

int push(node *stack, node **top, int item);
int pop(node *stack, node **top);
int getSize(node *stack, node *top);
int isEmpty(node *stack, node *top);
int isFull(node *stack, node *top);
int clearStack(node *stack, node **top);

void print_stack(node *stack, node *top)
{
    if (!isEmpty(stack, top))
        traverseLinkedList(stack, top);
    else
        printf("\n");
}

void main()
{
    node *stack, *top;
    stack = top = initStackUsingLinkedList();

    printf("\nInteger Stack Demonstration Using Linked List");

    int option, temp, output;
    while (option != 5)
    {
        print_stack(stack, top); // for debugging
        printf("\n");

        printf("Available stack operations: \n\
        1 Push \n\
        2 Pop \n\
        3 Clear \n\
        4 Get Size \n\
        5 Exit \n");

        printf("# Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("# Enter element to push: ");
            scanf("%d", &temp);

            output = push(stack, &top, temp);
            if (output)
            {
                printf("# %d pushed successfully\n", temp);
            }
            else
                printf("# ERROR: STACK OVERFLOW !!!\n");
            break;

        case 2:
            temp = pop(stack, &top);
            switch (temp)
            {
            case -99999:
                printf("# ERROR: STACK UNDERFLOW\n");
                break;
            default:
                printf("# popped %d\n", temp);
            }
            break;

        case 3:
            output = clearStack(stack, &top);
            if (output)
                printf("# stack has been cleared\n");
            else
                printf("# ERROR: stack is already empty\n");
            break;

        case 4:
            printf("# stack size: %d\n", getSize(stack, top));
            break;

        case 5:
            clearStack(stack, &top);
            printf("# stack has been cleared\n");
            printf("# Exiting\n\n");
            break;

        default:
            printf("# INVALID OPTION\n");
        }
    }
}

node *initStackUsingLinkedList()
{
    // dummy value
    return createNode(-98765);
}

int push(node *stack, node **top, int item)
{
    printf("%d\n", 3333);
    if (getLinkedListSize(stack, *top) == MAX_SIZE + 1) // stack overflow
        return 0;

    printf("%d\n", 111232);

    *top = append(stack, *top, item);
    return 1;
}

int pop(node *stack, node **top)
{
    if (*top == stack) // stack underflow
        return -99999;

    int temp = (*top)->data;
    *top = getPreviousNode(stack, top);
    printf("previous node: %d\n", (*top)->data);

    return temp;
}

int getSize(node *stack, node *top)
{
    return getLinkedListSize(stack, top) - 1;
}

int isEmpty(node *stack, node *top)
{
    if (top == stack)
        return 1;
    return 0;
}

int isFull(node *stack, node *top)
{
    if (!isEmpty(stack, top))
        return 1;
    return 0;
}

int clearStack(node *stack, node **top)
{
    if (isEmpty(stack, *top))
        return 0;
    *top = stack;
    return 1;
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

int getLinkedListSize(node *head, node *top)
{
    node *n = head;
    int i = 0;

    while (n->next != top && n->next != NULL)
    {
        printf("%d\n", n->data);

        n = n->next;
        i++;
    }

    return i;
}

node *insert(node *head, node *top, int index, int item)
{
    // returns pointer to head just in case element inserted at head

    if (index < 0 || index > getLinkedListSize(head, top))
    {
        printf("Given index %d outside range\n", index);
        exit(0);
    }

    node *n = head;
    int i = 1;
    node *newNode = createNode(item);

    if (index == 0)
        newNode->next = head;
    else
    {
        while (i++ < index)
            n = n->next;

        newNode->next = n->next;
        n->next = newNode;
    }

    return newNode;
}

node *append(node *head, node *top, int item)
{
    return insert(head, top, getLinkedListSize(head, top), item);
}

void traverseLinkedList(node *stack, node *top)
{
    node *n = stack;

    while (n != top)
    {
        if (n->data != DUMMY_VALUE)
            printf("%d ", n->data);
        n = n->next;
    }
    printf("\n\n");
}

node *getPreviousNode(node *stack, node **n)
{
    node *temp = stack;

    while (temp->next != *n)
        temp = temp->next;

    return temp;
}
