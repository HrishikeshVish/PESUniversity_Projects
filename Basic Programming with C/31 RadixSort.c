#include <stdio.h>
#include "sort.h"
void radixSort(int, int *);

int main ()

{
	int n;
	
	printf("\nPlease enter the number of elements to be inserted in the array: ");
	scanf("%d",&n);
    
    	int a[n], i;
    	
    	printf("\nEnter the Elements:\n");
    	
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	printf("\nThe entered array is:\n[ ");
	
	for(i = 0; i < n; i++)
        	printf("%d ", a[i]);
    
    	printf("]\n");
    
    	radixSort(n, a);
    
    	printf("\nThe array after applying Radix Sort is:\n[ ");
    	
    	for(i = 0; i < n; i++)
    		printf("%d ", a[i]);
    
    	printf("]\n\n");

    	return 0;

}
int max(int n, int *a) {

    int i, max = a[0];

    for(i = 0; i < n; i++) {
        
        if(a[i] > max)
            max = a[i];
    
    }

    return max;

}


void radixSort(int n, int *a) {
	
	int i, c = 0, length = max(n, a) + 1, b[length];
    
    	for(i = 0; i < length; b[i] = -1, i++);
	for(i = 0; i < n; b[a[i]] = a[i], i++);

    	for(i = 0; i < length; i++)
        
        if(b[i] != -1)
             a[c++] = b[i];

}


