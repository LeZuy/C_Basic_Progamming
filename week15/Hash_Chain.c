#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 26 //hash table size
#define max 50
#define numstr 21

typedef char elementType;

typedef struct linkedlist{
	elementType data[max];
	struct linkedlist *next;
}nodeType;

nodeType* bucket[M];

int hash(elementType key[]){
	return key[0] % 65;
}

void CreateBucket(){
	int b;
	for(b = 0; b < M; b++)
		bucket[b] = NULL;
}

nodeType *CreateNode(elementType key[]){
	nodeType *newnode = (nodeType*)malloc(sizeof(nodeType));
	 strcpy(newnode->data, key);
   	 newnode->next = NULL;
	return newnode;
}

void InsHead(elementType key[], nodeType *head){
	nodeType *newnode = CreateNode(key);
	int value = hash(key);
		newnode->next = bucket[value];
		bucket[value] = newnode;	
}

void InsAf(nodeType *prev, elementType key[]){
	if(prev == NULL)
		printf("Nut truoc co gia tri NULL");
	else{
		nodeType *newnode = CreateNode(key);
		newnode->next = prev->next;
		prev->next = newnode;
	}
}

void place(nodeType *head, elementType key[]){

	nodeType *prev = NULL, *cur ;
	for(cur = head; cur!=NULL && strcmp(key, cur->data)>0; cur = cur->next)
            prev = cur;
     
      if (prev == NULL)//them nut vao dau Buket
            InsHead(key,head);
      else
            InsAf(prev, key);	
}

int search(elementType key[]){
	nodeType *cur;
	int p = 0, value = hash(key);
	
	cur = bucket[value];
	while(strcmp(key,cur->data)!=0){
		cur = cur->next;
		p++;
	}
	return p;
}

nodeType *DelHead(nodeType *head){
	if(head == NULL)return NULL;
	else{
	nodeType *temp;
		temp = head->next;
		free(head);
	return temp;
	}
}

elementType DelAf(nodeType *prev){
	nodeType *temp;
	elementType key[max];
	
	temp = prev->next;
	strcpy(key,  temp->data);
	prev->next = prev->next->next;
	free(temp);	
	
	return *key;
}

elementType DelKey(elementType key[]){
	nodeType *cur, *prev = NULL;
	int value = hash(key);
	elementType delKey[max];
	
	cur = bucket[value];
//	prev = cur;
	while(cur!=NULL && strcmp(key, cur->data) != 0){
		prev = cur;
		cur = cur->next;
	}
	if(cur == NULL)
		printf("\nKhong co nut de xoa");
	else{
	if(cur == bucket[value])
		bucket[value] = DelHead(bucket[value]);
	else		
		 DelAf(prev);
	}
	
}

void freeBucket(nodeType *head){
	nodeType *cur = NULL, *prev = head;
	while(prev!=NULL){
		cur = prev->next;
		free(prev);
		prev = cur;
	}
}

void freeTable(){
	for(int b = 0; b < M; b++)
		freeBucket(bucket[b]);
}

int main(){
	int bam;
	
	printf("\n---------Hash Table Chainning---------\n");
	
	CreateBucket();
	
	char s[numstr][max]  = {{"Archer"}, {"Lancer"},{"Rider"},
							{"Caster"},{"HolyGrail"}, {"Ruler"}, {"Saber"},
							{"Berseker"},{"Beast"}, {"Foreinger"}, {"AlterEgo"},
							{"Shielder"}, {"MoonCancer"}, {"Avenger"}, {"Mage"},
						    {"Priest"}, {"Homunculus"}, {"Orleans"}, {"Einzbern"}, 
							{"NoblePhantasm"},{"UnlimitedBladesWorks"}};
	char s2[] = {"Assassin"};
	
	place(bucket[hash(s2)],s2);
	
	for(int i = 0 ; i < numstr; i++){
		bam = hash(s[i]);
		 place(bucket[bam],s[i]);
	}
	DelKey(s[13]);
	printf("\n Da xoa xau %s", s[13]);
	
	for(int i = 0; i < M; i++){
		nodeType *cur = bucket[i];
		printf("\n%5c: ", i+65);
		
		while(cur != NULL){
			printf( " %s", cur->data);
			if(cur->next != NULL)printf(",");
			cur = cur->next;
		}
	}
	int kq = search(s2);
	if(kq == -1)
		printf("\nNo such key");
	else printf("\n %s co tai bucket %c, vi tri %d", s[0] , hash(s[0])+65 , kq);
	freeTable();	
	
		
	return 0;
}

