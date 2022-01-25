#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 100000


void insertion_sort(int a[],int l, int n){
    int i, j, next;
    for(i=l; i<=n; i++){
        next = a[i];
        for(j=i-1; j>=l && a[j]>next; j--){
            a[j+1] = a[j];
            a[j] = next;
        }
    }
}


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int l, int r){
	int p = a[r];
	int i, j = l - 1;
	
	for( i = l; i<=r-1 ; i++){
		if(a[i]<=p){
			j++;
			swap(&a[j], &a[i]);
		}
	}
	swap(&a[j+1],&a[r]);
	return (j+1); 
}

void quick_sort(int a[], int l, int r){
	int p;
	if(l>=r)return;
	p = partition(a, l, r);
	quick_sort(a, l, p-1);
	quick_sort(a, p+1, r); 
}

void hybird_sort(int a[], int l, int r){
	while(l<r){
		if(r - l  < 10){
			insertion_sort(a, l, r);
			break;
		}
		else{
			int p = partition(a, l ,r);
			if((p - l )< (r - p)){
				hybird_sort(a, l, p-1 );
				l = p + 1;
			}
			else{
				hybird_sort(a, p + 1, r);
				r = p - 1;
			}
		}
	}
}

void printList(int a[], int n){
    for(int i=0; i<=n; i++){
        printf(" %d", a[i]); 
    }
    printf("\n");
}


int main(){
	int n, a[MAXSIZE], a1[MAXSIZE]; //  a[] for quick, a1[] for insert
	printf("Nhap n: "); scanf(" %d", &n);
	
	srand((int)time(0));
	for(int i = 0; i<=n; i++){
		a[i] = rand()%500 ;
		a1[i] = a[i];
		printf(" %d", a[i]);
	}
	
	printf("\n\n");
	
	clock_t start1 = clock() ;
		quick_sort(a, 0, n);
	clock_t end1 = clock();
	
	clock_t start2 = clock();
		hybird_sort(a1, 0 , n);
	clock_t end2 = clock();
	
	printList(a, n);
	printf(" \n");
	printList(a1, n);
	
	double timespent1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("\n-Quick sort: %lfs", timespent1);
	double timespent2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	printf("\n-Quick & Insert: %lfs", timespent2);
	
	return 0;
}



