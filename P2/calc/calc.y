%{ 
   /* Definition section */
  #include<stdio.h> 
%} 
  
%token NAME NUMBER 

%left '+' '-'
  
%left '*' '/' '%'
  
%left '(' ')'

%nonassoc UMINUS
/* Rule Section */
%% 
  
ArithmeticExpression: E{ 
  
         printf("output=%d \n", $$); 
  
         return 0; 
  
        }; 
 E:E '+' E {$$=$1+$3;} 
  
 |E '-' E {$$=$1-$3;} 
  
 |E '*' E {$$=$1*$3;} 
  
 |E '/' E {$$=$1/$3;} 
  
 |E '%' E {$$=$1%$3;} 
  
 |'(' E ')' {$$=$2;} 
  
 | NUMBER {$$=$1;} 

 ; 
  
%% 
  
//driver code 
int main() 
{ 
   printf("Input:\n"); 
   yyparse(); 
} 
  
int yyerror() 
{ 
} 
int yywrap(){
    return 1;
}