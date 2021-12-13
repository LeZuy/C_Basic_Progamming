#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{SUCESS,FAIL, SIZE = 100};

typedef struct {
	char name[20];
    char phone[10];
   	char email[20];
}PhoneBook;

typedef struct LinkedList{
    PhoneBook data;
    struct LinkedList *next;
}*node;

int reval = SUCESS;
node head = NULL;


node CreateNode(PhoneBook value){
	node temp;
    temp = (node)malloc(sizeof(struct LinkedList)); 
    	temp->next = NULL;
    	temp->data = value; 
    return temp;
}

void Insert(node *headref, PhoneBook data){
    node p, new = CreateNode(data);
    if(*headref == NULL){
    	*headref = new;
	}
	else{
		p = *headref;
		while(p->next != NULL){
    	p = p->next;
    }
    p->next = new;
	}
}

void DelNode(node* nodeDel, node *headref){
    if(*nodeDel == *headref){
        *headref = (*headref)->next;
        free(*headref);
    }
	else{
        node* cur;
        for(cur = headref; (*cur)->next != *nodeDel; cur = &((*cur)->next));
        
        (*cur)->next = (*cur)->next->next;
        free(*nodeDel);   
    }
}
void readinput(){
    FILE *fp ;
    PhoneBook input;
    if((fp = fopen("PhoneBook.txt", "r")) == NULL){
    	printf("Can't open file!\n");
        reval = FAIL;
    }
    else{
    while(fscanf(fp, "%s %s %s", input.name, input.phone, input.email) != EOF){
        Insert(&head,input);
    	}
	}
    fclose(fp);
}

void printList(){
    printf("%-20s %-10s %-20s\n", "Name", "PhoneNum", "Email");
    node cur;
	for(cur = head; cur != NULL; cur = cur->next){
        printf("%-20s %-10s %-20s\n", cur->data.name, cur->data.phone, cur->data.email);
    }
} 

void Search(char name[]){
    node cur, found = NULL;
    FILE *fp;
    for( cur = head; cur != NULL; cur = cur->next){
        if(strcmp(cur->data.name, name) == 0){
            found = cur;
            break;
        }
    }
    fp = fopen("Result.txt", "w");
    if(found == NULL){
        fprintf(fp, "Name not found!\n");
    }
	else{
        fprintf(fp, "Name: %s \nPhone number: %s \nEmail: %s \n", found->data.name, found->data.phone, found->data.email);
        if(found != head){
		
            PhoneBook fvalue = found->data;
            DelNode(&found, &head);
        
            node new = CreateNode(fvalue); 
            new ->next = head;
            head = new;
        }
    }
    fclose(fp);
}

int main(){
	 char key_name[20];
    	readinput();		//Doc file input
    	printf("Nhap ten ban muon tim: "); 
			fflush(stdin); gets(key_name);
    
		Search(key_name);
    	printList();
    return reval;
}




