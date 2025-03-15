#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void crate();
void insert(int val);
void delnode(int val);
void display();
void insatbng(int val);
void insbef(int key, int val);
void insaft(int key, int val);
void sort();

int main()
{
    int val, ch, key;

    do
    {
        printf("\n |--------- MENU --------|");
        printf("\n 1. create node");
        printf("\n 2. insert at end");
        printf("\n 3. Dispaly");
        printf("\n 4. delete");
        printf("\n 5. insert at begning");
        printf("\n 6. insert before");
        printf("\n 7. insert after");
        printf("\n 8. sorting");
        printf("\n 9. Exsit");
        printf("\n -----------------------");

        printf("\n Enter the choice : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            crate();
        }
        
        else if (ch == 2)
        {
           printf("Enter the value : ");
           scanf("%d", &val);
           insert(val);
        }

        else if (ch == 3)
        {
            display();
        }
        
        else if (ch == 4)
        {
            printf("Enter the value : ");
            scanf("%d", &val);
            delnode(val);
        }
        
        else if (ch == 5)
        {
            printf("Enter the value");
            scanf("%d", &val);
            insatbng(val);
        }
        
        else if (ch == 6)
        {
            printf("Enter the key");
            scanf("%d", &key);
            printf("Enter the value");
            scanf("%d", &val);
            insbef(key,val);
        }
        
        else if (ch == 7)
        {
            printf("Enter the key");
            scanf("%d", &key);
            printf("Enter the value");
            scanf("%d", &val);
            insaft(key,val);
        }
        

        else if (ch == 8)
        {
            sort();
            display();
        }
        

        else if (ch == 9)
        {
          printf("Thx you");
        }
        
        else
        {
            printf("This choice isn't availble");
        }
        

    } while (ch != 9);
}

// This is for crate node 

void crate()
{
    struct node *curr;
    int num;

    printf("Enter the number : ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        if (first == NULL)
        {
            first = (struct node*)malloc(sizeof(struct node));
            curr = first;
        }
        else
        {
            curr -> next = (struct node*)malloc(sizeof(struct node));
            curr = curr -> next;
        }

        printf("Enter the value : ");
        scanf("%d", &curr -> data);
        curr -> next = NULL;
        
    }
    
}

// This is for insert the value.

void insert(int val)
{
    struct node *new, *curr;

    new = (struct node*)malloc(sizeof(struct node));

    new -> data = val;
    new -> next = NULL;

    if(first == NULL)
    {
        first = new;
        return;
    }  

    curr = first;

    while (curr -> next != NULL)
    {
        curr = curr -> next;
    }
    
    curr -> next = new;
}

// This is for display the value.

void display()
{
    struct node *curr;

    if (first == NULL)
    {
        printf("Link-list is't exsit");
        return;
    }

    curr = first;

    while (curr != NULL)
    {
        printf("%d-->", curr -> data);    
        curr = curr -> next;
    }
    
    
}

// This for delete node or value,

void delnode(int val)
{
    struct node *curr, *prev;

    if (first == NULL)
    {
        printf("The Link- List is't exsit");
        return;
    }

    curr = first;

    if (first -> data == val)
    {
        first = curr -> next;
        free(curr);
        return;
    }
    
    while (curr != NULL && curr -> data != val)
    {
        prev = curr;
        curr = curr -> next; 
    }

    if (curr == NULL)
    {
        printf("This value doen't found");
        return;
    }
    
    
    prev -> next = curr -> next;
    free(curr);

}

// This is for insert in the begning.

void insatbng(int val)
{
    struct node  *new;

    new = (struct node*)malloc(sizeof(struct node));

    new -> data = val;
    new -> next = first;

    first = new;

}

// This for the insert before the value.

void insbef(int key, int val)
{
    struct node *curr , *new, *prev;

    new = (struct node*)malloc(sizeof(struct node));

    new -> data = val;
    new -> next = NULL; 

    if (first -> data == key)
    {
        new -> next = first;
        first = new;
        return;
    }
    
    curr = first;

    while (curr != NULL && curr -> data != key )
    {
        prev = curr;
        curr = curr -> next;
    }

    if (curr == NULL)
    {
        printf("Link-List isn't exsist");
        return;
    }
    
    new -> next = curr;
    prev -> next = new;

}

void insaft(int key, int val)
{
    struct node *curr, *new, *prev;

    new = (struct node*)malloc(sizeof(struct node));

    new -> data = val;
    new -> next = NULL;

    if (first == NULL)
    {
        printf("Link-List is empty");
        return;
    }

    curr = first;

    while (curr != NULL && curr -> data != key)
    {
        curr = curr -> next;
    }
    
    if (curr == NULL)
    {
        printf("This value doesn't extist");
        return;
    }
    
    new -> next = curr -> next;
    curr -> next =new;
    
}


void sort()
{
    struct node *i, *j;
    int tem;

    if (first == NULL)
    {
        printf("Link-List is empty ");
        return;
    }

    i = first;

    while (i -> next != NULL )
    {
        j = i -> next;

        while (j -> next != NULL)
        {
            if (j -> data < i -> data)
            {
                tem = i -> data;
                i -> data = j -> data;
                j -> data = tem;
            }
           j =j -> next;
        }
       i = i -> next;
    }
    
    
}
