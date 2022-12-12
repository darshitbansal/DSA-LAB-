#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int q[5];
    int f;
    int r;
};

void initialise(struct queue *s1)
{
    s1->f=-1;
    s1->r=-1;
}

int insert_rear(struct queue *s1,int n)
{
    if ((s1->f==0&&s1->r==n-1)||(s1->f==s1->r+1))
    {
        printf("overflow\n");
        return 0;
    }
    if (s1->f==-1&&s1->r==-1)
    {
        s1->f=0;
        s1->r=0;
    }
    else if (s1->r==n-1)
    {
        s1->r=1;
    }
    else
    {
        s1->r++;
    }
    int item;
    scanf("%d",&item);
    s1->q[s1->r]=item;
}

int insert_front(struct queue *s1,int n)
{
    if ((s1->f==0&&s1->r==n-1)||(s1->f==s1->r+1))
    {
        printf("overflow\n");
        return 0;
        
    }
    if (s1->f==-1&&s1->r==-1)
    {
        s1->f=0;
        s1->r=0;
    }
    else if (s1->f==0)
    {
        s1->f=n-1;
    }
    else
    {
        s1->f--;
    }
    int item;
    scanf("%d",&item);
    s1->q[s1->f]=item;
}

int delete_rear(struct queue *s1,int n)
{
    if (s1->r==-1)
    {
        printf("underflow\n");
        return 0;
    }
    printf("%d\n",s1->q[s1->r]);
    if (s1->f==s1->r)
    {
        s1->f=-1;
        s1->r=-1;
    }
    else if (s1->r==0)
    {
        s1->r=n-1;
    }
    else
    {
        s1->r--;
    }    
}

int delete_front(struct queue *s1,int n)
{
    if (s1->f==-1)
    {
        printf("underflow\n");
        return 0;
    }
    printf("%d\n",s1->q[s1->f]);
    if (s1->f==s1->r)
    {
        s1->f=-1;
        s1->r=-1;
    }
    else if (s1->f==n-1)
    {
        s1->f=1;
    }
    else
    {
        s1->f++;
    }    
}

void empty(struct queue *s1)
{
    if(s1->f==-1&&s1->r==-1)
    printf("empty\n");
    else
    printf("non-empty\n");
}

void main()
{
    struct queue s;
    initialise(&s);
    int n;
    printf("Enter Size of Queue : ");
    scanf("%d",&n);
    while(1)
    {
        printf("    FUNCTIONS\n1 -->  Insert at Rear\n2 -->  Insert at Front\n3 -->  Delete at Rear\n4 -->  Delete at Front\n5 -->  check IsEmpty\n6 -->  Exit\nEnter your choice : ");
        int x;
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            insert_rear(&s,n);
            break;

            case 2:
            insert_front(&s,n);
            break; 

            case 3:
            delete_rear(&s,n);
            break;       

            case 4:
            delete_front(&s,n);
            break;

            case 5:
            empty(&s);
            break;

            case 6:
            exit(1);
        }
    }
}
