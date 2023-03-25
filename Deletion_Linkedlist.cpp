//[4][.]-[3][.]-[8][.]-[1][.]-[2][.]
//case 1:-Deleting the first node
//case 2:-Deleting a node in between
//case 3:- Delete the last node
//case 4:- Delete a node with a given value
#include<stdio.h>
#include<stdlib.h>
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
//Case 1:-Deleting the first element from linked list
struct Node *deleteFirst(struct Node * head){
	struct Node *ptr = head;
	head= head->next;
	free(ptr);
	return head;
}
//Case 2:-Deleting the element at given index from linked list
struct Node *deleteAtIndex(struct Node * head,int index){
	struct Node *p = head;
	struct Node *q = head->next;
	for(int i =0; i<index-1;i++){
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);

	return head;
}
//Case 3:-Deleting the last element from linked list
struct Node *deletelast(struct Node * head){
	struct Node *p = head;
	struct Node *q = head->next;
	while(q->next != NULL){
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);

	return head;
}
//Case 4:-Deleting the node with given value from linked list
struct Node *deleteNode(struct Node * head,int value){
	struct Node *p = head;
	struct Node *q = head->next;
	while(q->data!=value && q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	if(q->data == value){
		p->next=q->next;
		free(q);
		
	}

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
	head->data = 4;
	head->next =second;
	
		//link second and third nodes
	second->data =3;
	second->next =third;
	
		//link third and fourth nodes
	third->data =8;
	third->next =fourth;
	
		//terminate list at the fourth nodes
	fourth->data = 1;
	fourth->next =NULL;
	printf("Linked list before deletion\n");
	linkedlistTraversal(head);
	
//	head = deleteFirst(head);  //For deleting the first element from linked list
//	head = deleteAtIndex(head,2);
  //  head = deletelast(head);
    head = deleteNode(head,3);
	printf("Linked list after deletion\n");
	linkedlistTraversal(head);



return 0;
}


