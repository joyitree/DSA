//here a array will create statically

#include<stdio.h>
int main(){
    int n;
    printf("enter a number: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the data: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("the array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}