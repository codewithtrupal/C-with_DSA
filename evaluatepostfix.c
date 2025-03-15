#include<stdio.h>
#include<ctype.h>
#define MAX 100
float st[MAX];
int top=-1;
void push(float val)
{
    if(top==MAX-1)
    {
        printf("\nStack Overflow:");
        return;
    }
    top++;
        st[top]=val;
}
float pop()
{
    float tmp;
    if(top==-1)
    {
        printf("\nStack Underflow:");
        return '0';
    }
    tmp=st[top];
    top--;
    return tmp;
}
float evalpostfixexpr(char *exp)
{
    int i=0;
    float op1, op2, value;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            push((float)(exp[i]-'0'));
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(exp[i])
            {
            case '+':
                value=op1+op2;
                break;
             case '-':
                value=op1-op2;
                break;
             case '*':
                value=op1*op2;
                break;
             case '/':
                value=op1/op2;
                break;
             case '%':
                value=(int)op1%(int)op2;
                break;
            }
            push(value);
        }
        i++;
    }
    return(pop());
}
void main()
{
    float val;
    char exp[MAX];
    printf("\nEnter Any Postfix Expression:");
    gets(exp);
    printf("\nValue of the Postfix Expression is:");
    val=evalpostfixexpr(exp);
    printf("%f",val);
}
