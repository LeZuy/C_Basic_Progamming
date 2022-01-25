#include<stdio.h>
#include<stdlib.h>

enum{SUCESS, FAIL};

int main(){
	FILE *fp;
	char data[10], sort[10];
	char c;
	int i;
	
	fflush(stdin);
	fp = fopen("Sort.txt", "r");

	while((c = fgetc(fp))!=EOF){
		 data[i] = c;
		i++;
	}
	for(i = 0 ; i<10; i++){
		next = data[i];
		for(int j = i-1; j)
	}
		
	return 0;
}
