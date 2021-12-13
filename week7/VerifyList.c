#include<stdio.h>
#define MAXSIZE 1000

enum{TRUE, FALSE
};
typedef struct{
	int key;
}element;

element list[MAXSIZE];

int BinarySearch(int x, element list[], int size){
	int left = 0, right = size - 1, mid;
		while(left <= right){
			mid = (left + right)/2;
			if(list[mid].key > x) right = mid - 1;
			else if(list[mid].key < x)left = mid + 1;
			else return mid;
		}
	return -1;
}

int Verify(element list1[], element list2[], int n, int m){
	int i, j, marked[MAXSIZE];
	for(i = 0; i < m; i++){
		marked[i] = FALSE;
		}
	for(i = 0; i < n; i++){
		if(j = seqsearch(list2, n, list1[i].key )<0) 
			printf("\n%d not found in list 2", list[1].key);
		else marked[j] = TRUE;	
		}	
	for(i = 0; i < m; i++)
		if(!marked[i]) printf("\n%d not found in list 1", list2[i].key);	
		
}
int seqsearch(element arr[], int size, int k){
	int i = 0;
	while (arr[i].key != k)i++;
	return i-1;
}

int main(){
	element list1[MAXSIZE] = {1,2,3,4,5,6,7,8,9,10};
	element list2[MAXSIZE] = {1,2,3,4,5,6,7,8,10};
	Verify(list1, list2, 10, 9);
	
}


