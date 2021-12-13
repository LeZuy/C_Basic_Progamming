#include<stdio.h>
#include<stdlib.h>

enum{SUCESS, FAIL};

int main(){
    int n, i, value, sum;
    int *p;
    FILE *fp;
    int reval = SUCESS;

    printf("Nhap so phan tu: "); scanf(" %d", &n);
    p = (int*)malloc(n * sizeof(int));

    i = 0; sum = 0;
    printf("\n Nhap cac phan tu: ");
    while(i < n){
        scanf("%d", &value);
        p[i++] = value;
        sum = sum + value;
    }

    if((fp = fopen("out.txt", "w")) == NULL){
        printf("\n Cannot open file.");
        reval = FAIL;
    }
    else{ 
        fprintf(fp, " %d", i);
        for(i=n-1; i>=0; i--){
            fprintf(fp, " %d", p[i]);
        }
        fprintf(fp, " %d", sum);
    }
    fclose(fp);
    free(p);
    return reval;
}

