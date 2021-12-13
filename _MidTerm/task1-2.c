#include <stdio.h>
#include<stdlib.h>
#include <string.h>

enum{SUCESS,FAIL, SIZE = 100};

typedef struct{
    char name[20];
    char phone[10];
    char email[20];
}PhoneBook;

typedef struct LinkedList {
    PhoneBook data;
    struct LinkedList *next;
}node;

typedef node *nodep;

node *head= NULL;

node *Create( PhoneBook value){
    node *new;
        new = (node*)malloc(sizeof(node));
        new->data = value;
        new->next = NULL;
    return new;
}

void Insert(node** root, PhoneBook data){
    node *new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = *root;
    *root = new;
    }


void Traversal(){
    node *cur;
    printf("%-20s%-10s%-20s", "Name", "Phone", "Email");
    for ( cur = head; cur != NULL; cur = cur->next){
        printf("\n%-20s%-10s%-20s%", &cur->data.name, &cur->data.phone, &cur->data.email);
    }
}

void DelNode(node** del,node** root){
    if (*del == *root){
        *root = (*root)->next;
        free(*root);
    }else{
        node** cur;
        for (cur = root; (*cur)->next != *del; cur = &((*cur)->next));

        (*cur)->next = (*cur)->next->next;
        free(*del);   
    }
}

node *Search(char key_name[]){
    node *found = NULL;
    node *cur;
    for ( cur = head ; cur != NULL; cur = cur->next){
        if (strcmp(cur->data.name, key_name) == 0){
            found = cur;
            return found;
        }
    }
}
void OutputFile(node *found){   
    FILE *fp = fopen("PhoneBookout.txt", "w");
    if (found == NULL){
        fprintf(fp, "Name not found!\n");
    }else{
        fprintf(fp, "Name: %s\nPhone: %s\nEmail: %s\n", found->data.name, found->data.phone, found->data.email);
        if (found != head){
            PhoneBook temp = found->data;
            DelNode(&found,&head);
            Insert(&head, temp);
        }
    }
    fclose(fp);
    }
int main(){
    FILE *fp;
    PhoneBook data;
    int i, n=10;
    char key_name[20];
    if((fp= fopen("PhoneBook.txt", "r")) == NULL){
        printf("Cannot open file");
    }
    else{
        for(i=0; i<n; i++){
            fscanf(fp, "%-20s %-10s %-20s", data.name, data.phone, data.email);
            Insert(&head, data);
        }
        fclose(fp);
    }
    printf("Nhap ten ban muon tim: ");
    fflush(stdin); gets(key_name);
    Search(key_name);
    Traversal();
}