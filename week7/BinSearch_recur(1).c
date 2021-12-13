#include<stdio.h>

int count;

int binSearch(int x, int a[], int low, int high){
	int mid, i;
	
//	for(i=low; i<=high; i++) printf("%d ", a[i]);
	count++; 
		
	if(low>high) return -1;
	
	else{
	if(high>=low){
		mid = (low + high )/2; 
		
			if( a[mid] < x )
				return binSearch(x, a, mid + 1, high );
		
			else if(a[mid] > x)
				return binSearch(x, a, low, mid - 1);
	
			else if(a[mid] == x) return mid;
		}
	
	}
	
	return -1;
	
}

int main(){
	int a[100], n, i;
	
	for(i = 0; i <= 100; i++){
		a[i] = i;
	//	printf("%d\n", a[i]);
}
	printf("Nhap n:"); scanf("%d", &n);
	printf("\nTim thay tai %d", binSearch(n, a, 0, 99));
	printf("\nGoi ham %d lan ", count);
	return 0;
}
