#include<stdio.h>

int main()
{
    int x[5],i,se;

    printf("Enter any 5 elements : ");

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &x[i]);
    }

    printf("Enter the numer you find : ");
    scanf("%d", &se);

    for ( i = 0; i < 5; i++)
    {
        if (se == x[i])
        {
            printf("Your vlaue found at %d postion ", i + 1);
            break;
        }
    }

    if (i == 5)
    {
        printf("Vule does't Exsist ");
    }
    
    return 0;
    
}