#include<stdio.h>
int new(int x);
int main()
{
    int n,a[10],k,i,x;
    printf("size of array\n");
    scanf("%d",&n);
    printf("enter array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter k");
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        if(a[i]<k)
        {
            x=new(a[i]);
            if(x==1)
            {
                printf("%d\t",a[i]);
            }
        }
    }
}
int new(int x)
{
    if(x>9)
    {
        if(x%10-(x/10)%10==1||(x/10)%10-x%10==1)
        {
            new(x/10);
        }
        else
        return 0;
    }
    else
    return 1;
}