#include<stdio.h>
#include<stdlib.h>
struct myarray{
    int total_size;
    int used_size;
    int *ptr;
};
void createarray(struct myarray *head, int tsize, int usize){
    head->total_size=tsize;
    head->used_size=usize;
    head->ptr=(int *)malloc(tsize * sizeof(int));
}
void set(struct myarray *head){
    int n;
    printf("enter the element in the array: ");
    for(int i=0; i< head->used_size; i++){
        scanf("%d",&n);
        (head->ptr)[i]=n;
    }
}
void show(struct myarray *head){
    printf("the array is: ");
    for(int i=0; i< head->used_size; i++){
        printf("%d ", (head->ptr)[i]);
    }
}
void insert(struct myarray *head, int new, int pos){
    if(pos>(head->total_size)){
        printf("\narray is full");
    }
    else{
        head->used_size=(head->used_size)+1;
        for(int i=(head->used_size)-1; i>=pos; i--){
            (head->ptr)[i]=(head->ptr)[i-1];
        }
        (head->ptr)[pos-1]=new;
    }
}
int main(){
    struct myarray ele;
    createarray(&ele, 10, 5);
    set(&ele);
    show(&ele);
    insert(&ele, 100, 2);
    printf("\nthe new array: ");
    show(&ele);
}