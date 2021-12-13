#include<stdio.h>
#define MAXSIZE 200000

int ArrayEqual(int a[], int b[], int n){
    int i;
    for(i=0; i<n; i++){
        if( a[i] != b[i])return 0;
    }
    return 1;
}
int main(){
    int n, i, a[MAXSIZE], b[MAXSIZE];
    printf("Nhap n: "); scanf("%d", &n);
    for( i=0; i<n; i++){
        printf("\na[%d] = ", i); scanf("%d", &a[i]);
    }
    for( i=0; i<n; i++){
        printf("\nb[%d] = "); scanf("%d", &b[i]);
    }
    if(ArrayEqual(a, b, n) == 1)printf("\n2 mang giong nhau");
    
    else printf("\n2 mang khac nhau");
}