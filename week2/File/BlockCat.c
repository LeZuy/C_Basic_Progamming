#include<stdio.h>
#include<stdlib.h>
enum{SUCESS, FAIL, MAX_LEN = 81};

void BlockCat(FILE *fin){
    int num;
    char buff[MAX_LEN + 1];
    while(!feof(fin)){
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num*sizeof(char)] = '\0';
        puts(buff);
    }
}

int main( int argc, char *argv[] ){
    FILE *fptr1, *fptr2;
    char filename1[] = "lab1.txt";
    char filename2[] = "lab1a.txt";
    int reval = SUCESS;

    if(argc !=3 ){
        printf("Nhap lai ten file");
        reval = FAIL;
    }
    else if((fptr1 = fopen(argv[1],"r")) == NULL){
        printf("Fail to open file %s.", filename1);
        reval = FAIL;
    }
    else if( (fptr2 = fopen(argv[2],"r")) == NULL){
        printf("Fail to open file %s.", filename2);
        reval = FAIL;
    }
    else{
        BlockCat(fptr1);
        BlockCat(fptr2);
        fclose(fptr1); fclose(fptr2);
    }
    return 0;
}


