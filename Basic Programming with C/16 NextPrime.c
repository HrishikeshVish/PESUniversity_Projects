/* 2_nextPrime.c [L5P2F1] */

#include <stdio.h>


int main()

{
                /* Program to find the next prime number after a given number - Client */

								int n;

								printf("\nEnter a number:\n");
								scanf("%d", &n);
								
								int F = nP(n);
								
								if(F)
								printf("\nThe next prime number after %d is %d\n", n, F);
								else
								printf("\nThe given number (%d) is not prime!\n", n);
								
								getchar();
								return 0;
}

/***** END OF FILE *****/
int Prime(int n)
{
int i, s = 0;
for (i = 1; i <= n; i++)
if (!(n % i))
s++;
if (s-2)
return 0;
else
return 1;
}

int nP(int n)
{
if (Prime(n))
while (1)
{
n++;
if(Prime(n))
return n;
}
else
return 0;
}
