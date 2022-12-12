#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct stack
{
    char a[100];
    int top;
};

void create(struct stack *s1)
{
    s1->top=-1;
}

void push(struct stack *s1, char element)
{
    if(s1->top==99)
    {
        printf("overflow");
        exit(1);
    }
    else
    {
        s1->top++;
        s1->a[s1->top]=element;
    }
}

void display(struct stack *s1)
{
    while(s1->top+1)
    {
        printf("%c",s1->a[s1->top]);
        s1->top--;
    }
}

void main()
{
    struct stack s;
    create(&s);
    char str1[100];
    scanf("%s",str1);
    int a=strlen(str1);
    for (int i=0;i<a;i++)
    {
        push(&s,str1[i]);
    }
    display(&s);
}