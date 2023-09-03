#include <stdio.h>
#include <stdlib.h>

typedef struct node_ node;

struct node_
{
    int data;
    node *next;
};

node createLFromArray(int length, int array[]);
void traverseL(node head);

void main()
{
    int test_array[] = {10, -3, 20, 0, 55};
    node list = createLFromArray(
        sizeof(test_array) / sizeof(test_array[0]),
        test_array);

    traverseL(list);
}

node createLFromArray(int length, int array[])
{
    node n;

    if (length == 0)
    {
        printf("Array should have at least one element");
        exit(0);
    }

    n.data = array[0];
    n.next = NULL;
    node head = n;

    for (int i = 1; i < length; i++)
    {
        node temp;
        temp.data = array[i];
        temp.next = NULL;
        n.next = &temp;
        // printf("%u %u\n", &temp, n.next);

        n = temp;
    }

    return head;
}

void traverseL(node n)
{
    do
    {
        // printf("%d ", n.data);
        printf("nextL %u\n", n.next);
        break;
        n = *(n.next);
        printf("%d\n", 3333);
    } while (n.next != NULL);
}
