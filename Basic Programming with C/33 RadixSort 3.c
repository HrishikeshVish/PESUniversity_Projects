#include <stdio.h>
struct student

{
    int roll;
    char name[100];
};

void radixSort(int, struct student *);


int main (void)

{
	
	int n;
	
	printf("\nEnter number of students: ");
	scanf("%d", &n);
    
    struct student a[n];
    
    int i;

    for(i = 0; i < n; i++) {
    
    	printf("\nEnter the details of Student %d:\nRoll: ", i+1);
        scanf("%d", &(a[i].roll));
        printf("Name: ");
        scanf("%s", a[i].name);
        
    }

	printf("\n\nThe student details before sorting are:\n");

    for(i = 0; i < n; i++)
        printf("\n%d: %s", a[i].roll, a[i].name);
    printf("\n");
	
    radixSort(n, a);
    
	printf("\n\nThe student details after sorting are:\n");
    
    for(i = 0; i < n; i++)
        printf("\n%d: %s", a[i].roll, a[i].name);
    printf("\n\n");

    return 0;

}

int max(int n, struct student *a) {

    int i, max = a[0].roll;

    for(i = 0; i < n; i++) {
        
        if(a[i].roll > max)
            max = a[i].roll;
    
    }

    return max;

}


void radixSort(int n, struct student *a) {
	
	int i, c = 0, length = max(n, a) + 1;
	struct student b[length];
    
    	for(i = 0; i < length; b[i].roll = -1, i++);
	for(i = 0; i < n; b[a[i].roll] = a[i], i++);

    	for(i = 0; i < length; i++)
        
        if(b[i].roll != -1)
             a[c++] = b[i];

}

