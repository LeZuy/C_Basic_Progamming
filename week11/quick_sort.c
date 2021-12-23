#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int l, int r){
	int p = a[l];
	int i = l - 1;
	int j = r + 1;
	while(1){
		do{ 
			++i;
		}while(a[i]<p);
		
		do{
			--j;
		}while(a[j]>p);
		
		if(i<j){
			swap(&a[i], &a[j]);
		}
		 else return j;
	}
}

void quick_sort(int a[], int l, int r){
	int p;
	if(l>=r)return;
	p = partition(a, l, r);
	quick_sort(a, l, p);
	quick_sort(a, p+1, r); 
}

int main(){
	int a[6] = {5, 10, 32, 89, -4, 22};
	
	quick_sort(a, 0, 5);
	printf("--------Xap xep nhanh-------\n");
	for(int i =0; i <=5; i++){
		printf(" %d", a[i]);
	}
	return 0;
}
