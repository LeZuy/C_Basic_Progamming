#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{SUCESS,FAIL, SIZE = 100};

typedef struct {
		char name[20];
    	char phone[10];
    	char email[20];
}PhoneBook;

PhoneBook Queue[SIZE];
int front = 0, rear = 0;
int reval = SUCESS;

void Enqueue(int* rear, PhoneBook data){
    Queue[*rear] = data;
    *rear = (*rear) + 1;
	}
	 
void Dequeue(int *front){
    *front = (*front + 1) % 10;
}

void readinput(){
    FILE *fp ;
    if((fp= fopen("PhoneBook.txt", "r")) == NULL){
        printf("Can't open file!\n");
        reval = FAIL;
    }
    PhoneBook value;
    while(fscanf(fp, "%s %s %s", value.name, value.phone, value.email) != EOF){
        Enqueue(&rear,value);
    }
    fclose(fp);
}

void printList(){
    printf("%-20s %-10s %-20s\n", "Name", "PhoneNum", "Email");
    for(int i = front; i < rear; i++){
        printf("%-20s %-10s %-20s\n", Queue[i].name, Queue[i].phone, Queue[i].email);
    }
}

void Search(char key[]){
    int found = -1;
    int i;
    
    for(i = front; i < rear; i++){
        if(strcmp(Queue[i].name, key) == 0){
            found = i;
        break;
        }
    }
    FILE *fp = fopen("Result.txt", "w");
    if(found == -1){
        fprintf(fp, "Name not found!\n");
    }
	else{
        fprintf(fp, "Name: %s \nPhone: %s \nEmail: %s \n", Queue[i].name, Queue[i].phone, Queue[i].email);
    }
    fclose(fp);
}

int main(){
	char key[20];
    
		readinput();
    	printList();
    	printf("Nhap ten ban muon tim: "); 
			fflush(stdin); gets(key);
    	Search(key);
    printf("Xem file output -->");
	
	return reval;
}

