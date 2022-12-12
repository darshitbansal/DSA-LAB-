#include<stdio.h>
int insertion_sort(int a[],int n)
{
    int i,j,x;
    for (i = 1; i < n; i++)
    {
        x = a[i];
        j = i - 1;
        while ((x < a[j]) && (j >= 0))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = x;
    }
    return 0;
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
    insertion_sort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}   