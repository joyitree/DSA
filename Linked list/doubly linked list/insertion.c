// insertion are mainly 3 types
//---------------insert at begining
//---------------insert after the node
//---------------insert at end

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

                  /*insert at begining*/

void insertbegining(int ele){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=ele;
    ptr->prev=NULL;
    ptr->next=head;
    head=ptr;
    printf("\n node inserted\n");
}

                  /*insert at after a node*/

void insertrandom(int ele, int pos){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=ele;
    struct node * temp =head;
    if(pos==0){
        insertbegining(ele);
    }
    else{
        for(int i=0; i<pos-1; i++){
            temp=temp->next;
            if(temp==NULL){
                printf("can't insert");
                return;
            }
        }
        ptr->next=temp->next;
        ptr->prev=temp;
        temp->next=ptr;
        printf("node inserted successfully");
    }
}

                  /*insert at end*/

void insertlast(int ele){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * temp = head;
    ptr->data=ele;
    while(temp->next != NULL){
        temp=temp->next;
    }
    ptr->prev=temp->next;
    temp->next=ptr;
    ptr->next=NULL;
    printf("node inserted successfully");
}

int main()  
{  
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int num;
        printf("enter the element: ");
        scanf("%d", &num);
        create(num);
    }
    display(); 
    int operation,num,l;
    printf("\nenter your choice: 1. insert at first, 2.insert at a particular position, 3.insert at last.\n");
    scanf("%d",&operation);
    switch(operation){
        case(1):
        printf("enter the new element: ");
        scanf("%d", &num);
        insertbegining(num);
        display();
        break;
        case(2):
        printf("enter the new element: ");
        scanf("%d", &num);
        printf("\nenter the location: ");
        scanf("%d", &l);
        insertrandom(num,l);
        display();
        break;
        case(3):
        printf("enter the new element: ");
        scanf("%d", &num);
        insertlast(num);
        display();
        break;
        default:
        printf("invalid choice!");
    }
    return 0;  
} 