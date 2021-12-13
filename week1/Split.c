#include<stdio.h>

 int split(double n, int *i, double *f){
     *i = (int)n;
     *f = n - *i;
 }
 int main(){
     double f;
     int i;
     split(3.14, &i, &f);
     printf("%d, %.2f ", i, f);
     return 0;
 }