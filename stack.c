#include <stdio.h>

// for demonstration purpose
#define MAX_SIZE 5

int push(int[], int *, int);
int pop(int[], int *);
int getSize(int);
int isEmpty(int[], int);
int isFull(int[], int);
int clearStack(int *);

void print_stack(int stack[], int top)
{
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

void main()
{
    int stack[MAX_SIZE];
    int top = -1;

    printf("\nInteger Stack Demonstration");

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
                printf("# %d pushed successfully\n", temp);
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
            output = clearStack(&top);
            if (output)
                printf("# stack has been cleared\n");
            else
                printf("# ERROR: stack is already empty\n");
            break;

        case 4:
            printf("# stack size: %d\n", getSize(top));
            break;

        case 5:
            clearStack(&top);
            printf("# stack has been cleared\n");
            printf("# Exiting\n\n");
            break;

        default:
            printf("# INVALID OPTION\n");
        }
    }
}

int push(int stack[], int *top, int item)
{
    if (*top == MAX_SIZE - 1) // stack overflow
        return 0;
    stack[++*top] = item;
    return 1;
}

int pop(int stack[], int *top)
{
    if (*top == -1) // stack underflow
        return -99999;

    // prefix and postfix ops have higher precedence
    // than dereference operator
    return stack[(*top)--];
}

int getSize(int top)
{
    return top + 1;
}

int isEmpty(int stack[], int top)
{
    if (getSize(top) == 0)
        return 1;
    return 0;
}

int isFull(int stack[], int top)
{
    if (getSize(top) == MAX_SIZE)
        return 1;
    return 0;
}

int clearStack(int *top)
{
    if (*top == -1)
        return 0;
    *top = -1;
    return 1;
}
