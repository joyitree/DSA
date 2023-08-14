//deletion are mainly 3 types
//---------------delete from the begining
//---------------delete a node in between
//---------------delete from the end

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * head, *tail = NULL;

void create(int ele){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void display(){
    printf("\nthe doubly linked list: ");
    struct node * current=head;
    if(head==NULL){
        printf("list is empty");
        return;
    }
    while(current!=NULL){
        printf("%d ", current->data);
        current=current->next;
    }
    printf("\n");
}

                  /*delete from first*/

void deletefirst(){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    printf("deleted sucessfully");
}

                   /*delete from between*/

void deleterandom(int loc){
    struct node * ptr=head;
    for(int i=0; i<loc-1; i++){
        ptr=ptr->next;
    }
    struct node * temp;
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    printf("deleted successfully");
}

                  /*delete the last*/

void deletelast(){
    struct node * ptr=head;
    struct node * temp = head->next;
    while(temp->next != NULL){
        ptr=ptr->next;
        temp=temp->next;
    }
    ptr->next=temp->next;
    free(temp);
    printf("deleted successfully");
}
int main()  
{  
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    //Add nodes to the list  
    for(int i=0; i<n; i++){
        int num;
        printf("enter the element: ");
        scanf("%d", &num);
        create(num);
    }
    display();  
    int operation,l;
    printf("\nenter your choice: 1. delete from first, 2.delete from a particular position, 3.delete from last.\n");
    scanf("%d",&operation);
    switch(operation){
        case(1):
        deletefirst();
        display();
        break;
        case(2):
        printf("\nenter the location: ");
        scanf("%d", &l);
        deleterandom(l);
        display();
        break;
        case(3):
        deletelast();
        display();
        break;
        default:
        printf("invalid choice!");
    }
   
    return 0;  
} 