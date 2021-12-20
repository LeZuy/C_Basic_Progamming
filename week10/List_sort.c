#include<stdio.h>
#include<string.h>

enum{ 
	SUCESS,
	FAIL,
	MAXSIZE = 100
};

typedef struct{
	char Name[20];
	char Phone[10];
	char Email[20];
}Phonebook;


void printList(Phonebook a[], int n, int count, FILE *fp){
	for(int i=0; i<=n; i++){
		printf("\n %-20s", a[i].Name);
		fprintf(fp,"\n %-20s", a[i].Name);
		
		printf(" %-10s", a[i].Phone);
		fprintf(fp," %-10s", a[i].Phone);
		
		printf(" %-20s", a[i].Email);
		fprintf(fp," %-20s", a[i].Email);
	}
	printf("\n So lan thuc hien: %d", count);
	fprintf(fp,"\n So lan thuc hien: %d", count);
}


void swap(Phonebook *a, Phonebook*b){
	Phonebook temp;
		temp = *a;
		*a =*b;
		*b = temp;
}

void insertion_sort(Phonebook a[], int n, FILE *fp){
	Phonebook next;
	int j, count = 0;
	for(int i=1; i<=n; i++){
		next = a[i];
		for( j = i-1; j>=0 && (strcmp(next.Name, a[j].Name)<0); j--){
			a[j+1] = a[j];
			a[j] = next;
			count ++;
		}
	}
	printf("\n-------Xap xep chen-------\n");
	fprintf(fp, "\n-------Xap xep chen-------\n");
	printList(a, n, count, fp);
}


void selection_sort(Phonebook a[], int n, FILE *fp){
	int min = 0, count = 0;
	for(int i = 0; i<=n; i++){
		if(strcmp(a[i].Name, a[min].Name)<0){
			swap(&a[i], &a[min]);
			min = i;
		}
		count ++;
	}
	printf("\n-------Xap xep chon-------\n");
	fprintf(fp, "\n-------Xap xep chon-------\n");
	printList(a, n, count, fp);
}

void heapify(Phonebook a[], int n , int i){

	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	if(l<n && strcmp(a[l].Name, a[largest].Name)>0){
		largest = l;
	}
	if(r<n && strcmp(a[r].Name,a[largest].Name)>0){
		largest = r;
	}
	if(i != largest){
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}

void heap_sort(Phonebook a[], int n, FILE *fp){
	int count = 0;
	for(int i = n/2; i >=0; i-- ){
		heapify(a, n, i);
		count ++;
	}
	for(int i=n; i>=0; i--){
		swap(&a[0], &a[i]);
		heapify(a, i, 0);
		count ++;
	
	}
	printf("\n-------Xap xep vun dong-------\n");
	fprintf(fp, "\n-------Xap xep vun dong-------\n");
	printList(a, n, count, fp);
}





int main(){
	Phonebook list[MAXSIZE], buff[MAXSIZE];
	int n, irc = 0, reval = SUCESS;
	FILE *fin, *fout;
	
	printf("Nhap n:"); scanf("%d", &n);
	
	//Doan lenh de tao file input
	
/*	for(int i = 0; i<=n; i++){
		printf("\nHo ten: "); scanf(" %s", list[i].Name);
		printf("So dien thoai:"); scanf(" %s", list[i].Phone);
		printf("Email:"); scanf(" %s", list[i].Email);
	} 
	
	fin = fopen("Phonebook.txt", "w");
	
	if(fin == NULL){
		printf("\nCannot open file!");
		reval =  FAIL;
	}
	else{
	//	fprintf(fin, "%-20s %-10s %-20s", "Name", "Phone", "Email");
		for(int i = 0; i<=n; i++){
			fprintf(fin, "\n%-20s %-10s %-20s", list[i].Name, list[i].Phone, list[i].Email);
		}
		reval = SUCESS;
	}

	fclose(fin);*/
	
	
	//doc file	
	fin = fopen("Phonebook.txt", "r");
	if(fin == NULL){
		printf("\nCannot open file!");
		reval = FAIL;
	}	
	else{
		printf("%-20s %-10s %-20s", "Name", "Phone", "Email");
		for(int i=0; i<=n; i++){
		fscanf(fin, "%s %s %s", buff[i].Name, buff[i].Phone, buff[i].Email);
			printf("\n%-20s", buff[i].Name);
			printf(" %-10s", buff[i].Phone);
			printf(" %-20s", buff[i].Email);
		}
		reval = SUCESS;
	}
	
	fout = fopen("PhoneBookout.txt", "w");
	if(fout == NULL){
		printf("Cannot open file PhoneBookout.txt");
		reval = FAIL;
	}
	else{
	fprintf(fout, "%-20s %-10s %-20s", "Name", "Phone", "Email");
	for(int i=0; i<=n; i++){
	
			fprintf(fout,"\n%-20s", buff[i].Name);
			fprintf(fout," %-10s", buff[i].Phone);
			fprintf(fout," %-20s", buff[i].Email);
		}
		
//	insertion_sort(buff, n, fout);
//	selection_sort(buff, n, fout);
	heap_sort(buff, n, fout);
	reval = FAIL;
	}
	
	fclose(fin);
	fclose(fout);
	return reval;
}
	
