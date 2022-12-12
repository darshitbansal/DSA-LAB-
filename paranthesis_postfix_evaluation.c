#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
/**********************************************************************************************************/
struct stack
{
    int a[100];
    char b[100];
    int top1;
    int top2;
};
/**********************************************************************************************************/
void create(struct stack *s)
{
    s->top1=-1;
    s->top2=-1;
}
/**********************************************************************************************************/
void evaluate(struct stack *s)
{
    int x;
    switch(s->b[s->top2])
    {
        case '+':
        x=((s->a[s->top1-1])+(s->a[s->top1]));
        s->top1--;
        s->a[s->top1]=x;
        break;

        case '-':
        x=((s->a[s->top1-1])-(s->a[s->top1]));
        s->top1--;
        s->a[s->top1]=x;
        break;

        case '*':
        x=((s->a[s->top1-1])*(s->a[s->top1]));
        s->top1--;
        s->a[s->top1]=x;
        break;

        case '/':
        x=((s->a[s->top1-1])/(s->a[s->top1]));
        s->top1--;
        s->a[s->top1]=x;
        break;

        case '^':
        x=pow((s->a[s->top1-1]),(s->a[s->top1]));
        s->top1--;
        s->a[s->top1]=x;
        break;
    }
}
/**********************************************************************************************************/
int number(char x)
{
    switch(x)
    {
        case '0':
        return 0;

        case '1':
        return 1;

        case '2':
        return 2;

        case '3':
        return 3;

        case '4':
        return 4;
        case '5':
        return 5;

        case '6':
        return 6;

        case '7':
        return 7;

        case '8':
        return 8;

        case '9':
        return 9;
    }
}
/**********************************************************************************************************/
int compare(struct stack *s,char a)
{
        if(a=='/')
        {
            if(s->b[s->top2]=='^'||s->b[s->top2]=='*')
            {
                evaluate(s);
                s->top2--;
                compare(s,a);
            }
            else
            {
                return 1;
            }
        }
        else if(a=='*')
        {
            if(s->b[s->top2]=='^'||s->b[s->top2]=='/')
            {
                evaluate(s);
                s->top2--;
                compare(s,a);
            }
            else
            {
                return 1;
            }
        }
        else if(a=='-')
        {
            if(s->b[s->top2]=='+'||s->b[s->top2]=='^'||s->b[s->top2]=='/'||s->b[s->top2]=='*')
            {
                evaluate(s);
                s->top2--;
                compare(s,a);
            }
            else
            {
                return 1;
            }
        }
        else if(a=='+')
        {
            if(s->b[s->top2]=='^'||s->b[s->top2]=='/'||s->b[s->top2]=='*')
            {
                evaluate(s);
                s->top2--;
                compare(s,a);
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
}
/**********************************************************************************************************/
void postfix(struct stack *s , char x[])
{
    create(s);
    for(int i=0;x[i]!='\0';i++)
    {
        int num;
        if( (int)x[i]>=48 && (int)x[i]<=57)
        {
            num=number(x[i]);
            s->top1++;
            s->a[s->top1]=num;
        }
        else if (x[i]=='('||x[i]=='['||x[i]=='{')
        {
            s->top2++;
            s->b[s->top2]=x[i];
        }
        else if (x[i]==')')
        {
            if (s->b[s->top2]=='('&&x[i-1]=='(')
            {
                printf("invalid expression1");
                exit(1);
            }
            else
            {
                while(s->b[s->top2]!='('&&s->top2>=0)
                {
                    if (s->b[s->top2]=='['||s->b[s->top2]=='{')
                    {
                        printf("invalid expression2");
                        exit(1);
                    }
                    else
                    {
                        evaluate(s);
                        s->top2--;
                    }
                                  
                }
                if (s->b[s->top2]=='('&&x[i-1]!='(')
                {
                    if(s->top2>0)
                        s->top2--;
                }
                if(s->top2==-1)
                {
                    printf("invalid expression3");
                    exit(1);
                }
            }
        }
        else if (x[i]==']')
        {
            if (s->b[s->top2]=='['&&x[i-1]=='[')
            {
                printf("invalid expression1");
                exit(1);
            }
            else
            {
                while(s->b[s->top2]!='['&&s->top2>=0)
                {
                    if (s->b[s->top2]=='('||s->b[s->top2]=='{')
                    {
                        printf("invalid expression2");
                        exit(1);
                    }
                    else
                    {
                        evaluate(s);
                        s->top2--;
                    }          
                }
                if (s->b[s->top2]=='['&&x[i-1]!='[')
                {
                    if (s->top2>0)
                    s->top2--;
                }
                if(s->top2==-1)
                {
                    printf("invalid expression3");
                    exit(1);
                }
            }
        }
        else if (x[i]=='}')
        {
            if (s->b[s->top2]=='{'&&x[i-1]=='{')
            {
                printf("invalid expression1");
                exit(1);
            }
            else
            {
                while(s->b[s->top2]!='{'&&s->top2>=0)
                {
                    if (s->b[s->top2]=='('||s->b[s->top2]=='[')
                    {
                        printf("invalid expression2");
                        exit(1);
                    }
                    else
                    {
                        evaluate(s);
                        s->top2--;
                    }          
                }
                if (s->b[s->top2]=='{'&&x[i-1]!='{')
                {
                    if(s->top2>0)
                    s->top2--;
                }
                if(s->top2==-1)
                {
                    printf("invalid expression3");
                    exit(1);
                }
            }
        }
        else if (x[i]=='^')
        {
            s->top2++;
            s->b[s->top2]=x[i];
        }
        else 
        {
            if (compare(s,x[i]))
            {
                s->top2++;
                s->b[s->top2]=x[i];
            }
            else
            {
                printf("invalid expression");
                exit(1);                
            }
        }
    }
    while(s->top2!=-1)
    {
        if (s->b[s->top2]=='('||s->b[s->top2]=='['||s->b[s->top2]=='{')
        {
            s->top2--;
        }
        else
        {
            evaluate(s);
            s->top2--;
        }
    }
}
/**********************************************************************************************************/
void main()
{
    char x[100];
    scanf("%s",x);
    struct stack *s;
    postfix(s,x);
    printf("%d",s->a[0]);    
}
/**********************************************************************************************************/
