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
node *createLinkedListFromUserInput();
int getLength(node *head);
node *insert(node *head, int index, int item);
void append(node *head, int item);
void traverseLinkedList(node *head);
node *getTail(node *head);
void traverseDoublyLinkedListBackwards(node *tail);
int getItemAtIndex(node *head, int index);
node *deleteIndex(node *head, int index);
node *deleteItem(node *head, int item);
int *search(node *head, int query);
int contains(node *head, int query);

void main()
{
    int get_index,
        insertion_index,
        insertion_item,
        deletion_index,
        deletion_item,
        searchQuery,
        *found_indices,
        search_i;

    int test_array[] = {5, 10, 15, 20, 0, -3, 55, 9};
    // int test_array[] = {-3};

    // creating
    node *list = createLinkedListFromArray(
        sizeof(test_array) / sizeof(test_array[0]),
        test_array);
    // node *list = createLinkedListFromUserInput();

    // traversing
    printf("Traversing Forwards:\n");
    traverseLinkedList(list);

    printf("Traversing Backwards:\n");
    traverseDoublyLinkedListBackwards(list);

    printf("Length of doubly linked list: %d\n\n", getLength(list));

    // fetching index
    get_index = 2;
    // printf("at index %d: %d\n\n", get_index, getItemAtIndex(list, get_index));

    // insert at head
    insertion_index = 0;
    insertion_item = 100;
    printf("Inserting %d at index %d\n", insertion_item, insertion_index);
    list = insert(list, insertion_index, insertion_item);
    printf("Length of doubly linked list: %d\n", getLength(list));
    traverseLinkedList(list);

    // insert at tail
    insertion_index = getLength(list);
    insertion_item = -67;
    printf("Inserting %d at index %d\n", insertion_item, insertion_index);
    list = insert(list, insertion_index, insertion_item);
    printf("Length of doubly linked list: %d\n", getLength(list));
    traverseLinkedList(list);

    // deletion
    deletion_index = 2;
    printf("deleting index %d\n", deletion_index);
    list = deleteIndex(list, deletion_index);
    printf("Length of doubly linked list: %d\n", getLength(list));
    traverseLinkedList(list);

    // deleting head
    deletion_index = 0;
    printf("deleting index %d\n", deletion_index);
    list = deleteIndex(list, deletion_index);
    printf("Length of doubly linked list: %d\n", getLength(list));
    traverseLinkedList(list);

    deletion_item = 55;
    printf("deleting item %d\n", deletion_item);
    list = deleteItem(list, deletion_item);
    printf("Length of doubly linked list: %d\n", getLength(list));
    traverseLinkedList(list);

    // search
    searchQuery = 20;
    if (!contains(list, searchQuery))
        printf("%d NOT found\n", searchQuery);
    else
    {
        found_indices = search(list, searchQuery);
        printf("%d found at indices:\n", searchQuery);
        search_i = 0;
        while (found_indices[search_i] != -1)
            printf("%d ", found_indices[search_i++]);
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

node *createLinkedListFromUserInput()
{
    int n, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    scanf("%d", &temp);
    node *head = initLinkedList(temp);

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        append(head, temp);
    }

    return head;
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

node *getTail(node *head)
{
    node *n = head;

    if (getLength(head) == 1)
        return head;

    do
        n = n->next;
    while (n->next != NULL);
    return n;
}

void traverseDoublyLinkedListBackwards(node *head)
{
    node *tail, *n = head;

    if (!head)
        return;

    if (!head->next)
    {
        printf("%d\n", head->data);
        return;
    }

    // get tail
    do
        n = n->next;
    while (n->next);

    do
        printf("%d ", n->data);
    while (n = n->previous);

    printf("\n\n");
}

int getItemAtIndex(node *head, int index)
{
    if (index < 0 || index > getLength(head) - 1)
    {
        printf("Given index %d outside range\n", index);
        exit(0);
    }

    node *n = head;
    int i = 0;

    if (index == 0)
        return head->data;
    else
        while (++i <= index)
            n = n->next;

    return n->data;
};

node *deleteIndex(node *head, int index)
{
    // returns pointer to head just in case head is deleted

    node *toBeDeleted;

    if (index < 0 || index > getLength(head) - 1)
    {
        printf("Given index %d outside range\n", index);
        exit(0);
    }

    node *n = head;
    int i = 1;

    if (index == 0)
        if (getLength(head) == 1)
        {
            printf("Cannot delete head when length = 1\n");
            exit(0);
        }
        else
            head = n->next;
    else
    {
        while (i++ < index)
            n = n->next;

        toBeDeleted = n->next;
        n->next = n->next->next;
        free(toBeDeleted);
    }

    return head;
}

node *deleteItem(node *head, int item)
{
    // deletes first match of item
    // returns pointer to head just in case head is deleted

    int *foundIndexes = search(head, item);

    if (foundIndexes[0] == -1)
        printf("%d NOT found\n", item);
    else
        head = deleteIndex(head, foundIndexes[0]);

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

int *search(node *head, int query)
{
    /*
    returns array containing indices of items which matching query
    last index will be -1
    first element being -1 indicates no match found
    */

    node *n = head;

    int i = 0,
        *found,
        found_i;

    i = found_i = 0;
    found = (int *)malloc(getLength(n));

    do
    {
        if (n->data == query)
            found[found_i++] = i;
        i++;
    } while ((n = n->next) != NULL);

    found[found_i] = -1;
    return found;
}

int contains(node *head, int query)
{
    if (search(head, query)[0] == -1)
        return 0;
    return 1;
}
