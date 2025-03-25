#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front = NULL, *rear = NULL;

void ENQUEUE(int val)
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));

    if (new == NULL)
    {
        printf("\n Queue overflow");
        return;
    }

    new -> data = val;
    new -> next = NULL;

    if (rear == NULL)
    {
        front = rear = new;
    }
    else
    {
        rear -> next = new;
        rear = new;
    }
    
}

int DEQUEUE()
{
    struct node *curr;
    int tem;

    if (front == NULL)
    {
        printf("\n Queue underflow");
        return 0;
    }

    curr = front;
    tem = front -> data;
    front = front -> next;
    free(curr);
    
    if (front == NULL)
    {
        rear = NULL;
    }
    

    return tem;
}

void main()
{
    int ch,val,dlp;

    do
    {
       printf("||--------MENU----------||");
       printf("\n 1.ENQUEUE");
       printf("\n 2.DEQUEUE");
       printf("\n 4.Exsit");
       printf("\n||---------------------|| \n");
       printf("\nEnter your choice : \n") ;
       scanf("%d", &ch);

       if (ch == 1)
       {
        printf("Enter the value : \n");
        scanf("%d \n", &val);
        ENQUEUE(val);
       }

       else if (ch == 2)
       {
        dlp = DEQUEUE();
        printf("%d \n ", dlp);
       }
        
       else if (ch == 3)
       {
        printf("Thx For visiting /n");
        return;
       }
       
       else
       {
        printf("Enter the valid choice ");
       }
       

    } while (ch != 3);
    
}