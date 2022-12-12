#include <stdio.h>
int main()
{
    struct student
    {
        int r;
        char name[30];
        float m[6];
    } s;
    scanf("%d%s", &s.r, s.name);
    float min = 100, sum = 0;
    for (int i = 0; i < 6; i++)
    {
        scanf("%f", &s.m[i]);
        sum = sum + s.m[i];
        if (min > s.m[i])
        {
            min = s.m[i];
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (s.m[i] == min)
            s.m[i] = 100;
    }
    sum -= min;
    min = 100;
    for (int i = 0; i < 6; i++)
    {
        if (min > s.m[i])
            min = s.m[i];
    }
    sum -= min;
    if (sum / 4 >= 95)
        printf("eligible");
    else
        printf("not eligible");
    return 0;
}