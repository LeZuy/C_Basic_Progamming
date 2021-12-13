#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    double width, lenght;
    if(argc != 3){
        printf("Tham so khong phu hop");
        return 1;
    }
    else{
        width = atof(argv[1]);
        lenght = atof(argv[2]);
        printf("Area: %.2f", width * lenght);
        printf("\nPerimeter: %.2f", (width + lenght)*2);
    }
   return 0; 
}

