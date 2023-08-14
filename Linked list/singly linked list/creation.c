#include <stdio.h>  
#include <stdlib.h>  
//Represent a node of singly linked list  
struct node{  
    int data;  
    struct node *next;  
};      
   
//Represent the head and tail of the singly linked list  
struct node *head, *tail = NULL;  
   
//addNode() will add a new node to the list  
void addNode(int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    }  
}    
void display() {
    //Node current will point to head  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of singly linked list: \n");  
    while(current != NULL) {   
        printf("%d ", current->data);  
        current = current->next; 
    }
    printf("\n");  
} 

void print_Middle ()
{
  struct node *first_ptr = head;
  struct node *second_ptr = head;

  if (head != NULL)
    {
      //the only logic is to traverse the linked list with two pointers
      //one at normal speed and other twice the speed of first
      /*when the fast pointer reaches to the end, slow pointer will be in 
         the middle of the linted list */
        while (second_ptr != NULL && second_ptr->next != NULL)
	    {
	        second_ptr = second_ptr->next->next;
	        first_ptr = first_ptr->next;
	    }
        printf ("The middle element in the linked list is : %d", first_ptr->data);
    }
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
        addNode(num);
    }
    display();  
    print_Middle();
    printf("\n");
    reverse(head);
    display();
    return 0;  
}  