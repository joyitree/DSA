// insertion are mainly 3 types
//---------------insert at begining
//---------------insert after the node
//---------------insert at end


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
    printf("the linked list is: ");
    struct node *p=head;
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=head);

}

                   /*insert at begining*/

void insertbegining(int ele){
    struct node *ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->data =ele;
    struct node *temp = head->next;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->next =head;
    head=ptr;
    printf("\nnode inserted\n");
}

                    /*insert at the end*/

void insertlast(int ele){
    struct node *ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->data=ele;
    struct node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=head;
    printf("\nnode inserted\n");
}

                    /*insert at a given position*/

void insertrandom(int ele, int index){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=ele;
    struct node *temp=head;
    if(index==0){
        insertbegining(ele);
    }
    else{
        for(int i=0; i<index-1; i++){
            temp=temp->next;
            if(temp==head){
                printf("can't insert");
                return;
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("\nnode inserted\n");
    }

}

int main(){
    int n,new;
    printf("enter the no. of data: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        printf("enter the element: ");
        scanf("%d", &x);
        create(x);
    }
    display();
    int operation;
    printf("\nenter your choice!-----\n 1.insert at begining \n 2.insert after a given node \n 3.at the end\n");
    scanf("%d", &operation);
    switch(operation){
        case(1):
        printf("\nenter the new element that you want to insert: ");
        scanf("%d", &new);
        insertbegining(new);
        display();
        break;
        case(2):
        printf("\nenter the new element that you want to insert: ");
        scanf("%d", &new);
        int l;
        printf("enter the loation after where you want to insert: ");
        scanf("%d",&l);
        if(l>=0){
            insertrandom(new, l);
            display();
        }
        break;
        case(3):
        printf("\nenter the new element that you want to insert: ");
        scanf("%d", &new);
        insertlast(new);
        display();
        break;
        default:
        printf("invalid choice! ");
    }
    return 0;
}