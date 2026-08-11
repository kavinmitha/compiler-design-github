%{
#include <stdio.h>

int count = 0;
%}

%%
[aAeEiIoOuU]    { printf("Vowel: %s\n", yytext); count++; }
[a-zA-Z]        ;
\n              { printf("Total Vowels = %d\n", count); return 0; }
.               ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}