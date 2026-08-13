#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[500];
    int i = 0;

    printf("Enter a statement:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0')
    {
        /* Ignore spaces, tabs and new lines */
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
        {
            i++;
        }

        /* Ignore single-line comments */
        else if (input[i] == '/' && input[i + 1] == '/')
        {
            break;
        }

        /* Ignore multi-line comments */
        else if (input[i] == '/' && input[i + 1] == '*')
        {
            i += 2;

            while (input[i] != '\0' &&
                   !(input[i] == '*' && input[i + 1] == '/'))
            {
                i++;
            }

            if (input[i] != '\0')
                i += 2;
        }

        else
        {
            printf("%c", input[i]);
            i++;
        }
    }

    printf("\n");

    return 0;
}