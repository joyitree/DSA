#include<stdio.h>
int main(){
    int n,ele,flag=0;
    int i;
    printf("enter the element: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array data: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("the array is: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nenter the element to search: ");
    scanf("%d", &ele);
    for(i=0; i<n; i++){
        if(arr[i] == ele){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("the element found at the position %d in the array.", i+1);
    }
    else{
        printf("'element doesn't found");
    }
    return 0;
}