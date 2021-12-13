#include<stdio.h>
#include<string.h>
#define MAXSIZE 100

void replace(char str[], char x, char y){
    int i;
    for(i = 0; str[i] != '\0'; ++i){
        if(str[i] == x){
            str[i] = y;
        }
    }
}
int main(){
    char str[MAXSIZE + 1];
    char x, y, tmp;

    printf("Nhap xau: "); scanf(" %100s", str);

    printf("\nReplace what: "); scanf(" %c", &x); //Luu y de khoang trang
    do{
        tmp = getchar();
    }while( tmp != '\n');
    
    printf("\nReplace with: "); scanf(" %c", &y);
    
    replace(str, x, y);
    printf("\n %s", str);
    return 0;
}

/* Ham truyen xau
const char *replace(char str[], char x, char y){
    int i;
    for(i = 0; str[i] != '\0'; ++i){
        if(str[i] == x){
            str[i] = y;
        }
    }
    return str;
}
int main(){
    char str[5] = "mama";
    char x, y, tmp;
    printf(" %s", str);
    printf("\n %s", replace(str, 'm', 'p'));
   
    return 0;
}*/