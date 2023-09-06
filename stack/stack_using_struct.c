#include <stdio.h>

// for demonstration purpose
#define MAX_SIZE 5

typedef struct
{
    int stack[MAX_SIZE];
    int top;

} Stack;

int push(Stack *, int);
int pop(Stack *);
int getSize(Stack);
int isFull(Stack);
int clearStack(Stack *);

void print_stack(Stack s, int top)
{
    for (int i = 0; i <= top; i++)
        printf("%d ", s.stack[i]);
    printf("\n");
}

void main()
{
    printf("\nInteger Stack Demonstration");

    Stack s;
    s.top = -1;

    int option, temp, output;
    while (option != 5)
    {
        print_stack(s, s.top); // for debugging
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

            output = push(&s, temp);
            if (output)
                printf("# %d pushed successfully\n", temp);
            else
                printf("# ERROR: STACK OVERFLOW !!!\n");
            break;

        case 2:
            temp = pop(&s);
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
            output = clearStack(&s);
            if (output)
                printf("# stack has been cleared\n");
            else
                printf("# ERROR: stack is already empty\n");
            break;

        case 4:
            printf("# stack size: %d\n", getSize(s));
            break;

        case 5:
            clearStack(&s);
            printf("# stack has been cleared\n");
            printf("# Exiting\n\n");
            break;

        default:
            printf("# INVALID OPTION\n");
        }
    }
}

int push(Stack *stack, int item)
{
    if (stack->top == MAX_SIZE - 1) // stack overflow
        return 0;
    stack->stack[++stack->top] = item;
    return 1;
}

int pop(Stack *stack)
{
    if (stack->top == -1) // stack underflow
        return -99999;

    // unlike the dereference operator (*), arrow operator has higher
    // precedence than the prefix and postfix ops
    return stack->stack[stack->top--];
}

int getSize(Stack stack)
{
    return stack.top + 1;
}

int isEmpty(Stack stack)
{
    if (getSize(stack) == 0)
        return 1;
    return 0;
}

int isFull(Stack stack)
{
    if (getSize(stack) == MAX_SIZE)
        return 1;
    return 0;
}

int clearStack(Stack *stack)
{
    if (stack->top == -1)
        return 0;
    stack->top = -1;
    return 1;
}
