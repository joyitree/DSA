#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node *head, *tail = NULL;
void create(int ele){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=head;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}
void display(){
    struct node *p=head;
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=head);
    printf("\nthe head is: %d", head->data);
    printf("\nthe tail is: %d", tail->data);

}
int main(){
    int n;
    printf("enter the no. of data: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        printf("enter the element: ");
        scanf("%d", &x);
        create(x);
    }
    printf("the linked list is: ");
    display();
    return 0;
}