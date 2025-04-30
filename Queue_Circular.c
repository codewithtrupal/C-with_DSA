#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void ENQUEUE(int val)
{
    if ((front == 0 && rear == MAX -1) || rear + 1 == front)
    {
        printf("\nQueue overflow ");
        return;
    }

    if (rear == MAX - 1 )
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    
    queue[rear] = val;

    if (front == -1)
    {
        front++;
    }
    
}

int DEQUEUE()
{
    int tem;

    if (front == -1)
    {
        printf("\n Queue undreflow");
        return 0;
    }

    tem = queue[front];

    if (front == MAX - 1)
    {
        front = 0;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
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