#include <stdio.h>

int main()
{ 
  int arr[10] ;
  int i, j, n,tmp;
  printf("enter total element:");
  scanf("%d",&n);
  printf("enter arrary element:");
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
   //display the array elements
   for (i=0; i <n; ++i)
   {
      printf("%4d", arr[i]);
   }
 
  for (i=1 ; i <=n-1; i++) {
    j = i;
 
    while (j > 0 && arr[j-1] > arr[j]) {
      tmp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = tmp;
 
      j--;
    }
  }
 
  printf("\n*** Array Sorted in Ascending Order ***\n");
 
  for (i=0; i < n; i++)
     printf("%4d", arr[i]);
 
  return 0;
}