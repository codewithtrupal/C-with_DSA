#include<stdio.h>

int main()
{
    int x[10],beg,end,se,mid;

    printf("Enter the 10 elements : ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &x[i]);
    }

    printf("Enter the numer you find : ");
    scanf("%d", &se);

    beg = 0;
    end = 9;

    for (mid=(beg+end)/2; beg <= end ; mid=(beg+end)/2)
    {
        if (x[mid] == se)
        {
            printf("Your vlaue found at %d postion ", mid + 1);
            break;
        }

        else if(se < x[mid])
        {
            end = mid - 1;
        }

        else
        {
            beg = mid + 1;
        }
        
    }

    if (end < beg)
    {
        printf("Value not found : ");
    }
    
    return 0;
    
}