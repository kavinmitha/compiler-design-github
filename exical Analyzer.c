#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[200];
    int i = 0;

    printf("Enter a statement:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0')
    {
        if (isspace(input[i]))
        {
            i++;
        }
        else if (isalpha(input[i]) || input[i] == '_')
        {
            printf("IDENTIFIER: ");

            while (isalnum(input[i]) || input[i] == '_')
            {
                printf("%c", input[i]);
                i++;
            }

            printf("\n");
        }
        else if (isdigit(input[i]))
        {
            printf("CONSTANT: ");

            while (isdigit(input[i]))
            {
                printf("%c", input[i]);
                i++;
            }

            printf("\n");
        }
        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '/' ||
                 input[i] == '=')
        {
            printf("OPERATOR: %c\n", input[i]);
            i++;
        }
        else
        {
            i++;
        }
    }

    return 0;
}