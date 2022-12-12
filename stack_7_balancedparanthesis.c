#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bracket
{
    char a[100];
    int top;
};

void create(struct bracket *b1)
{
    b1->top=-1;
}

void push(struct bracket *b1, char element)
{
    if(b1->top==99)
    {
        printf("overflow");
        exit(1);
    }
    else
    {
        b1->top++;
        b1->a[b1->top]=element;
    }
}

char pop(struct bracket *b1)
{
        char x;
        x=b1->a[b1->top];
        b1->top--;
        return x;
        
}

int match(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
        return 1;
    else if (c1 == '{' && c2 == '}')
        return 1;
    else if (c1 == '[' && c2 == ']')
        return 1;
    else
        return 0;
}

int balance(char exp[], int a)
{
    int i = 0;
    struct bracket b;
    create(&b);
    while (i<a)
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&b, exp[i]);
        else if (exp[i] == '}' || exp[i] == ')'|| exp[i] == ']')
        {
            if (b.top==-1)
                return 0;
            else if (! match(pop(&b), exp[i]))
                return 0;
            
        }
        if(i==a-1)
        {
            if(b.top==-1)
            {
                return 1;
            }
            else{
                return 0;
            }
        }

        i++;
    }
}

void main()
{
    char exp[100];
    scanf("%s",exp);
    int a=strlen(exp);
    if (balance(exp,a))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
}
