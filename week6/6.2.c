#include<stdio.h>


int LinearSentinelSearch(int a[], int n , int k ){
	int i = 0; a[n]= k;
	while(a[i]!=k){
		i++;
	}
	return i-1;
}

int main(){
	int i, n, a[100], k;
	printf("Nhap n: "); scanf("%d", &n);
	for(i=0; i<=n; i++){
		scanf("%d", &a[i]);
	}
	printf("Can tim: "); scanf("%d", &a[n+1]);
 k=	a[n+1] ;
	printf ("Vi tri can tim %d", LinearSentinelSearch(a, n, k ));
return 0;

	
}
