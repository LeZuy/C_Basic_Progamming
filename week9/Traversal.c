#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}*treetype;



int leftof(int value, treetype root){
    return value < root->data;
}
int rightof(int value, treetype root){
    return value > root->data;
}

treetype insert( int value, treetype root ){
    if(root == NULL){
        treetype node = (treetype)malloc(sizeof(treetype));
    node -> data = value;
    node -> left = NULL;
    node -> right = NULL;
        return node;
    }
    if( leftof(value, root))root -> left =  insert (value, root->left);
    else if( rightof(value, root))root -> right = insert (value, root -> right);
    return root;
}

void inorderprint(treetype root){
    if(root != NULL){
        inorderprint(root -> left);
        printf(" %d ", root->data);
        inorderprint(root->right);
    }
}

int main(){
    treetype root = NULL;
       
     root = insert(20, root);
     root = insert(30, root);
     root = insert(10, root);
printf(" %d ", root->data);
inorderprint(root);
return 0;

}