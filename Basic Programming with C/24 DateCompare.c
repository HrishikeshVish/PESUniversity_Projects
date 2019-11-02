#include <stdio.h>


int main()
{
struct Date d1, d2;
printf("Enter the first date: ");
scanf("%d/%d/%d", &d1.D, &d1.M, &d1.Y);
printf("Enter the second date: ");
scanf("%d/%d/%d", &d2.D, &d2.M, &d2.Y);
int r = comp(d1, d2);
if(r)
if(r == -1)
printf("The first date occurs before the second\n");
else printf("The first date occurs after the second\n");
else printf("The two dates occur on the same goddamn day! Yay!\n");
getchar();
return 0;
}
int comp(struct Date d1, struct Date d2)
{
if(d1.Y == d2.Y)
{
if(d1.M == d2.M)
{
if(d1.D == d2.D)
return 0;
else if(d1.D < d2.D)
return -1;
else return 1;
}
else if(d1.M < d2.M)
return -1;
else return 1;
}
else if(d1.Y < d2.Y)
return -1;
else return 1;
}