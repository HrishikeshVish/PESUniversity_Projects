#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *a, *b;
int max(int p, int q){
	return p>=q? p:q;
}
int naive(int i, int j){
	if(i == 0 || j ==0){
		return 0;
	}
	int m = i-1;
	int n = j-1;
	if(a[m] == b[n]) {
	
	
	return naive(i-1, j-1)+1;
	
	}
	else{
		return max(naive(i, j-1), naive(i-1,j));
	}
}
int memoize( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   int i, j; 

   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
     

   return L[m][n]; 
} 

   int L[400][200];              

   int dp1( int i, int j, char* x, char* y )
   {
      int sol1, sol2, sol3;

      if ( i == 0 || j == 0 )
      {

         return 0;
      }


      if ( L[i][j] >= 0 )
      {
         return( L[i][j] );  
      }



      if ( x[i-1] == y[i-1] )
      {
         sol1 = dp1(i-1, j-1, x, y);

         L[i][j] = sol1 + 1;  

	 return( sol1 + 1 );
      }
      else
      {
         sol2 = dp1(i-1, j, x, y);
	 sol3 = dp1(i, j-1, x, y);

	 if ( sol2 >= sol3 )
	 {

            L[i][j] = sol2;       

	    return(sol2);
	 }
	 else
	 {

            L[i][j] = sol3;     

	    return(sol3);
	 }


      }
   }
int main(){
	
	a = (char*)malloc(sizeof(char)*200);
	b = (char*)malloc(sizeof(char)*200);
	scanf("%s", a);
	scanf("%s", b);
	int i = naive(strlen(a), strlen(b));
	printf("%d\n", i);
	i = memoize(a, b, strlen(a), strlen(b));
	printf("%d\n", i);
	i = dp1(strlen(a), strlen(b), a, b);
	printf("%d\n", i);
}

