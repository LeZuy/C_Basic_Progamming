#include<stdio.h>
#include<stdlib.h>

enum{
	SUCESS,
	FAIL
};

typedef struct{
	char number[9];
    char name[15];
    char email[25];
}PhoneBook;

int reval = SUCESS;

void SeekFile(int a, int b, FILE *fp ){
	int n = b - a + 1;
	int i, irc;
	PhoneBook *phonearr;
	if((fp = fopen("Phonebook.dat","r+b")) == NULL){
		printf("Cannot open file!");
		reval = FAIL;
	}
	phonearr = (PhoneBook*)malloc(n * sizeof(PhoneBook));
	if(phonearr == NULL){
		printf("Cap phat bo nho fail");
		reval = FAIL;
	}
	if(fseek(fp, (a-1)*sizeof(PhoneBook),SEEK_SET)!=0){
		printf("Fseek fail");
		reval = FAIL;
	}
	irc = fread(phonearr, sizeof(PhoneBook), n, fp);
	for(i=0; i<n; i++){
		printf("\n %s-", phonearr[i].name);
        printf(" %s-", phonearr[i].number );
        printf(" %s\n", phonearr[i].email);
        reval = SUCESS;
	}
	fclose(fp);
	free(phonearr);
}

int main(){
	FILE* fp;
	int a, b;
	printf("Nhap a: "); scanf("%d", &a);
	printf("Nhap b: "); scanf("%d", &b);
	SeekFile(a, b, fp);
	return reval;
}
