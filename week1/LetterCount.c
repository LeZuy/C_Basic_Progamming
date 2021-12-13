#define ALPHABET 26
#include<stdio.h>

int main(){
    int i = 0;
    int count[ALPHABET] = {0};
    char c ='\0';
        printf("Nhap xau:");
        c = getchar();
        printf("%d\n %d\n", c -'a', c-'A');
       while(c !='\n' && c >= 0){
           if (c <= 'z' && c>= 'a' ){
               ++count[c - 'a'];
           }
           if (c <= 'Z' && c >= 'A'){
               ++count[c - 'A'];
           }
           c = getchar();
       }
    for (i = 0; i < ALPHABET; ++i){
        if(count[i] > 0)
            printf("letter '%c' appears %d times. \n", 'a' + i, count[i]);
    }
       
return 0;        
}