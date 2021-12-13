#include<stdio.h>

int binSearch(int x, int a[], int low, int high){
	int mid;
	if(low>high) return -1;
//	if(low==high) return high;
//	else{
	if(high>=low){
	
	mid = (low + high )/2; 
		if( a[mid] < x )
				return binSearch(x, a, mid + 1, high );
		else if(a[mid] > x)
				return binSearch(x, a, low, mid - 1);
//			else if(a[mid] == x) return mid;
		else if(a[mid] == x) return mid;
	}
	return -1;
}

int main(){
	int i;
	int a[] = {1,2,4,7,8,9,10};
	int n =  sizeof(a)/sizeof(a[0]);
//	printf("%d", n);

	
	
		printf("Tim thay tai: %d \n", binSearch(10, a, 0, n-1));

	return 0; 
	
}


