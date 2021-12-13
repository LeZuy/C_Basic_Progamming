#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {SUCESS, FAIL, MAX_ELEMENT = 100};

typedef struct{
	char name[15];
	char phone[15];
	char email[20];
}PhoneBook;

int BinarySearch(char x[], PhoneBook a[], int n){
	int low = 0, high = n-1, mid;
	while(high >= low){
		mid = (high + low)/2;
		if(strcmp(a[mid].name, x) > 0) high = mid - 1;
		else if(strcmp(a[mid].name, x) < 0) low = mid + 1;
		else return mid;
	}
		return -1;
}

int main(void){
	printf("%d\n", sizeof(PhoneBook) );
	FILE *fp, *fpout;
	PhoneBook arr[MAX_ELEMENT];
	int i, n, irc; 
	char name[15];
	int reval = SUCESS;
	
	printf("Nhap n: "); scanf("%d", &n);
	if ((fp = fopen("phonebook.dat", "rb")) == NULL){
		printf("Cannot open file\n");
		reval = FAIL;
	}
		irc = fread(arr, sizeof(PhoneBook), n, fp);

	printf("So ptu doc duoc = %d\n", irc);
	fclose(fp);
	if(irc < 0){
			printf("Cannot read from file\n");
			return -1;
	}
	for(i=0; i<n; i++){
		printf("%s", arr[i].name);
	}
	 printf( "Nhap ten: ");
	  gets(name);
	 irc = BinarySearch( name, arr, n);
	 if (irc < 0){
	 	printf("\n Name not found! \n");
	 	return -1;
	 }
	fpout = fopen("result.txt","w"); 
	if (fpout == NULL){
		printf("Cannot create result file");
		reval = FAIL;
	}
	else fprintf(fpout, "%s \n Phone: %s \n Email: %s \n ", arr[i].name, arr[i]. phone, arr[i].email);
	fclose(fpout);
	return reval;
}
