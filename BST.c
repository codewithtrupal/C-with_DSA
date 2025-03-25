#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lptr, *rptr;
} *root = NULL;

void insert(int val)
{
    int d;
    struct node *curr, *prv, *new;

    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->lptr = NULL;
    new->rptr = NULL;

    if (root == NULL)
    {
        root = new;
        return;
    }

    curr = root;

    while (curr != NULL)
    {
        if (val < curr->data)
        {
            prv = curr;
            curr = curr->lptr;
            d = 0;
        }
        else if (val > curr->data)
        {
            prv = curr;
            curr = curr->rptr;
            d = 1;
        }
        else
        {
            printf("\n Duplicate value found!");
            return;
        }
    }

    if (d == 0)
    {
        prv->lptr = new;
    }
    else
    {
        prv->rptr = new;
    }
}

void preorder(struct node *r)
{
    if (r == NULL)
    {
        return;
    }

    printf("%d-->", r->data);
    preorder(r->lptr);
    preorder(r->rptr);
}

void inorder(struct node *r)
{
    if (r == NULL)
    {
        return;
    }
    inorder(r->lptr);
    printf("%d-->", r->data);
    inorder(r->rptr);
}

void postorder(struct node *r)
{
    if (r == NULL)
    {
        return;
    }

    postorder(r->lptr);
    postorder(r->rptr);
    printf("%d-->", r->data);
}
int main()
{
    int val, ch;
    do
    {
        printf("\n|--------------------|");
        printf("\n1.insert");
        printf("\n2.inorder");
        printf("\n3.preorder");
        printf("\n4.postorder");
        printf("\n5.Exit");
        printf("\n|---------------------|");
        printf("\nEnter choise:");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("\n Enter value:");
            scanf("%d", &val);
            insert(val);
        }
        else if (ch == 2)
        {
            printf("\n");
            inorder(root);
        }
        else if (ch == 3)
        {
            printf("\n");
            preorder(root);
        }
        else if (ch == 4)
        {
            printf("\n");
            postorder(root);
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            printf("\n invaild number!");
        }
    } while (ch != 5);
}
