//deletion are mainly 3 types
//---------------delete from the begining
//---------------delete a node in between
//---------------delete from the end

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
    printf("\nthe linked list is: ");
    struct node *p=head;
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=head);

}

                   /*deletion from begining*/

void deletebegin(){
    struct node *ptr;
    if(head==NULL){
        printf("\nunderflow\n");
    }
    else{
        ptr=head;
        while(ptr->next != head){
            ptr=ptr->next;
        }
        ptr->next=head->next;
        free(head);
        head=ptr->next;
    }
}

                   /*delete the last element*/

void deletelast(){
    struct node * ptr;
    struct node * temp;
    if(head==NULL){
        printf("\nunderflow");
    }
    else{
        temp = head;
        while(temp->next != head){
            ptr=temp;
            temp=temp->next;
        }
        ptr->next = temp->next;
        free(temp);
        printf("\ndeleted successfull");
    }
}

                   /*delete from a given position*/

void deleterandom(int pos){
    struct node *ptr=head;
    struct node *temp;
    if(pos==0){
        deletebegin();
    }
    else{
        if(head==NULL){
            printf("\nunderflow");
        }
        else{
            for(int i=0; i<pos-1; i++){
                ptr=ptr->next;
            }
            temp=ptr->next;
            ptr->next=temp->next;
            free(temp);
            printf("\ndeleted successfully");
        }
    }
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
    display();
    int operation,l;
    printf("\nenter your choice!-----\n 1.delete from begining \n 2.delete from a particular position \n 3.delete from end\n");
    scanf("%d", &operation);
    switch(operation){
        case(1):
        deletebegin();
        display();
        break;
        case(2):
        printf("enter the loation after where you want to insert: ");
        scanf("%d",&l);
        deleterandom(l);
        display();
        break;
        case(3):
        deletelast();
        display();
        break;
        default:
        printf("invalid choice! ");
    }
    return 0;
}