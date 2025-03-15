#include<stdio.h>
#include<ctype.h>
#define MAX 100
char st[MAX];
int top=-1;
void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%c",st[i]);
    }
}
void push(char val)
{
    if(top==MAX-1)
    {
        printf("\nStack Overflow:");
        return;
    }
    top++;
        st[top]=val;
}
char pop()
{
    char tmp;
    if(top==-1)
    {
        printf("\nStack Underflow:");
        return '0';
    }
    tmp=st[top];
    top--;
    return tmp;
}
int getPriority(char op)
{
    if(op=='^' || op=='$')
        return 3;
    else if(op=='/' || op =='*' )
        return 2;
    else if (op=='%')
        return 1;
    else
        return 0;
}
void infixtopostfix(char *source, char *target)
{
    int i=0,j=0;
    char tmp;
    while(source[i] != '\0')
    {
        if(source[i]=='(')
        {
            push(source[i]);
            i++;
        }
        else if(source[i]==')')
        {
            while((top==-1) || st[top]!='(')
            {
                target[j]=pop();
                j++;
            }
            if(top==-1)
            {
                printf("\nInvalid Expression:");
                return;
            }
            tmp=pop(); //Removing left parenthesis
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i]))
        {
            target[j]=source[i];
            j++;
            i++;
        }
        else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='%' || source[i]=='/' || source[i]=='^' || source[i] =='$')
        {
            while((top!=-1) && (st[top] != '(') && (getPriority(st[top]) >= getPriority(source[i])))
            {
                target[j]=pop();
                j++;
            }
            push(source[i]);
            i++;
        }
        else
        {
            printf("\nInvalid Expression:");
            return;
        }
    }
    while((top != -1) && (st[top]!='('))
    {
        target[j]=pop();
        j++;
    }
    target[j]='\0';
}
void main()
{
    char infix[MAX], postfix[MAX];
    printf("\nEnter Any Infix Expression:");
    gets(infix);
    infixtopostfix(infix, postfix);
    printf("\nCorresponding postfix expression is:");
    puts(postfix);
}
