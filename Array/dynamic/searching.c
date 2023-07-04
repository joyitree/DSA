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
void searching(struct myarray *head, int ele){
    int flag=0;
    for(int i=0; i<(head->used_size); i++){
        if((head->ptr)[i]==ele){
            flag=1;
        }
    }
    if(flag==0){
        printf("\nelement doesn't found");
    }
    else if(flag==1){
        for(int i=0; i<(head->used_size); i++){
            if(head->ptr[i]==ele){
                printf("\nelement %d is found at position %d.", ele, (head->ptr)[i]);
            }
        }
    }
}
int main(){
    struct myarray ele;
    createarray(&ele, 10, 4);
    set(&ele);
    show(&ele);
    searching(&ele, 3);
    return 0;
}