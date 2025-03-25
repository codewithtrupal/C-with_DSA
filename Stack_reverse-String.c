#include<stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char val)
{
    if (top == MAX -1)
    {
        printf("\n Stack overflow");
        return;
    }

    top++;
    stack[top] = val;
    
}

char pop()
{
    char tmp;

    if (top == -1)
    {
        printf("\n Stack underflow");
        return '\0';
    }

    tmp = stack[top];
    top--;

    return tmp;
    
}

int main()
{
    int i = 0;
    char str[100];
    char ch;

    printf("\n Enter the string : ");
    scanf("%s", str);

    while (str[i] != '\0')
    {
        push(str[i]);
        i++;
    }

    printf("Reversed string is : ");
    while (top != -1)
    {
        ch = pop();
        printf("%c", ch);
    }
    
    
}