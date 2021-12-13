#include<stdio.h>
#include<string.h>
#define MAXSIZE 20000000

void replace(char *str, char x, char y){
    if(str== NULL) return ;
    while(*str != '\0'){
            if(*str == x)
            *str = y;
            ++str;
        
    }
}

int main(){
    
    char str[5] = "mama";

    replace(str, 'm', 'p');
    printf( " \n%s", str);
    return 0;
}