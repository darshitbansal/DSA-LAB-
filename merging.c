#include <stdio.h>
int main()
{
    int n,m, a[10], b[10], i, j, k=0,c[100];
    printf("Enter the elements size:");
    scanf("%d",&m);
    printf("Enter the elements size:");
    scanf("%d",&n);
    printf("Enter the first elements->:");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the second elements->:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    i=0;
    j=0;
    while(i<m&&j<n)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else if (a[i]>b[j])
        {
            c[k]=b[j];
            k++;
            j++;
        }
        else
        {
            c[k]=a[i];
            k++;
            i++;
            j++;
        }
    }
    while(i<m)
    {
        c[k]=a[i];
        k++; 
        i++;
    }
    while(j<n)
    {
        c[k]=b[j];
        k++;
        j++;
    }
    for(i=0;i<k;i++)
    printf("%d",c[i]);
    return 0; 
}