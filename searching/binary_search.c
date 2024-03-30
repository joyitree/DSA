#include<stdio.h>
int binary_search(int arr[], int size, int ele){
    int low,high,mid;
    low=0;
    high=size-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else if(arr[mid]>ele){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(){
    int n,key;
    printf("enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array data: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("the array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    bubbleSort(arr,n);
    printf("\nafter sorting the array is:");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nenter  the element to be searched: ");
    scanf("%d", &key);
    int result = binary_search(arr,n,key);
    printf("find the element %d at %dth index in the array.",key,result);
    return 0;
}