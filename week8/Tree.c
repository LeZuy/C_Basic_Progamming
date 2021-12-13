#include<stdio.h>
#include<stdlib.h>


typedef struct nodetype {
	int data;
	struct nodetype *left, *right;
}node_type;

typedef struct nodetype *treetype;



void MakeNullTree(treetype T){
	T = NULL;
}

int EmptyTree(treetype T){
	return T == NULL;
}

treetype LeftChild(treetype root){
	if(root != NULL) return root->left;
	else return NULL;
}

treetype RightChild(treetype root){
	if(root != NULL) return root->right;
	else return NULL;
}

treetype CreateNode(int value){
	treetype new;
	new = (node_type*)malloc(sizeof (node_type));
	if(new != NULL){
		new->left = NULL;
		new->right = NULL;
		new->data = value;
	}
	return new;
}

int isLeaf(treetype node){
	if(node!=NULL) 
		return (node->left == NULL) && (node->right == NULL);
	else return -1;	
}

int nb_nodes(treetype root){
	if (root == NULL) return 0;
	else return 1 + nb_nodes(root->right) + nb_nodes(root->left);
}
int nb_rights(treetype root){
	if(root->right == NULL)return 0;
	else return 1 + nb_rights(root->right);
}
int nb_lefts(treetype root){
	if(root->left == NULL)return 0;
	else return 1 + nb_lefts(root->left);
}
int nb_leaves(treetype root){
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
	else return (nb_leaves(root->left) + nb_leaves(root->right));
}
int nb_internals(treetype root){
	if(EmptyTree(root) )return 0;
	else return (nb_nodes(root) - nb_leaves(root) - nb_lefts(root) - nb_rights(root) + 2);
}


 treetype createfrom2( int value, treetype l, treetype r){
	treetype N;
		N = (node_type*)malloc(sizeof (node_type));
	N->data = value;
	N->left = l;
	N->right = r;
		return N;
}

treetype AddLeft(treetype T, int value){
	treetype newnode = CreateNode(value);

	if(newnode == NULL) return newnode;
	if(T == NULL){
		 T = newnode;
	}
	else{
		node_type *Lnode = T;
		while(Lnode->left != NULL ) Lnode = Lnode->left;
		Lnode->left = newnode;
	}
	return newnode;
}
treetype AddRight(treetype T, int value){
	treetype newnode = CreateNode(value);

	if(newnode == NULL) return newnode;
	if(T == NULL){
		 T = newnode;
	}
	else{
		node_type *Rnode = T;
		while(Rnode->right != NULL ) Rnode = Rnode->right;
		Rnode->right = newnode;
	}
	return newnode;
}

int TreeHeight(treetype root){

	int lHeight, rHeight;

	if(EmptyTree(root))return 0;
	else{
		lHeight = TreeHeight(root -> left);
		rHeight = TreeHeight(root -> right);
	if( rHeight > lHeight )return rHeight + 1;
	else return lHeight + 1;
	}
}

int main(){
	treetype root, n1, n2, n3;
	root = CreateNode(0);
	n1 = CreateNode(10);
	n2 = CreateNode(11);
	n3 = CreateNode(12);
		root->left = n1;  
		n1->left = n2;
		n1->right = n3;
		/*		 root
			  	/
			   n1
			  /  \
			n2    n3
		*/
		printf(" %d %d %d %d",isLeaf(root), isLeaf(n1), isLeaf(n2), isLeaf(n3));
		printf("\nNumber of nodes: %d ", nb_nodes(root) );
		printf("\n Height of tree: %d ", TreeHeight(root));
		printf("\n right:%d left:%d leaves: %d inner: %d", nb_rights(root), nb_lefts(root), nb_leaves(root), nb_internals(root));
MakeNullTree(n1);
MakeNullTree(root);
return 0;	
}