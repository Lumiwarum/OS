#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define INIT_NODE(name) struct node* name =(struct node*) malloc(sizeof(struct node));// initializating macro
#define SET_NODE(name,val) name->next=NULL; name->prev=NULL; name->value=val;
struct node{
int value;
struct node* next;
struct node* prev;
};

void printListHead(struct node *head);
void printListTail(struct node *tail);
void insertNode(struct node *newnode, struct node *prevnode);
void deleteNode(struct node *delnode);

int main(){
INIT_NODE(node1);//start of initializing nodes
INIT_NODE(node2);
INIT_NODE(node3);
INIT_NODE(node4);
SET_NODE(node1,1);
SET_NODE(node2,2);
SET_NODE(node3,3);
SET_NODE(node4,4);// end of initialazing nodes

insertNode(node2,node1);//creating linked list
insertNode(node3,node2);
printf("Doubly linked list before changes:\n");
printListHead(node1);
printf("The same linked list, but printed from tail:\n");
printListTail(node3);
insertNode(node4,node2);
printf("Doubly linked list after inserting node with value 4 after the node with value 2:\n");
printListHead(node1);
printf("The same but from tail:\n");
printListTail(node3);
deleteNode(node2);
printf ("Doubly linked list after deleting node with value 2:\n");
printListHead(node1);
printf("The same but from tail:\n");
printListTail(node3);
}

//This function takes as a parametr pointer to head of Doubly linked list and print all its elements
void printListHead(struct node *head){
while (head->next!=0){
	printf("%d\n",head->value);
	head=head->next;
}
printf("%d\n",head->value);
}
// The same function, but prints from the tail
void printListTail(struct node *tail){
while (tail->prev!=0){
	printf("%d\n",tail->value);
	tail=tail->prev;
}
printf("%d\n",tail->value);
}

/*
* This function takes as parameters pointer to node that need to be inserted and to node
* after which it need to be inserted
*/
void insertNode(struct node *newnode, struct node *prevnode){
if (prevnode->next!=0){
	prevnode->next->prev=newnode;
}
newnode->next=prevnode->next;
prevnode->next=newnode;
newnode->prev=prevnode;
}
/*
* This function take as parameters pointer to the node that need to be removed
*/
void deleteNode(struct node *delnode){
delnode->next->prev=delnode->prev;
delnode->prev->next=delnode->next;
free(delnode);
}
