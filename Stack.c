#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int val)
{
    if (top == MAX-1)
    {
            printf("Stack overflow ");
            return;
    }
    
    top++;
    stack[top] = val;
}

int pop()
{
    int tem;

    if (top == -1)      
    {
       printf("Stack underflow");
       return 0;
    }

    tem = stack[top];
    top--;

    return tem;
    
}

int peep()
{
    int tem;

    if (top == -1)      
    {
       printf("Stack underflow");
       return 0;
    }

    tem = stack[top];

    return tem;
}

void main()
{
    int ch,val,dlp;

    do
    {
       printf("||--------MENU----------||");
       printf("\n 1.push");
       printf("\n 2.pop");
       printf("\n 3.peep");
       printf("\n 4.Exsit");
       printf("\n||---------------------||");
       printf("\nEnter your choice : ") ;
       scanf("%d", &ch);

       if (ch == 1)
       {
        printf("Enter the value : ");
        scanf("%d", &val);
        push(val);
       }

       else if (ch == 2)
       {
        dlp = pop();
        printf("\n%d", dlp);
       }

       else if (ch == 3)
       {
        dlp = peep();
        printf("\n%d", dlp);
       }
       
       else if (ch == 4)
       {
        printf("Thx For visiting");
        return;
       }
       
       else
       {
        printf("Enter the valid choice ");
       }
       

    } while (ch != 4);
    
}
