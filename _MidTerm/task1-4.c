#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{SUCESS,FAIL, SIZE = 10};

typedef struct {
    char name[20];
    char phone[10];
    char email[20];
}PhoneBook;


PhoneBook Queue[SIZE];

int front = 0, rear = -1;
int reval = SUCESS;

void Enqueue(int* rear, PhoneBook data){
    *rear = ( *rear + 1) % 10;
    Queue[*rear] = data;
}

void Dequeue(int *front){
    *front = ((*front) + 1) % 10;
}

int main(){
    FILE *fp ;
    PhoneBook val;
    int j;

    if((fp = fopen("PhoneBook.txt", "r")) == NULL){
        printf("Cannot open file\n");
        reval = FAIL;
    }
    int i;
    for(i = 0; i < 10; i++){
        fscanf(fp, "%s %s %s", val.name, val.phone, val.email);
        Enqueue(&rear, val);
    }
     
    printf("%-20s %-10s %-20s\n", "Name", "PhoneNum", "Email");
    
    for ( i = front; i <= rear; i++){
        printf("%-20s %-10s %-20s\n", Queue[i].name,Queue[i].phone, Queue[i].email );
    }
    
    printf("\nData dequeued: \n");
    printf("%-20s %-10s %-20s\n", Queue[front].name, Queue[front].phone, Queue[front].email);
    Dequeue(&front);
    
    printf("\n"); 
    fscanf(fp, "%s %s %s", val.name, val.phone, val.email);
    Enqueue(&rear, val);
    
    printf("%-20s %-10s %-20s\n", "Name", "PhoneNum", "Email");
    
//    i = front;
    for(i = front, j = 0; j < 10; j++){
        printf("%-20s %-10s %-20s\n", Queue[i].name, Queue[i].phone, Queue[i].email);
        i = (i + 1)%10;
    }
    fclose(fp);
    
    return reval;
}

