//deletion are mainly 3 types
//---------------delete from the begining
//---------------delete a node in between
//---------------delete from the end

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

                /*delete the first element*/

void deletebegining(){
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    printf("\ndelete sucecessfull!\n");
}
 
                /*delete the node in between*/

void deleteindex(int loc){
    struct node * ptr = head;
    for(int i=0; i<loc-1; i++){
        ptr=ptr->next;
    }
    struct node * temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("\nelement deleted successfully\n");
}

                /*delete the last element*/

void deletelast(){
    struct node *ptr = head;
    struct node *temp = head->next;
    while(temp->next != NULL){
        ptr=ptr->next;
        temp=temp->next;
    }
    ptr->next=temp->next;
    free(temp);
    printf("\nsucessfully deleted last item\n");
}
int main(){
    int n,l;
    printf("enter the number: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int num;
        printf("enter the element: ");
        scanf("%d", &num);
        create(num);
    }
    traversal(head);
    printf("\nenter your choice:\n 1.delete the first node:\n 2.delete the node from a particular index:\n 3.delete the last node:\n");
    int operation;
    printf("enter the choice: ");
    scanf("%d", &operation);
    switch(operation){
        case(1):
        deletebegining();
        traversal(head);
        break;
        case(2):
        printf("enter the index: ");
        scanf("%d",&l);
        if(l>=0){
            deleteindex(l);
            traversal(head);
        }
        break;
        case(3):
        deletelast();
        traversal(head);
        break;
        default:
        printf("invalid choice! ");
    }
    return 0;
}