#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define max 50
#define table_size 100

typedef struct node{
 	char string[max]; 
 	
}nodeType;

nodeType table[table_size]; 
int avail;

int hash(char key[]){
	return key[0] % 65;
}

void CreateTable(){
	for(int i = 0; i < table_size; i++)
		table[i].string[0] = '\0';
	avail = table_size - 1;
}

int isEmpty(){
	for(int i = 0 ; i < table_size; i++)
		if(table[i].string[0]!= '\0')
			return false;
	return true;
}

int getEmpty(){
	while(strcmp(table[avail].string, "\0") != 0)
		avail--;
	return avail;	
}

int search(char key[]){
	int i = hash(key);
	while(strcmp(key, table[i].string) !=0 && i != -1)
		i++;
	if(strcmp(key, table[i].string) == 0)return i;
	else return table_size;
}

int insert(char key[]){
	int i, j;
	i = search(key);
	if(i != table_size){
		printf("\nKhoa bi trung");
		return i;
	}
	i = hash(key);
	while(strcmp(table[i].string, "\0") != 0)
		i++;
	if(strcmp(table[i].string, "\0") == 0)
		j = i;
	else{
		j = getEmpty();
		if(j == -1)
			printf("\n Bang bam da day");
		else{
			for(int k = i; k > i-j; k--)
				table[i-1] = table[i]; 
			j = i ;
		}
	strcpy(table[j].string, key);	
	}
}

int main(){
	insert("Archer");
	
	for(int i = 0; i < table_size; i++){
		printf("%s", table[i].string);
	}
}
