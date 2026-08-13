#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][20];
int top = -1;
int temp = 1;

void push(char *str)
{
    strcpy(stack[++top], str);
}

char* pop()
{
    return stack[top--];
}

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int main()
{
    char expr[100];
    char operators[100];
    int optop = -1;
    int i;

    printf("Enter expression: ");
    scanf("%s", expr);

    for (i = 0; expr[i] != '\0'; i++)
    {
        if (isalnum(expr[i]))
        {
            char operand[2];

            operand[0] = expr[i];
            operand[1] = '\0';

            push(operand);
        }
        else
        {
            while (optop >= 0 &&
                   precedence(operators[optop]) >= precedence(expr[i]))
            {
                char op = operators[optop--];
                char *b = pop();
                char *a = pop();

                char result[20];

                sprintf(result, "t%d", temp);

                printf("%s = %s %c %s\n",
                       result, a, op, b);

                push(result);
                temp++;
            }

            operators[++optop] = expr[i];
        }
    }

    while (optop >= 0)
    {
        char op = operators[optop--];
        char *b = pop();
        char *a = pop();

        char result[20];

        sprintf(result, "t%d", temp);

        printf("%s = %s %c %s\n",
               result, a, op, b);

        push(result);
        temp++;
    }

    return 0;
}