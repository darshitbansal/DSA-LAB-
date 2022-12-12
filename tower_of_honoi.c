#include <stdio.h>
void toh(int n, char A, char B, char C);
void main()
{
    int n = 3;
    toh(3, 'A', 'B', 'C');
}
void toh(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("move disc %d from %c to %c\n", n, A, C);
        return;
    }
    toh(n - 1, A, C, B);
    printf("move disc  %d from %c to %c\n", n, A, B );
    toh(n - 1, B, A, C);
    return;
}