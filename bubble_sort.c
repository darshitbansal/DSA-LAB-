#include<stdio.h>
int bubble_sort(int a[],int n)
{
    int x;
    for (int i=n-1;i>0;i--)
    {
        for (int j=0;j<i;j++)
        {
            if (a[j]>a[j+1])
            {
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    }
}
int main()
{
    int i,n;
    printf("enter size of array");
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    for(int i=0;i<n;i++)

    printf("%d",a[i]);
    return 0;
}