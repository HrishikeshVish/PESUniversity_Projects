%{
#include<stdio.h>
int res=0;
%} 
  
%token NUMBER ID 

%left '+' '-'
%left '*' '/'
  
%%

E:T  { printf("Result = %d\n", $$); 
       return 0; } 
;  
T : T '+' T { $$ = $1 + $3; } 
| T '-' T { $$ = $1 - $3; } 
| T '*' T { $$ = $1 * $3; } 
| T '/' T { $$ = $1 / $3; } 
| '-' NUMBER { $$ = -$2; } 
| '-' ID { $$ = -$2; } 
| '(' T ')' { $$ = $2; } 
| NUMBER { $$ = $1; } 
| ID { $$ = $1; }; 
;

%% 
void main()
{
printf(" enter expression:\n");
yyparse();
}

void yyerror()
{
printf("invalid\n");
exit(0);
}
