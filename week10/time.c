#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10000

void swap( int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int a[], int n){
	int min;
	for(int i=0; i<=n; i++){
		min = i;
		for(int j=i+1; j<=n-1; j++){
			if(a[j]<a[min]){
				min = j;
				}
			swap(&a[i], &a[min]);
		}
	}
}

void heapify(int a[], int n, int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<=n && a[l]<a[largest]) largest = l;
	if(r<=n && a[r]<a[largest]) largest = r;
	if(largest!=i){
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}
void heap_sort(int a[], int n){
	for(int i = n/2-1; i>=0; i--){
		heapify(a, n, i);
	}
	for(int i = n-1; i>=0; i--){
		swap(&a[0], &a[i]);
		heapify(a, i, 0);
	}
}

int main(){

	int a[SIZE];
	time_t t1, t2;
	
	
	srand(time(NULL));
	for(int i=0; i<SIZE; i++){
		a[i] = rand();
		printf(" %d", a[i]);
	}
	time(&t1);
	selection_sort(a,SIZE);
	time(&t2);
	
	printf("\n\nsorted array: ");
	for(int i=0; i<SIZE; i++){
		printf(" %d", a[i]);
	}
	
	 double durationinseconds = (double) t2-t1;
	printf("\n time taken: %fs",durationinseconds);
	return 0;
}
