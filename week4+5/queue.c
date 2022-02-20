#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char hoten[40];
    char sodt[11];
    struct node* next;
} Node ;
typedef struct {
    Node* head;
    Node* tail;
}Queue;

Node* CreateNode(char name[], char phone[]){
	Node *newnode = (Node*)malloc(sizeof(Node));
	if(newnode == NULL)
		printf("\n Error malloc a node");
		newnode->next = NULL;
		strcpy(newnode->hoten, name);
		strcpy(newnode->sodt, phone);
	return newnode; 
}

Queue *CreateQueue(){
	Queue *newqueue = (Queue*)malloc(sizeof(Queue));
	if(newqueue == NULL) printf("\nError malloc queue");
		newqueue->head = NULL;
		newqueue->tail = NULL;
	return newqueue;
}

Queue *Enqueue(Queue *qu, char name[], char phone[]){
	if(qu == NULL)
		printf("\n Chua co hang doi");
	else{
		Node *newnode = CreateNode(name, phone);
		if(qu->head == NULL){
			qu->head = newnode;
			qu->tail = newnode;
		return qu;
		}
		else{
			qu->tail->next = newnode;
			qu->tail = newnode;
		return qu;
		}
	}		
}

Queue *Dequeue(Queue *qu){
	if(qu == NULL)	
		printf("\nKhong co hang doi");
	else{
		printf("\n\n ---> Lay ra: %s, sdt: %s\n", qu->head->hoten, qu->head->sodt);
		Node *temp = qu->head;
		qu->head = qu->head->next;
		free(temp);
	}
	return qu;
}

int main(){
	Queue *q1 = CreateQueue();
	Enqueue(q1, "An", "1234");
	Enqueue(q1, "Binh", "1234");
	Enqueue(q1, "Chi", "1234");
	
	printf("\n------------Hang Doi-------------\n");
	Node *cur = q1->head;
		while(cur!=NULL){
			printf(" \n  hoten: %s, sdt: %s", cur->hoten, cur->sodt);
			cur = cur->next;
		}

	
	Dequeue(q1);
	

	cur = q1->head;
		while(cur!=NULL){
			printf(" \n  hoten: %s, sdt: %s", cur->hoten, cur->sodt);
			cur = cur->next;
		}
		
	free(q1);
}
