#include <stdio.h>    
     
int main()    
{         
    int x;
    printf("enter size of array");
    scanf("%d",&x);
    int a[x];        
    printf("enter array: \n");    
    for (int i = 0; i < x; i++) 
    {     
        scanf("%d",&a[i]);     
    }
    printf("Array in reverse order: \n");
    for (int i = x-1; i >= 0; i--) {     
        printf("%d ", a[i]);     
    }     
    return 0;    
}