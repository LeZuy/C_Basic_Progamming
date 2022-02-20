#include<stdio.h>
#include<string.h>
#define MAX_CHAR 10
#define TABLE_SIZE 13

typedef struct{
	char key[MAX_CHAR];
}element;

element hash_table[TABLE_SIZE];

void init_table(element ht[]){
	int i;
	for(i = 0; i<TABLE_SIZE; i++)
		ht[i].key[0] = '\0';
}

int transform(char *key){
	int number = 0;
	while(*key) number += *key++;
	return number;
}

int hash(char *key){
	return (transform(key)%TABLE_SIZE);
}
int main(){
	char s1[] = "Caster";
	char s2[] = "Ruler";
	char s3[] = "Saber";		
	char s4[] = "Berseker";
	char s5[] = "Beast";
	char s6[] = "Assassin";
	
	
	printf(" %d", hash(s1));
	printf(" %d", hash(s2));
	printf(" %d", hash(s3)); //s1 và s3 dung do, cung gia tri bam la 12
	printf(" %d", hash(s4));
	printf(" %d", hash(s5));
	printf(" %d", hash(s6));
	printf ("\n");
	
	init_table(hash_table);
	
		strcpy( hash_table[hash(s1)].key, s1); 
		strcpy( hash_table[hash(s2)].key, s2); 
		strcpy( hash_table[hash(s3)].key, s3); 
		strcpy( hash_table[hash(s4)].key, s4); 
		strcpy( hash_table[hash(s5)].key, s5); 
		strcpy( hash_table[hash(s6)].key, s6); 
		
	printf("\n---------Bang bam----------\n")	;
	for(int i= 0; i<TABLE_SIZE; i++)
		printf(" %d: %s \n", i, hash_table[i].key);
	
	return 0;
}
