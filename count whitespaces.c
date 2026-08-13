#include <stdio.h>

int main()
{
    char ch;
    int spaces = 0;
    int newlines = 0;

    printf("Enter text (press Ctrl+D to stop):\n");

    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ' || ch == '\t')
            spaces++;

        if (ch == '\n')
            newlines++;
    }

    printf("\nNumber of whitespaces: %d\n", spaces);
    printf("Number of newlines: %d\n", newlines);

    return 0;
}