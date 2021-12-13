#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

enum{SUCESS, FAIL};

 struct PhoneBook {
    char number[9];
    char name[15];
    char email[25];
};

int main(){
    struct PhoneBook list[MAXSIZE];
    FILE *fp;
    int n, i, irc, reval = SUCESS;

    printf("Nhap n: "); scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("\nHo ten: "); scanf(" %s", list[i].name);
        printf("\nSo dien thoai: "); scanf(" %s", list[i].number);
        printf("\nEmail: "); scanf(" %s", list[i].email);
    }

    //write to file
    if ((fp = fopen("Phonebook.dat", "w+b")) == NULL){
        printf("Cannot open file Phonebook.dat.");
        reval = FAIL;
    }
    else{
         irc = fwrite(list, sizeof(struct PhoneBook), n, fp);
        reval = SUCESS;
        printf("fwrite return code: %d", irc);
    }
    fclose(fp);

    //read form file
    if((fp = fopen("Phonebook.dat","rb")) == NULL ){
        printf("Cannot open file Phonebook.dat.");
        reval = FAIL;
    }
    else{
        irc = fread(list, sizeof(struct PhoneBook), n, fp);
        printf("\nfread return code %d", irc);
        reval = SUCESS;
    }
    for(i=0; i<n; i++){
        printf("\n %s-", list[i].name);
        printf(" %s-", list[i].number );
        printf(" %s\n", list[i].email);
    }
    fclose(fp);
    return reval;
} 