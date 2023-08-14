// insertion are mainly 3 types
//---------------insert at begining
//---------------insert after the node
//---------------insert at end

#include <stdio.h>  
#include <stdlib.h>  
//Represent a node of singly linked list  
struct node{  
    int data;  
    struct node *next;  
};      

void traversal(struct node *ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *head, *tail = NULL;

void create(int ele){
    struct node * newNode = (struct node *)malloc(sizeof(struct node *));
    newNode->data = ele;
    newNode->next = NULL;

    if(head == NULL){
        head=tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}

              /* insert at the begining */

void insertbegining(int ele1){
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = ele1;
    ptr->next = head;
    head =  ptr;
    printf("node inserted! ");
}

              /*insert at a particular index*/

void insertrandom(int ele2, int loc){
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    struct node *temp;
    temp = head;
    ptr->data =ele2;
    for(int i=0; i<loc-1; i++){
        temp = temp->next;
        if(temp == NULL){
            printf("can't insert! ");
            return;
        }
    }
    ptr->next = temp->next;
    temp->next = ptr;
    printf("node inserted\n");
}

              /*insert at the end*/

void insertend(int ele3){
    struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    struct node *temp;
    ptr->data = ele3;
    ptr->next = NULL;
    temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    temp->next = ptr; 
}

int main(){
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int num;
        printf("enter the element: ");
        scanf("%d", &num);
        create(num);
    }
    traversal(head);
    int new,operation;
    printf("\nenter your choice!-----\n 1.insert at begining \n 2.insert after a given node \n 3.at the end\n");
    scanf("%d", &operation);
    switch(operation){
        case(1):
        printf("\nenter the new element that you want to insert: ");
        scanf("%d", &new);
        insertbegining(new);
        traversal(head);
        break;
        case(2):
        printf("\nenter the new element that you want to insert: ");
        scanf("%d", &new);
        int l;
        printf("enter the loation after where you want to insert: ");
        scanf("%d",&l);
        if(l>=0){
            insertrandom(new, l);
            traversal(head);
        }
        break;
        case(3):
        printf("\nenter the new element that you want to insert: ");
        scanf("%d", &new);
        insertend(new);
        traversal(head);
        break;
        default:
        printf("invalid choice! ");
    }
    return 0;
}