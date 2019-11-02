#include <stdio.h>


int main()
{
int m1, n1, m2, n2, i, j;
printf("Enter the order of the first matrix: ");
scanf("%dx%d", &m1, &n1);
printf("Enter the order of the second matrix: ");
scanf("%dx%d", &m2, &n2);
int a[m1][n1], b[m2][n2], r[m1][n2];
printf("Enter the elements of the first matrix:\n");
for(i=0; i<m1; i++)
for(j=0; j<n1; j++)
scanf("%d", &a[i][j]);
printf("Enter the elements of the second matrix:\n");
for(i=0; i<m2; i++)
for(j=0; j<n2; j++)
scanf("%d", &b[i][j]);
prod(m1, n1, m2, n2, a, b, r);
printf("The resultant matrix is:\n");
for(i=0; i<m1; i++)
{
for(j=0; j<n2; j++)
printf("%d\t", r[i][j]);
putchar('\n');
}
getchar();
return 0;
}
void prod(int m1, int n1, int m2, int n2, int a[m1][n1], int b[m2][n2], int r[m1][n2])
{
int i, j, k, s = 0;
for(i = 0; i < m1; i++)
for(j = 0; j < n2; j++)
{
for(k = 0; j < n1; k++)
s += a[i][k]*b[k][j];
r[i][j] = s;
s = 0;
}
}