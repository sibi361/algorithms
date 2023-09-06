#include <stdio.h>

// for demonstration purpose
#define MAX_SIZE 5

int insert(int queue[], int *rear, int item);
int delete(int queue[], int *front, int rear);
int getSize(int front, int rear);
int isEmpty(int front, int rear);
int isFull(int front, int rear);
int resetQueue(int *front, int *rear);
void print_queue(int queue[], int front, int rear);

void print_queue(int queue[], int front, int rear)
{
    printf("front: %d rear: %d\n", front, rear);

    for (int i = front + 1; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void main()
{
    int queue[MAX_SIZE];
    int front, rear;
    front = rear = -1;

    printf("\nInteger Queue Demonstration\n");

    int option, temp, output;
    while (option != 7)
    {
        print_queue(queue, front, rear); // for debugging
        printf("\n");

        printf("Available queue operations: \n\
        1 Insert \n\
        2 Delete \n\
        3 Get Size \n\
        4 isEmpty \n\
        5 isFull \n\
        6 Reset \n\
        7 Exit \n");

        printf("# Enter option: ");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        case 1:
            printf("# Enter element to insert: ");
            scanf("%d", &temp);

            output = insert(queue, &rear, temp);
            if (output)
                printf("\n# %d inserted successfully\n", temp);
            else
                printf("\n# ERROR: QUEUE OVERFLOW !!!\n");
            break;

        case 2:
            temp = delete (queue, &front, rear);
            switch (temp)
            {
            case -99999:
                printf("# ERROR: QUEUE UNDERFLOW\n");
                break;
            default:
                printf("# deleted %d\n", temp);
            }
            break;

        case 3:
            printf("# queue size: %d\n", getSize(front, rear));
            break;

        case 4:
            if (isEmpty(front, rear))
                printf("# queue is empty\n");
            else
                printf("# queue is NOT empty\n");
            break;

        case 5:
            if (isFull(front, rear))
                printf("# queue is full\n");
            else
                printf("# queue is NOT full\n");
            break;

        case 6:
            output = resetQueue(&front, &rear);
            if (output)
                printf("# queue has been reset\n");
            else
                printf("# ERROR: queue is already empty\n");
            break;

        case 7:
            resetQueue(&front, &rear);
            printf("# queue has been cleared\n");
            printf("# Exiting\n\n");
            break;

        default:
            printf("# INVALID OPTION\n");
        }
    }
}

int insert(int queue[], int *rear, int item)
{
    if (*rear == MAX_SIZE - 1) // queue overflow
        return 0;
    queue[++*rear] = item;
    return 1;
}

int delete(int queue[], int *front, int rear)
{
    if (*front == rear) // queue underflow
        return -99999;
    return queue[++*front];
}

int getSize(int front, int rear)
{
    return rear - front;
}

int isEmpty(int front, int rear)
{
    if (getSize(front, rear) == 0)
        return 1;
    return 0;
}

int isFull(int front, int rear)
{
    if (getSize(front, rear) == MAX_SIZE || front == MAX_SIZE - 1)
        return 1;
    return 0;
}

int resetQueue(int *front, int *rear)
{
    if (*rear == -1)
        return 0;
    *front = *rear = -1;

    return 1;
}
