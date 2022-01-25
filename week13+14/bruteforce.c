#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 2000


int main(){
	char text[MAXSIZE], pattern[3];
	int m, n, i, j, index = 0, found[MAXSIZE];
	
	printf("Nhap xau can tim: "); gets(pattern);
	printf("\n");
	
	for(int k = 0; k < MAXSIZE; k++){
		text[k] = 97 + rand() % (102 + 1 - 97);
		if(((k)%10) == 0) printf("\n%d: ", k/10);
		printf(" %c", text[k]);
		}
		
	printf("\n");
	
	m = strlen(pattern);
	n = strlen(text);
	 
	for( i = 0; i <= n-m; i++){
		if(pattern[0] == text[i]){
			j = 0;
			while(j<=m && (text[j+i] == pattern[j])){
				j++;	
			if(j == m) {
			found[index] = i;	
			index++;
				}
			}
		}
	}
	if(index == 0) printf("\nKhong tim thay xau %s", pattern);
	
	else{
	printf("\nTim thay tai:");
		for(int k = 0 ; k < index; k++){
		printf(" %d", found[k]);
		}
	}
	return 0;		
}
		

