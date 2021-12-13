#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list{
    int data;
    struct linked_list *next;
}node;

node *root, *cur;

node *Create( int value){
    node *new;
        new = (node*)malloc(sizeof(node));
        new->data = value;
        new->next = NULL;
    return new;
}

node *InsertAfterCur(node *new){
    if(root == NULL){
        root = new;
        cur = root;
    }
    else{
        new->next = cur->next;
        cur->next = new;
        cur = cur->next;
    }
    return cur;
}

void Traversal(){
    printf("\n");
    printf("%d",root->data);
    for(cur = root->next; cur != NULL; cur = cur->next){
        printf("->%d", cur->data);
    }
}

void DeleteHead(){
    node *del;
    del = root;
    root = del->next;
    free(del);
}
void FreeList(){
    node* free ;
    while(free!=NULL){
        root = root->next;
        FreeList(free);
        free = root;
    }
}

int main(){
    node *root, *A, *B, *C;
    A = Create(1); // root = A
    InsertAfterCur(A);
    B = Create(2);
    InsertAfterCur(B);
    C = Create(3);
    InsertAfterCur(C);
    Traversal();
    DeleteHead();
    Traversal();
    FreeList();
    Traversal();
    return 0;

}

