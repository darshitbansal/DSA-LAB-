#include<stdio.h>
#include<string.h>

// prefix

void main()
{
    char x[100];
    int a;
    scanf("%s",x);
    for (int i=1;x[i]!='\0';i++)
    {
        for (int j=0;x[j]!='\0';j++)
        {
            if(j<=i-1)
            printf("%c",x[j]);
        }
        printf("\n");
    }
}

// suffix

void main()
{
    char x[100];
    scanf("%s",x);
    int a=strlen(x);
    for (int i=1;i<a;i++)
    {
        for (int j=1;j<=i;j++)
        {
            if(j<=i)
            printf("%c",x[a-j]);
        }
        printf("\n");
    }
}
