#include<stdio.h>
int main()
{
    struct student
    {
       int r;
       char name[30];
       int marks;
       int age;
    }s[5];
    
    for (int i=0;i<5;i++)
    scanf("%d%s%d%d",&s[i].r,s[i].name,&s[i].age,&s[i].marks);
    for (int i=0;i<5;i++){
    printf("%d %s %d %d",s[i].r,s[i].name,s[i].age,s[i].marks);
    printf("\n");
    }
    return 0;
}