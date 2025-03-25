#include<stdio.h>

int main()
{
    int x[5],tmp;

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
        for (int j = i+1; j < 5; j++)
        {
            if (x[j] < x[i])
            {
                tmp = x[j];
                x[j] = x[i];
                x[i] = tmp;
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