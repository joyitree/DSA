#include<stdio.h>
int main(){
    int n,ele,pos;
    printf("enter the number: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array element: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("the array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    n++;
    printf("\nenter the element and the position: ");
    scanf("%d %d", &ele,&pos);
    for(int i=n-1; i>=pos; i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=ele;
    printf("the new array is: ");
    for(int i=0; i<n ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}