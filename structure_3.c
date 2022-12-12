#include<stdio.h>
int main()
{
    struct student
    {
       int r;
       char name[30];
       int marks;
       int age;
       char address[100];
    }s[15];
    
    for (int i=0;i<15;i++)
    scanf("%d%s%d%s%d",&s[i].r,s[i].name,&s[i].age,s[i].address,&s[i].marks);
    for (int i=0;i<15;i++){
    printf("%d %s %d %s %d",s[i].r,s[i].name,s[i].age,s[i].address,s[i].marks);
    printf("\n");
    }
    return 0;
}