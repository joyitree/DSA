#include<stdio.h>
#include<stdlib.h>
struct myarray{
    int total_size;
    int used_size;
    int *ptr;
};
void createarray(struct myarray *head, int tsize, int usize){

    //----------------------using dot operator------------------we have to direffer the pointer.

    // (*head).total_size=tsize;
    // (*head).used_size=usize;
    // (*head).ptr=(int *)malloc(tsize * sizeof(int));

    //--------------------using arrow operator--------------------------
    head->total_size=tsize;
    head->used_size=usize;
    head->ptr=(int *)malloc(tsize * sizeof(int));
}
void set(struct myarray *head){
    int n;
    printf("enter the number in the array: ");

    //-------------------------using dot operator----------------------------

    // for(int i=0; i<(*head).used_size; i++){
    //     scanf("%d",&n);
    //     (*head).ptr[i]=n;
    // }

    //---------------------using arrow operator--------------------------
    for(int i=0; i< head->used_size; i++){
        scanf("%d",&n);
        (head->ptr)[i]=n;
    }
}
void show(struct myarray *head){
    printf("the array is: ");

    //----------------------using dot operator-----------------------------

    // for(int i=0; i<(*head).used_size; i++){
    //     printf("%d ", (*head).ptr[i]);
    // }

    //-------------------------using arrow operator-------------------------
    for(int i=0; i< head->used_size; i++){
        printf("%d ", (head->ptr)[i]);
    }
}
int main(){
    struct myarray ele; 
    createarray(&ele, 10, 5);
    set(&ele);
    show(&ele);
    return 0;
}