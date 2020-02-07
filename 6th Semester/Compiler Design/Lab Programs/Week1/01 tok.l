%{
#include<stdio.h>
int tok = 0;
int id = 0;
int keyw = 0;
int op = 0;
int wp = 0;
int num=0;
%}

%%
"int"|"auto"|"break"|"if"|"switch"|"case"|"for"|"char"|"while"|"do"|"bool"|"float"|"long"|"double" {keyw++;tok++;}
"<"|">"|"="|"=="|"+"|"++"|"-"|"^"|"--"|"*"|"/"|"%"|"&&"|"||"|"!=" {op++;tok++;}
"{"|"}"|"["|"]"|":"|"\\"|";"|"("|")"  {tok++;} 
([0-9])([0-9])*("."?)([0-9])* {num++;tok++;}
" " wp++;
([a-zA-Z])([a-zA-Z])* {tok++; id++;}
"\n" {printf("\nkeywords = %d, tokens = %d, identifiers = %d, operators = %d, whitespace = %d numbers = %d \n", keyw, tok, id, op, wp, num);tok=0;id=0;keyw=0;op=0;wp=0;num=0;}

%%
int main(){
	yylex();
	return 0;
}
