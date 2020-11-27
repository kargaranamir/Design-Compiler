%{
    int c=0, w=0, l=0, s=0;
%}
word [^ \t\n]+
eol  \n	
spaces [ ]
%%
{word} {w++; c+=yyleng;};
{eol}  {c++; l++;}
{spaces}  {c++; s++;}
.      {c++;}
%%
main()
{
	yylex();
	printf(" lines= %d words= %d characters= %d spaces= %d\n", l, w, c, s);
}
