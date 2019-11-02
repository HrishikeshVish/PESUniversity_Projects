#include <stdio.h>
#include <string.h>


int main(void)
{
char s[100], s1[100];
printf("Enter a string: ");
scanf("%s", s);
int n = strlen(s);

rev(s, s1, n);

if (comp(s, s1, n))
printf("The given string is a palindrome!\n");
else
printf("The given string is NOT a palindrome!\n");

return 0;
}
void rev(char* s, char* s1, int n)
{
for (i = 0; i < n; i++)
s1[i] = s[n - i - 1];
}

int comp(char* s, char* s1, int n)
{
int f = 1;
for (i = 0; i < n && f; i++)
if (s[i] != s1[i])
f = 0;
return f;
}

