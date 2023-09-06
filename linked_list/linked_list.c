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
node *initLinkedList(int firstDataElement);
node *createLinkedListFromArray(int length, int array[]);
node *createLinkedListFromUserInput();
int getLength(node *head);
node *insert(node *head, int index, int item);
void append(node *head, int item);
int getIndex(node *head, int index);
node *deleteIndex(node *head, int index);
node *deleteItem(node *head, int item);
void traverseLinkedList(node *head);
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
        *found_indexes,
        search_i;

    int test_array[] = {-3, -2, -1, 0, 1, 2};

    // creating
    node *list = createLinkedListFromArray(
        sizeof(test_array) / sizeof(test_array[0]),
        test_array);
    // node *list = createLinkedListFromUserInput();

    // traversing
    printf("\nPrinting linked list:\n");
    traverseLinkedList(list);
    printf("Length of linked list: %d\n\n", getLength(list));

    // fetching index
    get_index = 2;
    printf("index %d: %d\n\n", get_index, getIndex(list, get_index));

    // insert at head
    insertion_index = 0;
    insertion_item = 100;
    printf("Inserting %d at index %d\n", insertion_item, insertion_index);
    list = insert(list, insertion_index, insertion_item);
    printf("Length of linked list: %d\n", getLength(list));
    traverseLinkedList(list);

    // deletion
    deletion_index = 2;
    printf("deleting index %d\n", deletion_index);
    list = deleteIndex(list, deletion_index);
    printf("Length of linked list: %d\n", getLength(list));
    traverseLinkedList(list);

    deletion_item = 100;
    printf("deleting item %d\n", deletion_item);
    list = deleteItem(list, deletion_item);
    printf("Length of linked list: %d\n", getLength(list));
    traverseLinkedList(list);

    // search
    searchQuery = 12;
    found_indexes = search(list, searchQuery);

    if (found_indexes[0] == -1)
        printf("%d NOT found\n", searchQuery);
    else
    {
        printf("%d found at indexes:\n", searchQuery);
        search_i = 0;
        while (found_indexes[search_i] != -1)
            printf("%d ", found_indexes[search_i++]);
        printf("\n");
    }

    printf("\ncontains(%d): %d\n", 2, contains(list, 2));
    printf("contains(%d): %d\n", -30, contains(list, -30));

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

node *initLinkedList(int firstDataElement)
{
    node *head = createNode(firstDataElement);
    return head;
}

int getLength(node *head)
{
    node *n = head;
    int i = 1; // head always exists

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
    int i = 1; // head always exists
    node *currentNode = createNode(item);

    if (index == 0)
    {
        currentNode->next = head;
        head = currentNode;
    }
    else
    {
        while (i++ < index)
            n = n->next;

        currentNode->next = n->next;
        n->next = currentNode;
    }

    return head;
}

void append(node *head, int item)
{
    insert(head, getLength(head), item);
}

int getIndex(node *head, int index)
{
    // returns pointer to head just in case head is deleted

    if (index < 0 || index > getLength(head) - 1)
    {
        printf("Given index %d outside range\n", index);
        exit(0);
    }

    node *n = head;
    int i = 0; // head always exists

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

    if (index < 0 || index > getLength(head) - 1)
    {
        printf("Given index %d outside range\n", index);
        exit(0);
    }

    node *n = head;
    int i = 1; // head always exists

    if (index == 0)
        head = n->next;
    else
    {
        while (i++ < index)
            n = n->next;

        n->next = n->next->next;
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

int *search(node *head, int query)
{
    node *n = head;

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

int contains(node *head, int query)
{
    node *n = head;

    while (n != NULL)
    {
        if (n->data == query)
            return 1;
        n = n->next;
    }

    return 0;
}
