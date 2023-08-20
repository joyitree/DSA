// ................. a stack is a linear data structure
// ................. it follows LIFO technique 
// ................. stack has only one end.
// ................. operations: push(), pop(), is empty(), is full(), peek(),display()


#include<stdio.h>
#include<stdlib.h>

//structure for node only
struct node{
    int data;
    struct node * next;
};

//create a node function:
struct node * createnode(int data){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

//structure for stack
struct stack{
    struct node * top;
};

//create a stack function:
struct stack * createstack(struct stack * s){
    struct stack * newstack=(struct stack *)malloc(sizeof(struct stack));
    if(newstack == NULL){
        exit;
    }
    newstack->top=NULL;
    return newstack;
}

//stack is empty
int isempty(struct stack * s){
    return (s->top==NULL);
}

//push function
void push(struct stack * s, int ele){
    struct node *new = createnode(ele);
    new->next=s->top;
    s->top=new;
}

//pop function
int pop(struct stack * s){
    if(isempty(s)){
        printf("stack is empty.\n");
        return -1;
    }
    struct node * temp=s->top;
    int data=temp->data;
    s->top=s->top->next;
    return data;
}

//peek function
void peek(struct stack * s){
    if(isempty(s)){
        printf("stack is empty.\n");
    }
    else{
        printf("%d",s->top->data);
    }
}

//display function
void display(struct stack * s){
    if (isempty(s)) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack elements:\n");
        struct node* current = s->top;
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}

//main function:
int main(){
    struct stack * s1;
    createstack(s1);
    int n,choice;
    printf("\n\t STACK OPERATIONS USING LINKED LIST");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.PEEK\n\t 5.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("enter the total no. of node to insert at linked list: ");
                scanf("%d", &n);
                for(int i=0; i<n; i++){
                    int ele;
                    printf("enter the element: ");
                    scanf("%d", &ele);
                    push(s1, ele);
                }
                break;
            }
            case 2:
            {
                pop(s1);
                break;
            }
            case 3:
            {
                display(s1);
                break;
            }
            case 4:
            {
                peek(s1);
                break;
            }
            case 5:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4/5)");
            }
                
        }
    }
    while(choice!=5);
    while(!isempty(s1)){
        pop(s1);
        free(s1);
    }
    return 0;
}