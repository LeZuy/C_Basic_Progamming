#include<stdio.h>

int binSearch(int x, int a[], int n){
	int mid, high = n+1, low=0;
	while(high>=low){
		mid = (low + high)/2;
		if(a[mid] == x) return mid;
		else if(x<mid) high = mid - 1;	
		else if(x>mid) low = mid + 1;
	}
	return -1;
}

int main(){
	int i;
	int a[] = {1, 4, 6, 7, 10, 30};
	int n = (sizeof (a)/sizeof (a[0]));
//	printf("%d", n);
	for(i=0; i<=10; i++){
	
	
	 printf("Tim thay %d tai: %d \n", i, binSearch(i, a, n));
}
	return 0; 
	
}
