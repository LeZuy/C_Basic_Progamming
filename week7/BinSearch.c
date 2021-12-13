#include<stdio.h>

int binSearch(int x, int arr[], int size){
	int mid, high = size-1, low = 0;
	while(high >= low){
		mid = (low + high)/2;

		if(x<arr[mid]) high = mid - 1;	
		else if(x>arr[mid]) low = mid + 1;
		else return mid;
	}
	return -1;
}

int main(){
	int i;
	int arr[] = {1, 4, 6, 7, 10, 30};
	int n = (sizeof (arr)/sizeof (arr[0]));
	printf("%d", n);
	for(i=0; i<=10; i++){

	
	 printf("Tim thay %d tai: %d \n", i, binSearch(i, arr,n));
}
	return 0; 
	
}
