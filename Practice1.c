#include<stdio.h>
int main()
{
    int i,j;
    for(i=1;i<=5;i++) //Rows
    {
        for(j=1;j<=i;j++) //Columns
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
