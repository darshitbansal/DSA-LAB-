#include <stdio.h>
#include <stdlib.h>
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

void palindrome(struct stack *s1,char str1[])
{
    int i=0;
    int x=s1->top;
    while(1)
    {
        if(i>=x)
        {
            printf("palindrome");
            exit(1);
        }
        if(str1[i]==s1->a[x])
        {
            i++;
            x--;
        }
        else
        {
            printf("not palindrome");
            exit(1);
        }
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
    palindrome(&s,str1);
}