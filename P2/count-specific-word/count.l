%{ 
#include<stdio.h> 
#include<string.h> 

char word [] = "amir"; 
int c = 0; 

%} 
%% 
[a-zA-Z]+ { if(strcmp(yytext, word)==0) 
				c++; } 
. ;		 
%% 


main() 
{ 
		yyin=fopen("in.txt", "r"); 
		yylex(); 	
		printf("%d\n", c); 
	
} 

int yywrap() 
{ 
	return 1; 
} 