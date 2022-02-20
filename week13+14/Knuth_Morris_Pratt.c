#include<stdio.h>
#include<string.h>

void longestPrefixSuffix (char *p, int size, int lps[size]){
	for(int i = 0; i < size; i++){
		lps[i] = 0; // lps[] ={00000...0}
	}
	for(int i = 1; i < size; i++){
		int k = lps[i-1]; // k = lps[0] = 0
		/*  p[] 	a	b		c		a		b		c		a		b		a
			i		 	1		2		3		4		5		6		7		8	
										lps[2]									lps[7]
			k			lps[0]	lps[1]	>lps[0]	lps[3]	lps[4]	lps[5]	lps[6]	>lps[2]
			lps[] 	0	0		0		1		2		3		4		5		1
		 */
		while(k > 0 && p[k] != p[i]) // a khac b
			 k = lps[k-1]; // k = lps[-1]  = 0 ?
		if(p[k] == p[i]) lps[i] = k + 1;
		else lps[i] = 0;  // lps[1] = 0
	}
}

void KMP_search(char *p, char* t){
	int m = strlen(p);
	int n = strlen(t);
	int lps[m];
	longestPrefixSuffix(p, m, lps);
	int start = 0, k = 0; 
	while(start <= n - m){
		while(k < m && t[start + k] == p[k]) k++;
		if(k == m){
			printf("\nMau tim thay tai: %d", start);
		}
		if(k > 0){
			start += k - lps[k-1];
			k = lps[k-1];
		}else{
			start++;
		}
	}
} 

int main(){
	char pattern[] = "abcabcaba";
	char text[] = 	 "aabcabcabcababcaabcabcabc";
	KMP_search(pattern, text);
}
