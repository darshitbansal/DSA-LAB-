#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int q[100];
    int f;
    int r;
};

void initialise(struct queue *s1)
{
    s1->f=-1;
    s1->r=-1;
}

int insert(struct queue *s1,int n)
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
    printf("Enter Element : ");
    scanf("%d",&item);
    s1->q[s1->r]=item;
}

int delete(struct queue *s1,int n)
{
    if (s1->f==-1)
    {
        printf("underflow\n");
        return 0;
    }
    printf("Element Deleted :- %d\n",s1->q[s1->f]);
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
    printf("Empty\n");
    else
    printf("Non-Empty\n");
}

void main()
{
    struct queue s;
    initialise(&s);
    int n;
    printf("Enter Size of Queue :");
    scanf("%d",&n);
    while(1)
    {
        printf("    FUNCTIONS\n1 -->  Insert at Rear\n2 -->  Delete at Front\n3 -->  check IsEmpty\n4 -->  Exit\nEnter your choice : ");
        int x;
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            insert(&s,n);
            break;

            case 2:
            delete(&s,n);
            break;       

            case 3:
            empty(&s);
            break;

            case 4:
            exit(1);
        }
    }
}
