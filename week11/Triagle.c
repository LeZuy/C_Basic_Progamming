#include<stdio.h>


void printTrialge(int n, char ch){
	if(n<0) return;
	else{
	for(int i= 0 ; i<=n ; i++){
		printf("%c ", ch);
	}
	printf("\n");
	printTrialge(n-1, ch);
	}
}

int main(){
	int n; char ch;
	printf("Nhap n: "); scanf("%d", &n);
	printf("Nhap ky tu: ");scanf(" %c", &ch);
	printTrialge(n, ch);
	return 0;
}
