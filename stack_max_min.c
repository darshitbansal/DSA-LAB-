#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    int a[10];
    int top;
};

void create(struct stack *s)
{
    s->top=-1;
}

void push(struct stack *s, int element)
{
    if(s->top==10)
    {
        printf("overflow");
        exit(1);
    }
    else
    {
        s->top++;
        s->a[s->top]=element;
    }
}

void max_min(struct stack *s)
{
    int x,y;
    x=s->a[s->top];
    y=s->a[s->top];
    s->top--;
    while(s->top!=-1)
    {
        if(x<s->a[s->top])
        {
            x=s->a[s->top];
            s->top--;
        }
        else if(y>s->a[s->top])
        {
            y=s->a[s->top];
            s->top--;
        }
        else
        {
            s->top--;
        }
    }
    printf("max is %d\nmin is %d",x,y);
    
}

void main()
{
    struct stack s;
    create(&s);
    for (int i=0;i<10;i++)
    {
        int element;
        scanf("%d",&element);
        push(&s,element);
    }
    max_min(&s);
}