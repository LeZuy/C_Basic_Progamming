#include<stdio.h>

void insertion_sort(int a[], int n){
    int i, j, next;
    for(i=1; i<n; i++){
        next = a[i];
        for(j=i-1; j>=0 && a[j]>next; j--){
            a[j+1] = a[j];
            a[j] = next;
        }
    }
    printf("\n-------Xap xep chen-------\n");
    for(i=0; i<n; i++){
        printf(" %d", a[i]); 
    }
}

void selection_sort(int a[], int n){
    int i, j, min, temp;

    for(i=0; i<=n; i++){
        min = i;
        for(j=i+1; j<=n-1; j++){
            if(a[j] < a[min]) min = j;
        }
     temp = a[i];
    a[i] = a[min];
    a[min] = temp;
    }
    printf("\n-------Xap xep lua chon-------\n");
    for(i=0; i<n; i++){
        printf(" %d", a[i]);
    }
}

 void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }


void heapify(int a[], int n, int i){
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;
	
	if(l<n && a[l]>a[largest]){
		largest = l;
	}
	if(r<n && a[r]>a[largest]){
		largest = r;
	}
	if(largest != i){
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
	
}

void heap_sort(int a[], int n){
	int temp;
	for( int i = n/2-1; i>=0; i--){
		heapify(a, n, i);
	}
	for( int i = n-1; i>=0; i--){
		swap(&a[0], &a[i]);
		heapify(a, i, 0);
	}
	printf("\n-------Xap xep vun dong-------\n");
    for(int i=0; i<n; i++){
        printf(" %d", a[i]);
	}
}



int main(){
    int a[9] = {16,23,4,10,76,8,90,46,30};
    int i, n;

    for(i=0; i<9; ++i){
    	printf(" %d", a[i]);
	}
 //   insertion_sort(a, 9);
//    selection_sort(a, 9);
    heap_sort(a, 9);
    
return 0;
}

 


