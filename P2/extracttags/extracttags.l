%{
#include <stdio.h>
%}
%%
"<"[^>]*> { printf("VALUE: %s\n", yytext); }
.|\n     ;
%%
main()
{
        yylex();
}
