// ................. a stack is a linear data structure
// ................. it follows LIFO technique 
// ................. stack has only one end.
// ................. operations: push(), pop(), is empty(), is full(), peek(),display()


#include<stdio.h>
#include<stdlib.h>

//maximu size of array
#define max_size 100
int size;

//define stack using structure
typedef struct stack{
    int data[max_size];
    int top;
}stack;

//create stack function
void createstack(stack * s){
    s->top=-1;
}

//is empty function
int isempty(stack * s){
    return(s->top==-1);
}

//is empty function
int isfull(stack * s){
    return(s->top==max_size-1);
}

//push function
void push(stack * s, int val){
    if(isfull(s)){
        printf("stack is full\n");
        return;
    }
    else{
        s->top++;
        s->data[s->top]=val;
    }
}

//pop function
void pop(stack * s)
{
    if(isempty(s)){
        printf("\nStack is empty: ");
    }
    else
    {
        s->top--;
    }
}

//peek function
int peek(stack * s){
    if(isempty(s)){
        printf("the stack is empty");
    }
    else{
        printf("%d", s->data[s->top]);
    }
}

//display function
void display(stack* s) {
    if (isempty(s)) {
        printf("Stack is empty");
    } else {
        printf("Stack elements:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
}

//main function
int main(){
    stack s;
    createstack(&s);
    int choice;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&size);
    printf("\n\t STACK OPERATIONS USING ARRAY");
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
                for(int i=0; i<size; i++){
                    int ele;
                    printf("enter the element: ");
                    scanf("%d", &ele);
                    push(&s, ele);
                }
                break;
            }
            case 2:
            {
                pop(&s);
                break;
            }
            case 3:
            {
                display(&s);
                break;
            }
            case 4:
            {
                peek(&s);
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
    return 0;
}