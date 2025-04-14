#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

int opcheck(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int evaluatePostfix(char *postfix)
{
    int stack[MAX_EXPR_SIZE];
    int top = -1;
    int i, operand1, operand2, result;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            stack[++top] = postfix[i] - '0';
        }
        else if (isOperator(postfix[i]))
        {
            operand2 = stack[top--];
            operand1 = stack[top--];

            switch (postfix[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = 1;
                for (int j = 0; j < operand2; j++)
                {
                    result *= operand1;
                }
                break;
            }

            stack[++top] = result;
        }
    }

    return stack[top];
}

char *convert(char *infix)
{
    int i, j;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[MAX_EXPR_SIZE];
    int top = -1;

    for (i = 0, j = 0; i < len; i++)
    {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        if (isalnum(infix[i]))
        { // Use isalnum function
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top == -1 || stack[top] != '(')
            {
                free(postfix);
                return "Invalid Expression";
            }
            top--; // Pop the '(' from the stack.
        }
        else if (isOperator(infix[i]))
        {
            while (top > -1 && opcheck(stack[top]) >= opcheck(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }
    while (top > -1)
    {
        if (stack[top] == '(')
        {
            free(postfix);
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[MAX_EXPR_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    char *postfix = convert(infix);

    if (strcmp(postfix, "Invalid Expression") == 0)
    {
        printf("Invalid Expression\n");
    }
    else
    {
        printf("Postfix expression: %s\n", postfix);
        int result = evaluatePostfix(postfix);
        printf("Result: %d\n", result);
    }

    free(postfix);
    return 0;
}
