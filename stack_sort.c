#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    int a[10];
    int b[10];
    int top1;
    int top2;
};

void create(struct stack *s)
{
    s->top1=-1;
    s->top2=-1;
}

void push(struct stack *s, int element)
{
    if(s->top1==9)
    {
        printf("overflow");
        exit(1);
    }
    else
    {
        s->top1++;
        s->a[s->top1]=element;
    }
}

void sort(struct stack *s)
{
    s->top2++;
    s->b[s->top2]=s->a[s->top1];
    s->top1--;
    while(s->top1!=-1)
    {
        if(s->a[s->top1]<s->b[s->top2])
        {
            int x=s->a[s->top1];
            s->top1--;
            while(x<s->b[s->top2]&&s->top2>=0)
            {
                s->top1++;
                s->a[s->top1]=s->b[s->top2];
                s->top2--;
            }
            s->top2++;
            s->b[s->top2]=x;
        }
        else if (s->a[s->top1]>=s->b[s->top2])
        {
            s->top2++;
            s->b[s->top2]=s->a[s->top1];
            s->top1--;
        }
    }
}

void display(struct stack *s)
{
    while(s->top2!=-1)
    {
        printf("%d",s->b[s->top2]);
        s->top2--;
    }
}

void main()
{
    struct stack s;
    create(&s);
    for(int i=0;i<10;i++)
    {
        int element;
        scanf("%d",&element);
        push(&s,element);
    }
    sort(&s);
    display(&s);
}