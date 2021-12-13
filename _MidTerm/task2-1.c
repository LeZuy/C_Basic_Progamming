#include<stdio.h>       
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

enum{ 
	SIZE = 100
}; 

char stack[SIZE];
int top = -1;

bool isEmpty(int top){
    if (top < 0) return true;
    else return false;
    }

void push(char item){
	if(top >= SIZE-1){
		printf("\nStack Overflow.");
	}
	else{
		top = top+1;
		stack[top] = item;
 }
}

char pop(){
	char val ;
	if(isEmpty(top)){
		printf("\nStack empty!");
	}
	else{
		val = stack[top];
		top = top-1;
	return val;
	}
}

bool isOp(char val){
	if(val == '*' || val == '/' ||val == '+' || val =='-')return 0;
	else return 1;
}

int ttuutien(char op){
	if(op == '*' || op == '/') return(2);
	else if(op == '+' || op == '-') return(1);
	else return(0);
}

void InfixToPostfix(char infix[], char postfix[]){ 
	int i=0, j=0;
	char item, x;    
	for(i=0; i<=strlen(infix); i++){
		item = infix[i];
		if( isOp(item)==1){
			postfix[j] = item;
			j++;
		}
		if( isOp(item)==0){
			while(ttuutien(item) <ttuutien(stack[top])){
					postfix[j] = pop();	
					j++;
					}
			push(item);
		}
		
	}
		while(!isEmpty(top)){
			x = pop();
			postfix[j] = x;
			j++;
		}
	
}
int chartoint(char item){
	int val;
	val = item - '0';
	return val;
}
int inttochar(int val){
	char item;
	item = val + '0';
	return item;
}
int doOp(int n1, int n2, char op){
	int ans;
	switch(op){
		case '+': ans = n1 + n2;
		break;
		case '-': ans = n1 - n2;
		break;
		case '*': ans = n1 * n2;
		break;
		case '/': ans = n1 / n2;
		break;
	}
	return ans;
}


char Eval(char postfix[]){
	int j, n1, n2, ans;
	char x, result;
	for(j = 0; j<=strlen(postfix); j++){
		x = postfix[j];
		if(!isOp(x)){
			push(x);
		}
		else{
			n1 = chartoint(pop());
			n1 = chartoint(pop());
			ans = doOp(n1,n2, x);
			result = inttochar(ans);
			push(result);
		}
	}
	return pop();
}
	

int main(){
	int j,i ;
	char infix[100];
	char postfix[100];    
	printf("\nEnter string : ");
	fflush(stdin); gets(infix);
	fflush(stdin);
 
	printf("%d", strlen(postfix));
	InfixToPostfix(infix, postfix);                   
	printf("Postfix notation : ");
	
	for(i=0; i<=strlen(infix); i++){
		printf(" %c", postfix[i]);         
		}
	printf(" %c", Eval(postfix));	
	
	return 0;
}
