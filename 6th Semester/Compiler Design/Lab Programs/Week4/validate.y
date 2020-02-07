%{
#include<stdio.h>
int validate=0;
%} 

%token number;
%%


E: D'/'M'/'Y {
		if($3 == 1 || $3 == 3 || $3 == 5 || $3 == 7 || $3 == 8 || $3 == 10 || $3 == 12){
		if($1 >0 && $1<=31 && $5>0){
			printf("Date is valid\n");
			validate = 1;
			}
		else{
			validate=0;
			printf("Date is invalid\n");
		    }
		}
	      else if($3 == 4 || $3 == 6 || $3 == 9 || $3 == 11){
	      	if($1>0 && $1<31 && $5>0){
	      		printf("Date is valid\n");
	      		validate=1;
	      		}
	      	else{
	      		validate=0;
	      		printf("Date is invalid\n");
	      	}
	      }
	     else if($3 == 2){
	     	if($5%4 == 0 || ($5%100==0 && $5%400 == 0)){
	     		if($1>0 && $1<=29){
	     			printf("Date is valid\n");
	     		}
	     		else{
	     			validate=0;
	     			printf("Date is invalid\n");
	     		}
	     	}else{
	     		if($1>0 && $1<29){
	     			printf("Date is valid\n");
	     		}else {
	     		validate=0;
	     			printf("Date is invalid\n");
	     		}}
	     	}
		else{validate = 0;
			printf("Date is invalid1\n");}} 
;
D: number 
M: number
Y: number
;
%%

void main()
{
while(1){
printf(" enter expr\n");
yyparse();
if(validate == 1){
	printf("valid date\n");
}
else{
	printf("Invalid Date\n");
}
validate = 0;
}
exit(0);
}

void yyerror()
{
printf("invalid\n");
exit(0);
}
