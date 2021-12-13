#include<stdio.h>

enum {SUCESS, FAIL};

int main(){
    FILE *fptr;
    char filename[] = "Lab1.txt";
    int reval = SUCESS;

    if((fptr = fopen(filename, "r")) == NULL){        
        printf("Cannot open file %s.", filename);
        reval = FAIL;
    }
    else{
        printf("\nThe value of fptr: 0x%d.", fptr);
        printf("\nFile is ready to close.");
        fclose(fptr);
    }
    
    return reval;
}
