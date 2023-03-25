#include<stdio.h>
#include<stdlib.h>
//Case1:- Insert at the beginningg
//Case2 :- Insert at the bottom
// Case3:-Insert at the end
// Case4:- Insert after the node

struct Node{
	int data;
	struct Node * next;
};
void linkedlistTraversal(struct Node *ptr){
	while(ptr!=NULL){
	
	printf("Element:%d\n",ptr->data);
	ptr=ptr->next;
	
	}
}
//case 1
struct Node * insertAtFirst(struct Node *head,int data){
	struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->next = head;
	ptr->data=data;
	return ptr;
	
}
//Case 3
struct Node * insertAtEnd(struct Node *head,int data){
	struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->data=data;
	struct Node *p= head;
	while(p->next!=NULL){
		p=p->next;
	}
	ptr->next = ptr;
	ptr->next=NULL;
	return head;
}
//Case 4
struct Node * insertAfterNode(struct Node *head,struct Node *prevNode,int data){
	struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->data=data;
	ptr->next=prevNode->next;
	prevNode->next=ptr;
	return head;
}
//Case 2
struct Node *insertAtIndex(struct Node *head,int data,int index){
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	struct Node *p=head;
	int i =0;
	while(i!=index-1){
		p=p->next;
		i++;
	}
	ptr->data=data;
	ptr->next=ptr->next;
	ptr->next=ptr;
	return head;
}
int main()
{
struct Node * head;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;

	
	//Allocate memory for nodes in the linked list in heap
	head=(struct Node *)malloc(sizeof(struct Node));
	second =(struct Node *)malloc(sizeof(struct Node));
	third =(struct Node *)malloc(sizeof(struct Node));
	fourth =(struct Node *)malloc(sizeof(struct Node));
	
	//link first and second nodes
	head->data = 7;
	head->next =second;
	
		//link second and third nodes
	second->data =9;
	second->next =third;
	
		//link third and fourth nodes
	third->data =10;
	third->next =fourth;
	
		//terminate list at the fourth nodes
	fourth->data = 11;
	fourth->next =NULL;
	
	printf("Linked list before insertion\n");
	linkedlistTraversal(head);
	//head = insertAtIndex(head,56,1);
	//head = insertAtEnd(head,56);
	head = insertAfterNode(head,second,45);
	printf("Linked list after insertion\n");
	linkedlistTraversal(head);

return 0;
}

