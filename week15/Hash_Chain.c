/*-----ADT chaining hash table----*/

#include<stdio.h>
#include<stdbool.h>

#define B 13 //hash table size

typedef struct nodeTag{
	int key;
	struct nodeTag *next;
}node;
typedef node* Position;
typedef Position Dictionary[B];

Dictionary D;

void initBucket(){
	for(int b = 0; b < B; b++)
		D[b] = NULL;
}

int Search(int x){
	Position p;
	int found = 0;
	p = D[hash(x)];
	
	while((p->key==x) && (!found)){
		if(p->key==x) found++;
		else p=p->next;
	}
	return found;
}

void InsertSet(int x){
	int bucket;
	Position p;
	if(!Search(x)){	
		bucket=hash(x);
		p=D[bucket];
		
		D[bucket] = (node*)malloc(sizeof(node));
		D[bucket]->key = x;
		D[bucket]->next = p;
	}
}

void Delete(int x){
	int bucket, done;
	Position p, q;
	bucket = hash(x);
	
	if(D[bucket]!=NULL){
		if(D[bucket]->key == x){
			q=D[bucket]->next;
			free(q);
		}
	
	else{
		done = 0;
		p = D[bucket];
		while((p->next!=NULL)&&(!done))
			if(p->key==x)done = 1;
			else p=p->next;
		if(done){
			q = p->next;
			p->next = q->next;
			free(q);
			}
		}
	}
}

bool isBucketEmpty(int b){
	return (D[b] == NULL ? false:true);
}

bool isEmpty(){
	for(int b = 0; b < B; b++)
		if(D[b]!=NULL) return true;
		return false;	
}

void clearBucket(int b){
	Position p,q;
	q = NULL;
	p = D[b];
	while(p!=NULL){
		q = p;
		p = p->next;
		free(q);
	}
	D[b] = NULL;
}

void clear(){
	for(int b = 0; b < B; b++)
		clearBucket(b);
}

void duyetBucket(int b){
	Position p;
	p = D[b];
	while(p != NULL){
		printf("%d", p->key);
		p=p->next;
	}
}

void duyetTable(){
	for(int b = 0; b<B; b++){
		printf("\nBucket %d:", b);
		duyetBucket(b);
	}
}

int main(){
}
