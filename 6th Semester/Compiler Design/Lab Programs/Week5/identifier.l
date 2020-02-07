%{

	#include<stdio.h>
	

%}
%%

"int"|"char"|"float"|"bool"|"main"|"for"|"if"|"while"|"case"|"switch"|"double"|"long" {printf("Invalid identifier\n");}

[a-zA-Z_][a-zA-Z0-9_]* {printf("Valid Identifier\n");}
[0-9]([a-zA-Z_0-9]) {printf("Invalid Identifier\n");}
[0-9a-zA-Z_&^%$#@!*]* {printf("Invalid Identifier\n");}
%%
int main(){
	yylex();
	return 0;
}
