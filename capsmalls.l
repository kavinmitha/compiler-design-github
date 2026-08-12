%{
#include <stdio.h>
%}

%%
[A-Z]+                          { printf("Capital Letters: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*          { printf("Valid Identifier: %s\n", yytext); }

[0-9][a-zA-Z0-9_]*              { printf("Invalid Identifier: %s\n", yytext); }

\n                              { return 0; }

.                               ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter input: ");
    yylex();
    return 0;
}