#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char value)
{
  if (top == MAX - 1)
  {
    printf("\nStack overflow");
    return;
  }
  stack[++top] = value;
}

char pop()
{
  if (top == -1)
  {
    printf("\nStack underflow");
    return '\0';
  }
  return stack[top--];
}

void main()
{
  char str[MAX];
  printf("\nEnter string : ");
  scanf("%s", str);

  int i = 0;
  while (str[i] != '\0')
  {
    push(str[i]);
    i++;
  }

  printf("Reversed string : ");
  while (top != -1)
  {
    char ch = pop();
    printf("%c", ch);
  }
}

