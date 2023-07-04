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
    for(int i=0; i< head->used_size; i++){
        printf("%d ", (head->ptr)[i]);
    }
}
int deletion(struct myarray *head, int pos){
    if(pos>=(head->used_size)){
        printf("\nposition not found");
    }
    else{
        for(int i=pos-1; i<=(head->used_size)-1; i++){
            (head->ptr)[i]=(head->ptr)[i+1];
        }
        (head->used_size)--;
    }
    return pos;
}
int main(){
    struct myarray ele;
    createarray(&ele, 10, 5);
    set(&ele);
    printf("\nthe array is: ");
    show(&ele);
    deletion(&ele, 4);
    printf("\nthe new array is: ");
    show(&ele);
    return 0;
}