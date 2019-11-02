#include <stdio.h>
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

int occurences(int n, int *a, int val) {
	
	int i, occ = 0;
	for (i = 0; i < n; i++)
		if (a[i] == val)
			occ++;
	return occ;

}

void radixSort(int n, int *a) {
	
	int i, j, ct = 0, length = max(n, a) + 1, b[length], c[length], isin=0;
    
    for(i = 0; i < length; b[i] = -1, i++);
    
    for(i = 0; i < n; i++) {
    	
    	isin = 0;
    	
    	for(j = 0; j < length; j++)
    		if (a[i] == b[j])
    			isin = 1;

    	if (!(isin))
        	b[a[i]] = a[i];

        }
    
    int oc = 0;
    int rep = 0;
    
    for(i = 0; i < length; i++)
        if(b[i] != -1) {
        	 c[oc] = occurences(n, a, b[i]);
        	 oc++;
        }
        
    int p = 0;
    for(i = 0; i < length; i++)
        if(b[i] != -1) {
        	for (j = 0; j < c[p]; j++) {
        		a[ct] = b[i];
        		ct++;
        	}
        	p++;
        }
}


