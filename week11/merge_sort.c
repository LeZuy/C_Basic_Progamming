#include<stdio.h>
#define MAXSIZE 1000


void merge(int A[], int first, int mid, int last){
	int tempA[MAXSIZE]; //mang phu
	
	int first1 = first; int last1 = mid; //mang 1						
	int first2 = mid + 1; int last2 = last;		//mang 2		
	int index = first1; 
	
	for(;(first1 <= last1) && (first2 <= last2); index++){
		if(A[first1]<A[first2]){
		tempA[index] = A[first1];
		first1++;
	}
		else{
			tempA[index] = A[first2];
			first2++;
		}
	}
	for(; first1 <= last1; first1++, index++){
		tempA[index] = A[first1];
	}
	for(; first2 <= last2; first2++, index++){
		tempA[index] = A[first2];
	}
	for(index = first; index <= last; index++){
		A[index] = tempA[index];
	}
}


void merge_sort(int a[], int l, int r){
	if(l<r){
		int m = (l+r)/2;
		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main(){
		int a[6] = {5, 10, 32, 89, -4, 22};
		merge_sort(a, 0, 6);
		printf("\n-------Xap sep tron-------\n");
		for(int i=0; i<=6; i++){
			printf(" %d", a[i]);
		}
}
