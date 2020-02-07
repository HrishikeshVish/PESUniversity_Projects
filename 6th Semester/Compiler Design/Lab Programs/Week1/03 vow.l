%{
#include<stdio.h>
int vow = 0;
int cons =0;
%}

%%
([aeiouAEIOU]) vow++;
([a-z]|[A-Z]) cons++;
"\n" {printf("Vowel count = %d, consonant count = %d\n", vow, cons);vow=0;cons=0;}

%%
int main(){

	yylex();
	return 0;
}

