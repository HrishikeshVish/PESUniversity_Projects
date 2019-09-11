#include<stdio.h>
 
#include<string.h>


#include<math.h>


#include<stdlib.h>


#include<time.h>


int strmatch_pattern(char *text, char *pattern);





int main(){


char *s1 = malloc(sizeof(char)*10000000) ; char *s2 = malloc(sizeof(char)*10000000);


int b = scanf("%[^\n]%*C", s1);


//fgets(s1, sizeof s1, stdin);





int n;


scanf("%d\n", &n);


int a[n];


struct timespec start,end;


for(int i=0;i<n;i++){  


 int a = scanf("%[^\n]%*C", s2);  


 //fgets(s2, sizeof s2, stdin);


 //if(s1[0] == '\n' || s2[0] =='\n'){printf("One or More NULL Strings\n"); break;}


 clock_gettime(CLOCK_REALTIME, &start); 


 printf("%d\n", strmatch_pattern(s1, s2));


 clock_gettime(CLOCK_REALTIME, &end); 


} 


double timeinseconds= end.tv_nsec - start.tv_nsec;











timeinseconds = timeinseconds/(pow(10,9));


if(timeinseconds>=0.004){printf("Enter"); printf("%d\n", -1);}


printf("%lf\n", timeinseconds);








}











int strmatch_pattern(char *text, char *pattern){


int z1 = strcmp(text,"");


int z2 = strcmp(pattern, "");


if(z1==0 || z2==0){printf("NULL STring\n");return -1;}


double n = strlen(text);


double m = strlen(pattern);





if(m>n){printf("Pattern greater than text\n");return -1;}





for (int i =0; i<=n-m+1; i++){


 int j = 0;


 while(j<m && (pattern[j] == text[i+j])){


  j++;


 }


 if(j==m) return i;





}


return -1; 





}