#include<stdio.h>

int main()
{
    int x[5],tem;

    for (int i = 0; i < 5; i++)
    {
        printf("Enter the value : ");
        scanf("%d", &x[i]);
    }

    printf("Before sorting ");

    for (int  i = 0; i < 5 ; i++)
    {
        printf("\n %d",x[i]);
    }

    
    
    printf("After sorting ");

    for (int  i = 0; i < 5 ; i++)
    {
        printf("\n %d",x[i]);
    }
    
    return 0;
    
}