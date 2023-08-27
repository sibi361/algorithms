// Polish Notation
// Conversion of infix expression to reverse Polish i.e.
// postfix notation

// unfinished

#include <stdio.h>
#include <string.h>

int MAX_SIZE;

int push(char stack[], int *top, int item);
char pop(char stack[], int *top);
int is_operator(char operator);
int input_precedence(char literal);
int output_precedence(char literal);

void print_stack(char stack[], int top)
{
    printf("stack: ");
    for (int i = 0; i <= top; i++)
        printf("%c ", stack[i]);
    printf("\n");
}

void main()
{
    // char exp[1000]; // input infix expression
    // printf("\nEnter infix expression: ");
    // scanf("%[^\n]s", exp);
    char exp[] = "a*(b-c)"; // abc-*
                            // char exp[MAX_SIZE] = "a * b - c"; // ab*c-

    MAX_SIZE = strlen(exp);
    char exp_postfix[MAX_SIZE], temp;
    char stack[MAX_SIZE];
    stack[0] = '#';
    int top = 0, i = 0, j = 0;

    while ((temp = exp[i++]) != '\0')
    {
        printf("%s\n", exp_postfix);
        print_stack(stack, top);

        if (is_operator(temp))
            if (output_precedence(temp) > input_precedence(temp))
                exp_postfix[j++] = pop(stack, &top);
            else if (output_precedence(temp) == input_precedence(temp))
                pop(stack, &top);
            else
                push(stack, &top, temp);
        else
            exp_postfix[j++] = temp;
    }

    if (top != -1)
        exp_postfix[j++] = pop(stack, &top);

    exp_postfix[j] = '\0';
    printf("\nObtained postfix expression:\n%s\n\n", exp_postfix);
}

int push(char stack[], int *top, int item)
{
    if (*top == MAX_SIZE - 1) // stack overflow
        return 0;
    stack[++*top] = item;
    return 1;
}

char pop(char stack[], int *top)
{
    if (*top == -1) // stack underflow
        return '\0';
    // prefix and postfix ops have higher precedence
    // than dereference operator
    return stack[(*top)--];
}

int is_operator(char operator)
{
    switch (operator)
    {
    case '^':
    case '%':
    case '/':
    case '*':
    case '+':
    case '-':
    case ')':
    case '(':
        return 1;
    }
    return 0;
}

int input_precedence(char literal)
{
    switch (literal)
    {
    case ')':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 3;
    case '%':
    case '/':
    case '*':
        return 5;
    case '^':
        return 7;
        return 2;
    default:
        printf("Unknown literal: %c\n", literal);
    }
};

int output_precedence(char literal)
{
    switch (literal)
    {
    case '#': // placeholder for empty stack
        return -1;
    case '(':
        return 0;
    case '+':
    case '-':
        return 2;
    case '%':
    case '/':
    case '*':
        return 4;
    case '^':
        return 6;
    case ')':
        return 100;
    default:
        printf("Unknown literal: %c\n", literal);
    }
};
