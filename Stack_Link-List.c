#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top= NULL;

void push(int val)
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));

    if (new == NULL)
    {
        printf("\n Stack overflow");
        return;
    }

    new -> data = val;
    new -> next = top;
    top = new;
    
}

int pop()
{
    struct node *curr;
    int tem;

    if (top == NULL)
    {
        printf("\n Stack underflow");
        return 0;
    }

    curr = top;
    top = top -> next;
    tem = curr -> data;
    free(curr);

    return tem;
}

int peep()
{
    if (top == NULL)
    {
        printf("\n Stack underflow");
        return 0;
    }

    return top -> data;
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