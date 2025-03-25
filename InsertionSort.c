#include<stdio.h>

int main()
{
    int x[5],tem;
    int j;

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

    for (int i = 1; i < 5; i++)
    {
        tem=x[i];
        j=i-1;

        while (j>=0&&x[j]>tem)
        {
            x[j+1]=x[j];
            j=j-1;
        }
        x[j+1]=tem;
        
    }

    
    printf("After sorting ");

    for (int  i = 0; i < 5 ; i++)
    {
        printf("\n %d",x[i]);
    }
    
    return 0;
    
}