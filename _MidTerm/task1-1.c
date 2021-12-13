#include <stdio.h>
#include<stdio.h>
#include <string.h>

enum{SUCESS,FAIL, SIZE = 100};

typedef struct{
    char name[20];
    char phone[10];
    char email[20];
}PhoneBook;

PhoneBook PhoneArr[SIZE]; 
int count = 0;

int binSearch(int l, int r, char name[]){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (strcmp(PhoneArr[mid].name, name) == 0)
            return mid;
        if (strcmp(PhoneArr[mid].name, name) > 0){
            return binSearch(l, mid - 1, name);
        }
        return binSearch(mid + 1, r, name);
    }
    return -1;
}

void printList(){
	int i;
    printf("%-20s%-10s%-20s\n", "Name", "Phone", "Email");
    for ( i = 0; i < count; i++){
        printf("%-20s%-10s%-20s\n", PhoneArr[i].name, PhoneArr[i].phone, PhoneArr[i].email);
    }
}
int main(){
	int reval = SUCESS;
    FILE *fin = fopen("PhoneBook.txt", "r");
    if (fin == NULL){
        printf("Cannot open file!");
        reval = FAIL;
    }
    while (!feof(fin)){
        fscanf(fin, "%s %s %s", &PhoneArr[count].name, &PhoneArr[count].phone, &PhoneArr[count].email);
        count++;
    }
    fclose(fin);

    char key_name[20], choice = 'y';
    int found = -1, i;
   	
   	while(choice == 'y'){
        printf("Nhap ten can tim: "); fflush(stdin); gets(key_name);
        found =  binSearch(0, 9, key_name);
        FILE *fout = fopen("PhoneBookout.txt", "a");
        if (found == -1) printf("Name not found!\n");
        else {
            printf("Success!\n");
            fprintf(fout, "Found record:\nName: %s\nPhone: %s\nEmail: %s\n\n", PhoneArr[found].name, PhoneArr[found].phone, PhoneArr[found].email);
            fclose(fout);
        PhoneBook temp = PhoneArr[found];
        for( i = found ; i >= 1; i--){
            PhoneArr[i] = PhoneArr[i-1];
            }
            PhoneArr[0] = temp;
            printList();
        }
        printf("Ban co muon tiep tuc tim kiem (y/n): "); scanf("%c", &choice);
    }
    return reval;
}
