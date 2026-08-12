#include <stdio.h>

int main()
{
    char str[100];

    printf("Enter a line: ");
    fgets(str, 100, stdin);

    if (str[0] == '/' && (str[1] == '/' || str[1] == '*'))
        printf("It is a Comment");
    else
        printf("It is Not a Comment");

    return 0;
}