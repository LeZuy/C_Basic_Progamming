#include<stdio.h>
#include<string.h>
#define MAX_CHAR 256

void badCharHeuristic(char *s, int size, int r[MAX_CHAR]){
	for(int i = 0; i < MAX_CHAR; i++){
		r[i] = -1;
	}
	printf("\n");
	for(int i = 0; i < size  ; i++){
//		printf(" %d", (int)s[i]);
		r[(int)s[i]] = i;
//		printf(" r[%d] = %d", (int)s[i], i);
	}
/*	for(int i = 0; i < MAX_CHAR; i++){
		 printf(" %d", r[i]);
	}*/
}

void badCharSearch(char *text, char *pattern){
	int m = strlen(pattern);
	int n = strlen(text);
	int r[MAX_CHAR];
	badCharHeuristic(pattern, m, r);
	int shift = 0;
	while(shift <= (n-m)){
		int j = m - 1;
		while(j >= 0 && pattern[j] == text[shift + j]) j--;
		if(j < 0){
			printf("\nMau xuat hien tai %d", shift);
			shift += (shift + m<n) ? m - r[text[shift + m]] : 1;
		//	printf("; r[text[shift + m]]: %d ", r[text[shift + m]]);
		}
		else{
			shift += (j - r[text[shift + j]] > 1) ? j - r[text[shift + j ]] : 1; 
		}
	}
}
int main(){
	char text[] = "AGCAATC4CTGA4GTT4G";
	//char pattern[] = "GAGTTG";
	char pattern[] = "4";
	badCharSearch(text, pattern);
	return 0;
}
