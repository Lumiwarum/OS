#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define INIT_NODE(name) struct node* name =(struct node*) malloc(sizeof(struct node));// initializating macro

struct node{
int value;
struct node* next;
};

void printList(struct node *head);
void insertNode(struct node *head, struct node *newnode, struct node *prevnode);
void deleteNode(struct node *head, struct node *delnode);

int main(){
INIT_NODE(node1);//start of initializing nodes
INIT_NODE(node2);
INIT_NODE(node3);
INIT_NODE(node4);
node1->next=NULL;
node2->next=NULL;
node3->next=NULL;
node4->next=NULL;
node1->value=1;
node2->value=2;
node3->value=3;
node4->value=4;// end of initialazing nodes

insertNode(node1,node2,node1);//creating linked list
insertNode(node1,node3,node2);
printf("Linked list before changes:\n");
printList(node1);
insertNode(node1,node4,node2);
printf("Linked list after inserting node with value 4 after the node with value 2:\n");
printList(node1);
deleteNode(node1,node2);
printf ("Linked list after deleting node with value 2:\n");
printList(node1);
}

//This function takes as a parametr pointer to head of Linked list and print all its elements
void printList(struct node *head){
while (head->next!=0){
	printf("%d\n",head->value);
	head=head->next;
}
printf("%d\n",head->value);
}

/*
* This function takes as parameters pointer to head of linked list, to node that need to be inserted and to node
* after which it need to be inserted
* Function first checks that this node is presented in the linked list. If it does, insert the node
*/
void insertNode(struct node *head, struct node *newnode, struct node *prevnode){
bool inList=false;
while (head->next!=0){
	if (head==prevnode){
		inList=true;
		break;
	}
	head=head->next;
}

if (head==prevnode){
inList=true;
}

if (!inList){
return;
}
newnode->next=prevnode->next;
prevnode->next=newnode;
}
/*
* This function take as parameters pointer to head of the Linked list and pointer to the node that need to be removed
* Function search for the node throuh the Linked list and delete it
*/
void deleteNode(struct node *head, struct node *delnode){
while (head->next!=0){
	if (head->next==delnode){
		head->next=delnode->next;
		free(delnode);
		break;
	}
}
}
