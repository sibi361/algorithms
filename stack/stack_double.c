#include <stdio.h>

// double stack implementation by having the first stack start from
// the left side of the array and the second stack start from the
// right side of the array

// for overflow demonstration purpose
#define MAX_SIZE 5

int push_1(int[], int *, int);
int push_2(int[], int *, int);
int pop_1(int[], int *);
int pop_2(int[], int *);
int getSize_1(int);
int getSize_2(int);
int clearStack_1(int *);
int clearStack_2(int *);

void print_stack_1(int stack[], int top_1)
{
    for (int i = 0; i <= top_1; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

void print_stack_2(int stack[], int top_2)
{
    for (int i = MAX_SIZE - 1; i >= top_2; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

void main()
{
    int stack[MAX_SIZE];
    int top_1 = -1;
    int top_2 = MAX_SIZE;

    printf("\nInteger Double Stack Demonstration\n\n");

    int option, temp, output;
    while (option != 9)
    {
        // for debugging

        printf("\nStack 1:\n");
        print_stack_1(stack, top_1);
        printf("Stack 2:\n");
        print_stack_2(stack, top_2);
        printf("\n");

        printf("Available stack operations: \n\
        1 Push stack 1 \n\
        2 Push stack 2 \n\
        3 Pop stack 1 \n\
        4 Pop stack 2 \n\
        5 Get Size of stack 2 \n\
        6 Get Size of stack 1 \n\
        7 Clear stack 1 \n\
        8 Clear stack 2 \n\
        9 Exit \n");

        printf("# Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("# Enter element to push: ");
            scanf("%d", &temp);

            output = push_1(stack, &top_1, temp);
            if (output)
                printf("# %d pushed successfully to stack 1\n", temp);
            else
                printf("# ERROR: STACK OVERFLOW !!!\n");
            break;

        case 2:
            printf("# Enter element to push: ");
            scanf("%d", &temp);

            output = push_2(stack, &top_2, temp);
            if (output)
                printf("# %d pushed successfully to stack 2\n", temp);
            else
                printf("# ERROR: STACK OVERFLOW !!!\n");
            break;

        case 3:
            temp = pop_1(stack, &top_1);
            switch (temp)
            {
            case -99999:
                printf("# ERROR: STACK UNDERFLOW\n");
                break;
            default:
                printf("# popped %d from stack 1\n", temp);
            }
            break;

        case 4:
            temp = pop_2(stack, &top_2);
            switch (temp)
            {
            case -99999:
                printf("# ERROR: STACK UNDERFLOW\n");
                break;
            default:
                printf("# popped %d from stack 2\n", temp);
            }
            break;

        case 5:
            printf("# stack 1 size: %d\n", getSize_1(top_1));
            break;

        case 6:
            printf("# stack 2 size: %d\n", getSize_2(top_2));
            break;

        case 7:
            output = clearStack_1(&top_1);
            if (output)
                printf("# stack 1 has been cleared\n");
            else
                printf("# ERROR: stack 1 is already empty\n");
            break;

        case 8:
            output = clearStack_2(&top_2);
            if (output)
                printf("# stack 2 has been cleared\n");
            else
                printf("# ERROR: stack 2 is already empty\n");
            break;

        case 9:
            clearStack_1(&top_1);
            clearStack_2(&top_2);
            printf("# stack 1 has been cleared\n");
            printf("# stack 2 has been cleared\n");
            printf("# Exiting\n\n");
            break;

        default:
            printf("# INVALID OPTION\n");
        }
    }
}

int push_1(int stack[], int *top_1, int item)
{
    if (*top_1 == MAX_SIZE / 2) // stack overflow
        return 0;
    stack[++(*top_1)] = item;
    return 1;
}

int push_2(int stack[], int *top_2, int item)
{
    if (*top_2 == MAX_SIZE / 2) // stack overflow
        return 0;
    stack[--*top_2] = item;
    return 1;
}

int pop_1(int stack[], int *top_1)
{
    if (*top_1 == -1) // stack underflow
        return -99999;

    // prefix and postfix ops have higher precedence
    // than dereference operator
    return stack[(*top_1)--];
}

int pop_2(int stack[], int *top_2)
{
    if (*top_2 == MAX_SIZE) // stack underflow
        return -99999;

    // prefix and postfix ops have higher precedence
    // than dereference operator
    return stack[(*top_2)++];
}

int getSize_1(int top_1)
{
    return top_1 + 1;
}

int getSize_2(int top_2)
{
    return MAX_SIZE - top_2;
}

int clearStack_1(int *top_1)
{
    if (*top_1 == -1)
        return 0;
    *top_1 = -1;
    return 1;
}

int clearStack_2(int *top_2)
{
    if (*top_2 == MAX_SIZE)
        return 0;
    *top_2 = MAX_SIZE;
    return 1;
}
