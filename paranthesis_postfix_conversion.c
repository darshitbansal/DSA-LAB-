#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
/**********************************************************************************************************/
struct stack
{
    char a[100];
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
int compare(struct stack *s,char a)
{
        if(a=='/')
        {
            if(s->b[s->top2]=='+'||s->b[s->top2]=='-'||s->b[s->top2]=='/'||s->b[s->top2]=='*')
            {
                return 1;
            }
            else if(s->b[s->top2]=='^')
            {
                s->top1++;
                s->a[s->top1]=s->b[s->top2];
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
            if(s->b[s->top2]=='+'||s->b[s->top2]=='-'||s->b[s->top2]=='*')
            {
                return 1;
            }
            else if(s->b[s->top2]=='^'||s->b[s->top2]=='/')
            {
                s->top1++;
                s->a[s->top1]=s->b[s->top2];
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
            if(s->b[s->top2]=='-')
            {
                return 1;
            }
            else if(s->b[s->top2]=='+'||s->b[s->top2]=='^'||s->b[s->top2]=='/'||s->b[s->top2]=='*')
            {
                s->top1++;
                s->a[s->top1]=s->b[s->top2];
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
                s->top1++;
                s->a[s->top1]=s->b[s->top2];
                s->top2--;
                compare(s,a);
            }
            else if (s->b[s->top2]=='-'||s->b[s->top2]=='+')
            {
                return 1;
            }
            else
            {
                return 1;
            }
        }
}
/**********************************************************************************************************/
void postfix(struct stack *s , char x[])
{
    create(s);
    for(int i=0;x[i]!='\0';i++)
    {
        if(( (int)x[i]>=65 && (int)x[i]<=90)||((int)x[i]>=97 && (int)x[i]<=122))
        {
            s->top1++;
            s->a[s->top1]=x[i];
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
                        s->top1++;
                        s->a[s->top1]=s->b[s->top2];
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
                        s->top1++;
                        s->a[s->top1]=s->b[s->top2];
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
                        s->top1++;
                        s->a[s->top1]=s->b[s->top2];
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
            s->top1++;
            s->a[s->top1]=s->b[s->top2];
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
    printf("%s",s->a);    
}
/**********************************************************************************************************/
