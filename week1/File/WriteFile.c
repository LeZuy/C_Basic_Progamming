#include<stdio.h>
#include<ctype.h>
#include<string.h>


enum {SUCESS, FAIL, MAXLEN = 81};

void CharReadWrite(FILE *fin, FILE *fout){
    int c ;
    while ((c = fgetc(fin)) != '\n'){
        if (islower(c)) c = toupper(c);
        else if (isupper(c)) c = tolower(c);
        fputc(c, fout); //write to file
        putchar(c); //display character
    }
}
void LineReadWrite(FILE *fin, FILE *fout){
    int len, n = 1;
    char c[MAXLEN];
    while(fgets (c, MAXLEN, fin) != NULL){
        len = strlen(c);
        fprintf(fout, " %d %s", n, c);
        printf("%s", c);
        n++;
    }
}

int main(){
    FILE *fin, *fout;
    char finname[] = "Lab1.txt";
    char foutname[] = "Lab1w.txt";
    int reval = SUCESS;

    if((fout = fopen(foutname, "w"))  == NULL){
        printf ("Fail to open file %s", finname);
        reval = FAIL;
    }
    else if((fin = fopen(finname, "r")) == NULL){
        printf("Fail to open file %s", foutname);
        reval = FAIL;
    }    
    else{
    //   CharReadWrite(fin, fout);
        LineReadWrite(fin, fout);
        fclose(fin);
        fclose(fout);
    }
    return reval;
}