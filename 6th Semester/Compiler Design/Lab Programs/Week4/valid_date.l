%{ 

    #include <stdio.h>
    #include "y.tab.h"
    extern int yylval;  
  
%}
%%

[0-9]+ {yylval = atoi(yytext); printf("value = %d\n", yylval);return number;} 

[\t] ; 
\n ; 
. { return yytext[0]; } 
%%
