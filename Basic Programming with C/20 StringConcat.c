#include <stdio.h>
#include <string.h>


int main(void)
{
char s[200], s1[100]; int d;
printf("Enter the first string: ");
scanf("%s", s);
printf("Enter the second string: ");
scanf("%s", s1);
int n1 = strlen(s1);
printf("Enter the number of times to replicate the second string: ");
scanf("%d", &d);
int i;
printf("%d", n);
for (i = 0; i < d; i++)
{
int n = strlen(s);
conc(s, s1, n, n1);
}

printf("The concatenated string is %s\n", s);

return 0;
}
void conc(char* s, char* s1, int n, int n1)
{
for (i = 0; i < n1; i++)
s[n+i] = s1[i];
}
