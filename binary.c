#include<stdio.h>
int binSer(int arr[],int lo,int hi,int x)
{
      if(lo<=hi)
      {
          int mid = (lo+hi)/2;
          if(arr[mid] == x) return x;
          else if(arr[mid] > x) return binSer(arr,lo,mid-1,x);
          else return binSer(arr,mid+1,hi,x);
      }

      return -1;
}
int main()
{
      int n; 
       printf("enter n:\n");
        scanf("%d",&n);
       
        int arr[n];
        for(int i =0 ;i<n;i++) scanf("%d",arr+i);

        int x; scanf("%d",&x);

        int pos = binSer(arr,0,n-1,x);
         pos == -1? printf("not found\n") : printf("found at index %d\n ",pos-1);
}