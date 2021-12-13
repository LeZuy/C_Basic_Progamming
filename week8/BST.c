#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct node{
    int data;
    struct node *left; 
    struct node *right;
} * treetype;

treetype Search(int value, treetype root){
    if(root == NULL) return NULL;
    else if(root->data == value) return root;
    else if(root->data < value) return Search(value, root->left);
    else return Search(value, root->right);
    
}

void insert(int value, treetype root){
    if(root == NULL){
        root =  (treetype)malloc(sizeof(struct node));
        root -> data = value;
        root -> left = NULL;
        root -> right = NULL;
    }
    else if(value < root->data) insert(value, root->left);
    else if(value > root->data) insert(value, root->right);    
}
int DeleteMin(treetype root ){
    int k;
    if(root->left == NULL){
        k = root->data;
        root = root->right;
        return k;
    }
    else return DeleteMin(root->left);
}
void DeleteNode(int x, treetype root){
    if(root != NULL){
        if(x < root->data)DeleteNode(x, root->left);
        else if(x > root->data)DeleteNode(x, root->right);
        else if((root -> left == NULL) && (root -> right == NULL)) root = NULL;
        else if(root -> left == NULL) root = root -> right;
        else if(root -> right == NULL) root = root -> left;
        else root -> data = DeleteMin(root -> right);
    } 
}
void prettyprint(treetype tree, char *prefix){
    char *prefixend = prefix + strlen(prefix);
if(tree != NULL){
    printf("%04d", tree->data);
    if((tree -> left == NULL) && (tree-> right == NULL)){
        printf("\304"); strcat(prefix, "  ");
    }
    else{
        printf("\302"); strcat(prefix, "\263  ");
    }
    prettyprint(tree->left, prefix);
    *prefixend = '\0';
    if((tree->left == NULL)&&(tree->right == NULL)){
        printf("\n%s", prefix); printf("\300");
    }else printf("\304");
    strcat(prefix,"  ");
    prettyprint(tree->right, prefix);
    }
}
int main(){
    treetype p, tree = NULL;
    char *prefix;
    int i, n = 0;
    
    srand(time(NULL));
    for ( i = 0; i < 10; i++ ) 
        insert (rand() % 100, tree );
     printf("pretty print:\n");
        strcpy(prefix,"    ");
        prettyprint(tree, prefix);
        printf("\n");
    do {
        printf("Enter key to search (-1 to quit):");scanf("%d", &n);
        p= Search(n, tree);
            if (p!=NULL) printf("Key %d found on the tree",n);
            else insert(n, tree);
            } while (n!=-1);
return 0;
}
