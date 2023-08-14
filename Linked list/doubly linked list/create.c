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
      
    //Displays the nodes present in the list  
    printf("the doubly linked list: ");
    display();  
   
    return 0;  
} 