#include<stdio.h>
#include<stdlib.h>

typedef int elementType;

struct List{
	elementType data;
	struct List *next;
};

typedef struct List NodeType;

//NodeType *head;

NodeType *CreateNode(elementType value){
	NodeType *newnode;
		newnode = (NodeType*)malloc(sizeof(NodeType));
		if(newnode == NULL) printf("Cap phat bo nho fail \n");
		else{
		newnode->data = value;
		newnode->next = NULL;
		}
	return newnode;
}

NodeType *InsAf(NodeType *prev, elementType value){
	NodeType *newnode;
	newnode = CreateNode(value);
		newnode->next = prev->next;
		prev->next = newnode;
	return newnode;	
}

NodeType *InsHead(NodeType *head, elementType value){
	NodeType *newnode;
	newnode = CreateNode(value);
		newnode->next =	head;
		head = newnode; 
	return head;	
}

NodeType *InsLast(NodeType *head, elementType value){
	NodeType *currnode;
	NodeType *newnode;
		newnode = CreateNode(value);
		currnode = head;
	
	if(head == NULL)
		head = newnode;
	else{
		while(currnode->next != NULL)
			currnode = currnode->next;
		currnode->next = newnode;
	}
	return head;		
}

void Traversal(NodeType *head){
	NodeType *curr;
	curr = head;
		while(curr != NULL){
			printf("%d", curr->data);
			curr = curr->next;
			if(curr != NULL)
				printf(" -> ");
		}
}

int isEmpty(NodeType *head){
	return !head;
}

elementType DelAf(NodeType *prev){
	NodeType *temp;
	elementType value;
		temp = prev->next;
		value = temp -> data;
		prev->next = prev->next->next;
		free(temp);
	return value;
}

NodeType *DelHead(NodeType *head){
	if(head == NULL)return NULL;
	else{
	NodeType *temp;
		temp = head->next;
		free(head);
	return temp;
	}
}

NodeType *DelTail(NodeType *head){
	NodeType *temp1, *temp2;
	temp1 = head; temp2 = head;
		while(temp1->next != NULL){
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = NULL;
		free(temp1);
	return head;
}

NodeType *Search(NodeType* head, elementType value){
	while (head->data != value)
		head = head->next;
	return head; //tra ve con tro den vi tri can tim	
}	

void freelist(NodeType *head){
	NodeType *temp1, *temp2;
		temp1 = head;
		while(temp1!=NULL){
			temp2 = temp1->next;
			free(temp1);
			temp1 = temp2;
		}
}

int main(){
	NodeType *head = NULL, *A = NULL, *B = NULL, *C = NULL, *D = NULL, *E = NULL;
	elementType a;
	int i, n;
		head = InsHead(head, 0);
		A = InsAf(head, 1);
		B = InsAf(A, 2);
		C = InsAf(B, 5); //0->1->2->5
		D = InsAf(A, 3);
		head = InsLast(head, 7); //0->1->3->2->5->7
		
		printf("-----------Danh sach lien ket---------\n\n");
	
		printf("List is %s\n\n", isEmpty(head) != 1 ? "not empty" : "empty" );
		Traversal(head);
	
		printf("\n\nXoa nut %d: ", DelAf(B)); //0->1->3->2->7
		Traversal(head);
		
		printf("\n\nXoa nut dau: ");
		NodeType *newhead;
		newhead = DelHead(head); //1->3->2->7
		Traversal(newhead);
		
		printf("\n\nXoa nut cuoi: "); 
		newhead =  DelTail(newhead);//1->3->2
		Traversal(newhead);
		
		freelist(newhead);
	return 0;
}
