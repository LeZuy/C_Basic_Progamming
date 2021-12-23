#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum{ SUCESS,
		FAIL,
		MAXSIZE = 100,
};

typedef struct{
	char Name[20];
	char Phone[10];
	char Email[20];
}Phonebook;

void swap(Phonebook *a, Phonebook *b){
	Phonebook temp = *a;
	*a = *b;
	*b = temp;
}

int partition(Phonebook a[], int l, int r){
	Phonebook p = a[l];
	int i = l - 1;
	int j = r + 1;
	while(1){
		do{ 
			++i;
		}while(strcmp(a[i].Name, p.Name)<0);
		
		do{
			--j;
		}while(strcmp(a[j].Name,p.Name)>0);
		
		if(i<j){
			swap(&a[i], &a[j]);
		}
		 else return j;
	}
}

void quick_sort(Phonebook a[], int l, int r){
	if(l>=r)return;
	int p = partition(a, l, r);
	quick_sort(a, l, p);
	quick_sort(a, p+1, r );
}

int main(){
	FILE *fin, *fout;
	Phonebook list[MAXSIZE];
	int reval;
	
	fin = fopen("Phonebook.txt", "r");
	if(fin == NULL){
		printf("Cannot open input file"); 
		reval = FAIL;
	}
	else{
		printf("\n%-20s %-10s %-20s", "Name", "Phone", "Email");
		for(int i = 0; i<=9; i++){
		fscanf(fin," %s %s %s", list[i].Name, list[i].Phone, list[i].Email);
		printf("\n %-20s", list[i].Name);
		printf(" %-10s", list[i].Phone);
		printf(" %-20s", list[i].Email);
	}
	reval = SUCESS;
}
	fclose(fin);
	fout = fopen("Phonebookout.txt", "w");
	if(fout = NULL){
		printf("Cannot open output file");
		reval = FAIL;
	}
	else{
			fprintf(fout, "%-20s %-10s %-20s", "Name", "Phone", "Email");
	for(int i=0; i<=9; i++){
	
			fprintf(fout,"\n%-20s", list[i].Name);
			fprintf(fout," %-10s", list[i].Phone);
			fprintf(fout," %-20s", list[i].Email);
		reval = SUCESS;	
		}
	}
	quick_sort(list, 0, 9);
	printf("\n------------Sap xep nhanh-------------");
	for(int i =0; i<=9; i++){
		printf("\n %-20s", list[i].Name);
		fprintf(fout,"\n %-20s", list[i].Name );
		printf(" %-10s", list[i].Phone);
		fprintf(fout,"\n %-20s", list[i].Phone );
		printf(" %-20s", list[i].Email);
		fprintf(fout,"\n %-20s", list[i].Email );
	}
	
	fclose(fout);
	return reval;
}
	
	
	
	
	

	
