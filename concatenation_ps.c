#include<stdio.h>
int main()
{
    char a[20],b[20],c[40];
    int p=0,q=0;
    printf("enter name ");
    scanf("%s%s",a,b);
    for (int i=0;a[i]!='\0';i++)
    {
        p++;
    }
    for (int i=0;b[i]!='\0';i++)
    {
        q++;
    }    
    for (int i=0;i<p+q;i++)
    {
        if (i<p)
        c[i]=a[i];
        else
        c[i]=b[i-p];
    }
    for (int i=0;i<p+q;i++)
    {
        printf("%c",c[i]);
    }
    return 0;
}
