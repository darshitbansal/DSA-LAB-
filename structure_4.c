#include<stdio.h>
int main()
{
    struct student
    {
       float d1;
       float d2;
       
    }s;
    printf("enter 1st distance in inches");
    scanf("%f",&s.d1);
    printf("enter 1st distance in inches");
    scanf("%f",&s.d2);
    printf("%f",(s.d1+s.d2)/12);
    return 0;
}
