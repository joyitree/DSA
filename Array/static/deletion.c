#include<stdio.h>
int main()
{
   int n,pos;
   printf("Enter the number: ");
   scanf("%d", &n);
   int arr[n];
   printf("Enter %d elements\n", n);
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
   }
   printf("the array is: ");
   for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
   }
   printf("\nEnter the location to delete element: ");
   scanf("%d", &pos);
   if (pos>= n)
      printf("Deletion not possible.\n");
   else
   {
      for (int i=pos- 1; i<n-1; i++){
        arr[i] = arr[i+1];
      }
      printf("the final array is: ");
      for (int i = 0; i<n-1; i++)
         printf("%d ", arr[i]);
   }
   int count=sizeof(arr[n]);
   printf("\nthe new size of array is: %d", count);
   return 0;
}
