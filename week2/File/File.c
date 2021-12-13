#include<stdio.h>

enum{SUCESS, FAIL, MAX_LEN = 81};

void BlockReadWrite( FILE *fin, FILE *fout){
    char buff[MAX_LEN + 1];
    int num; 

    while(!feof(fin)){
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num * sizeof(char)] = '\0';
        puts(buff);
        fwrite(buff, sizeof(char), num, fout);
    }
   //printf("\n%d\n%d", num, (num * sizeof(char)));
}

int main(){
    FILE *fin, *fout;
    char c[MAX_LEN];
    char finname[] = "lab1.txt";
    char foutname[] = "lab1a.txt";
    int reval = SUCESS;
    
   
   if((fin = fopen(finname, "r")) == NULL){
        printf("Fail to open %s file.", finname);
        reval = FAIL;
    }
    else if ((fout = fopen(foutname, "w")) == NULL){
        printf("\nFail to open %s file.", foutname);
    }
    else{
        BlockReadWrite(fin, fout);
        fclose(fin); fclose(fout);
    }
    return 0;
}