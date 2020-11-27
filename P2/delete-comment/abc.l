%{
#include<stdio.h>
%}

%%

\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
%%

main()
{
yyin=fopen("mypgm.cpp","r");
yylex();
}

int yywrap()
{
return 1;
}