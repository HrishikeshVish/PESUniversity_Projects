#include <stdio.h>
#include <stdlib.h>
int i;
struct employee

{

    int SSN;
    char Name[100];
    char Dept[10];

};
void readData(int n, struct employee* s)

{
	for(i = 0; i < n; i++)
	{
		printf("\nEnter the SSN, Name and Department of Employee %d:\n", i+1);
		scanf("%d", &s -> SSN);
		__fpurge(stdin);
		scanf("%s", s -> Name);
		scanf("%s", s -> Dept);
		s++;
	}
}

void dispData(int n, struct employee* s)
{
	for(i = 0; i < n; i++)
	{
		printf("\nThe details of Employee %d:\n", i+1);
		printf("SSN: %d\n", s -> SSN);
		printf("Name: %s\n", s -> Name);
		printf("Dept: %s\n", s -> Dept);
		s++;
	}
	
	putchar('\n');
}


int main()

{

	int n;
	struct employee* s;

	printf("\nEnter the number of employees: ");
	scanf("%d", &n);

	s = (struct employee*) malloc(n*sizeof(struct employee));

	readData(n, s);
	dispData(n, s);

	free(s);
	s = NULL;

	getchar();
	return 0;

}

