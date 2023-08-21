#include <stdio.h>

// deque i.e. double ended queue implemented using circular queue
// type: input restricted
// which means that stuff can be deleted from both front and rear
// end but can be inserted only from the rear

// for demonstration purpose
#define MAX_SIZE 5

int insert(int queue[], int front, int *rear, int item);
int delete(int queue[], int *front, int rear);
int delete_rear(int queue[], int front, int *rear);
int getSize(int front, int rear);
int isEmpty(int front, int rear);
int isFull(int front, int rear);
int resetQueue(int *front, int *rear);
void print_queue(int queue[], int front, int rear);

void main()
{
    int queue[MAX_SIZE];
    int front, rear, rear_front;
    front = rear = 0;

    printf("\nInteger Circular Queue Demonstration\n");

    int option, temp, output;
    while (option != 8)
    {
        print_queue(queue, front, rear); // for debugging
        printf("\n");

        printf("Available queue operations: \n\
        1 Insert \n\
        2 Delete \n\
        3 Delete Rear\n\
        4 Get Size \n\
        5 isEmpty \n\
        6 isFull \n\
        7 Reset \n\
        8 Exit \n");

        printf("# Enter option: ");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        case 1:
            printf("# Enter element to insert: ");
            scanf("%d", &temp);

            output = insert(queue, front, &rear, temp);
            if (output)
                printf("\n# %d inserted successfully\n", temp);
            else
                printf("\n# ERROR: QUEUE OVERFLOW\n");
            break;

        case 2:
            temp = delete (queue, &front, rear);
            switch (temp)
            {
            case -99999:
                printf("# ERROR: QUEUE UNDERFLOW\n");
                break;
            default:
                printf("# deleted %d from the front end\n", temp);
            }
            break;

        case 3:
            temp = delete_rear(queue, front, &rear);
            switch (temp)
            {
            case -99999:
                printf("# ERROR: QUEUE UNDERFLOW\n");
                break;
            default:
                printf("# deleted %d from the rear end\n", temp);
            }
            break;

        case 4:
            printf("# queue size: %d\n", getSize(front, rear));
            break;

        case 5:
            if (isEmpty(front, rear))
                printf("# queue is empty\n");
            else
                printf("# queue is NOT empty\n");
            break;

        case 6:
            if (isFull(front, rear))
                printf("# queue is full\n");
            else
                printf("# queue is NOT full\n");
            break;

        case 7:
            output = resetQueue(&front, &rear);
            if (output)
                printf("# queue has been reset\n");
            else
                printf("# ERROR: queue is already empty\n");
            break;

        case 8:
            resetQueue(&front, &rear);
            printf("# queue has been cleared\n");
            printf("# Exiting\n\n");
            break;

        default:
            printf("# INVALID OPTION\n");
        }
    }
}

int insert(int queue[], int front, int *rear, int item)
{
    *rear = (*rear + 1) % MAX_SIZE;

    if (*rear == front)
    { // queue overflow
        printf("#$$$ %d\n", *rear);
        *rear = (*rear - 1 + MAX_SIZE) % MAX_SIZE;
        return 0;
    }
    queue[*rear] = item;
    return 1;
}

int delete(int queue[], int *front, int rear)
{
    if (*front == rear) // queue underflow
        return -99999;

    // front being increased by one towards the right
    *front = (*front + 1) % MAX_SIZE;
    return queue[*front];
}

int delete_rear(int queue[], int front, int *rear)
{
    // notice that the variable being modified gets switched
    // for e.g. here in case of delete_rear() front becomes rear
    // this is obvious as the operation is being performed on the
    // conventionally opposite end

    if (front == *rear) // queue underflow
        return -99999;

    // rear being decreased by one towards the left
    *rear = (*rear - 1 + MAX_SIZE) % MAX_SIZE;
    return queue[*rear];
}

int getSize(int front, int rear)
{
    if (front <= rear)
        return rear - front;
    else
        return MAX_SIZE - front + rear;
}

int isEmpty(int front, int rear)
{
    if (getSize(front, rear) == 0)
        return 1;
    return 0;
}

int isFull(int front, int rear)
{
    if (getSize(front, rear) == MAX_SIZE - 1) // actual max size
        return 1;
    return 0;
}

int resetQueue(int *front, int *rear)
{
    if (*front == 0 && *rear == 0)
        return 0;
    *front = *rear = 0;

    return 1;
}

void print_queue(int queue[], int front, int rear)
{
    printf("front: %d rear: %d\n", front, rear);

    if (front == rear)
        return;
    if (front < rear)
        for (int i = front + 1; i <= rear; i++)
            printf("%d ", queue[i]);
    else
    {
        for (int i = front + 1; i < MAX_SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}
