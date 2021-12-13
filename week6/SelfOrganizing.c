#include<stdio.h>
#include<string.h>

struct Address{
	char Name[20];
	char Email[20];
	char Number[10];	
};
 
struct Address a[100];
	int index = 0;
	
void print(){
	int i;
	printf("%-20s %-10s %-20s", "Name", "Phone", "Email");
	for( i=0; i<index; i++){
		printf("%-20s %-10s %-20s", &a[i].Name, &a[i].Number, &a[i].Email);
	}
}


int main(){

	FILE *fin = fopen("PhoneBook.txt","r");
		if (fin == NULL){
			printf("Cannot open file");
			return 0;
			}

		while(!feof(fin)){
			fscanf(fin, "%s %s %s", &a[index].Name, &a[index].Number, &a[index].Email);
				index++;
		}
	fclose(fin);

	char key[20];
		printf("Nhap ten can tim: "); fflush(stdin); gets(key);
	int i, j;
	int found = -1;
	struct Address temp;
		for (i = 0; i < index-1 && strcmp(a[i].Name, key) != 0 ; i++){
			if(strcmp(a[i].Name, key) == 0){		
			break; };
		};
		printf("Found at: %d\n", found = i);
		if (found == -1)printf("Name not found\n");
		else {
			printf("Success!\n");
			FILE *fout = fopen("result.txt", "w");
			fprintf(fout, "Found record:\n Name: %s, PhoneNumber: %s, Email: %s", a[i].Name, a[i].Number, a[i].Email);
			fclose(fout);
			if(i>0){
						 temp = a[i];
						for (j=0; j<i; j++)
						a[j+1]=a[j]; 
						}
				a[0] = temp;
		print();
		}
}
/*#include <stdio.h>
#include <string.h>

typedef struct{
    char name[30];
    char phoneNum[15];
    char emailAdd[40];
}Address;
Address addressArr[100]; int count = 0;
void printList(){
	int i;
    printf("%-30s%-15s%-40s\n", "Name", "Phone number", "Email address");
    for ( i = 0; i < count; i++){
        printf("%-30s%-15s%-40s\n", addressArr[i].name, addressArr[i].phoneNum, addressArr[i].emailAdd);
    }
}
int main(){
    // Array
    FILE *fin = fopen("AddressBook.txt", "r");
    if (fin == NULL){
        printf("Can't open file!");
        return 0;
    }
    while (!feof(fin)){
        fscanf(fin, "%s %s %s", &addressArr[count].name, &addressArr[count].phoneNum, &addressArr[count].emailAdd);
        count++;
    }
    fclose(fin);
    char key_name[30], choice = 'y';
    while (choice == 'y'){
        printf("Nhap ten can tim: "); fflush(stdin); gets(key_name);
        int found_idx = -1;
        int i, j;
        for (i = 0; i < count; i++){
            if (strcmp(key_name, addressArr[i].name) == 0){
                found_idx = i;
                break;
            }
        }
        if (found_idx == -1) printf("Name not found!\n");
        else {
            printf("Success!\n");
            FILE *fout = fopen("AddressBookResult.txt", "a");
            fprintf(fout, "Found record:\nName: %s\nPhone number: %s\nEmail address: %s\n\n", addressArr[i].name, addressArr[i].phoneNum, addressArr[i].emailAdd);
            fclose(fout);
            Address temp = addressArr[i];
            for ( j = i; j >= 1; j--){
                addressArr[j] = addressArr[j-1];
            }
            addressArr[0] = temp;
            printList();
        }
        printf("Ban co muon tiep tuc tim kiem (y/n): "); scanf("%c", &choice);
    }
}*/
