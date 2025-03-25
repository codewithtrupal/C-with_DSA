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

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4-i; j++)
        {
            if (x[j+1] < x[j])
            {
                tem = x[j+1];
                x[j+1] = x[j];
                x[j] = tem;
            }
            
        }
        
    }

    printf("After sorting ");

    for (int  i = 0; i < 5 ; i++)
    {
        printf("\n %d",x[i]);
    }
    
    return 0;
    
}