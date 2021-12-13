#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100       

char *strcat(char *str1, char *str2){
    int len1, len2;
    char *result;

    len1 = strlen(str1);
    len2 = strlen(str2);

    result = (char*)malloc((len1 + len2 + 1)*sizeof(char));
    if(result == NULL){
        printf("Cap phat bo nho fail");
        return NULL;
    }
    strcpy(result, str1);
    strcpy(result + len1, str2);
    return result;
}

int main(){
    char str1[6] = "Hello";
    char str2[6] = "World";
    char *catstr;

    catstr = strcat(str1, str2);
    printf(" %s ", catstr);

return 0;
}


/*char *my_strcat(char *str1, char *str2){
    int len1, len2;

    char *result;
        len1 = strlen(str1);
        len2 = strlen(str2);
        result = (char*)malloc((len1 + len2 + 1) *  sizeof(char));
        if(result == NULL) {
            printf("Allocation failed! Check memory\n");
            return NULL;}
        strcpy(result, str1);
        strcpy(result + len1, str2);
        return result;
        }

 int main(void){
     char *cat_str;
    char str1[6] = "Hello";
    char str2[6] = "World";
     cat_str = my_strcat(str1, str2);
     if (cat_str == NULL){
         printf("Problem allocating memory!n");
         return 1;
         }
         printf("The concatenation of %s and %s is %s\n", str1, str2, cat_str);
         free(cat_str);
         return 0;
         }*/
