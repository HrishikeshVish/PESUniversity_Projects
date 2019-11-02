#include <stdio.h>
#include <stdlib.h>
struct Course

{

	char CID[10];
	char CN[10];

};
int i;

void readRecs(int n, struct Course* c)
{

	for (i = 0; i < n; i++)
	
	{
	
		printf("\nEnter the Course ID and the Course Name:\n");
		scanf("%s\n%s", (c+i) -> CID, (c+i) -> CN);
	
	}

}


void dropRecs(int* n, struct Course* c)
{
	
	int t;
	
	printf("\nEnter the number of courses to withdraw: ");
	scanf("%d",&t);
	
	*n = *n - t;

}

void dispRecs(int n, struct Course* c)
{

	printf("\nThe records are:\n");

	for (i = 0; i < n; i++)

	{

		printf("Course ID:\t%s\n", (c+i) -> CID);
		printf("Course Name:\t%s\n", (c+i) -> CN);

	}

}
int main()

{

struct Course *c;
int n;

printf("Enter the number of courses: ");
scanf("%d",&n);

c = (struct Course*) malloc(n*sizeof(struct Course));

readRecs(n, c);
dispRecs(n, c);
dropRecs(&n, c);

c = (struct Course*) realloc(c, n*sizeof(struct Course));

printf("\nEnter the courses to retain:\n");

readRecs(n, c);

printf("\nThe updated recoreds are:\n");

dispRecs(n, c);

free(c);
c = NULL;

getchar();
return 0;

}
