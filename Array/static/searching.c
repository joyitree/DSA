#include<stdio.h>
int main(){
    int n,ele,flag=0;
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
    printf("\nenter the element to be searched: ");
    scanf("%d",&ele);
    for(int i=0; i<n; i++){
        if(arr[i]==ele){
            flag=1;
        }
    }
    if(flag==0){
        printf("the element doesn't exit in the array");
    }
    else if(flag==1){
        for(int i=0; i<n; i++){
            if(arr[i]==ele){
                printf("the element %d present in the array at position %d", ele,arr[i]);
                break;
            }
        }
    }
    return 0;
}