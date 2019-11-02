/* 3S_revArray.c [L5P3F1] */

#include<stdio.h>

int main()

{
                /* Program to print an Array in the reverse order - Client */
                
                int a[10] = {1, 2, 3, 4, 5};
                
                rev(a);

                return 0;
}

/***** END OF FILE *****/
void rev(int a[])

{
                /* Program to print an Array in the reverse order - Server */
                
                int i;

                for(i=4; i>=0; i--)
                printf("%d ", a[i]);
                
                putchar('\n');

}
