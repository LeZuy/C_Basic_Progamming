#include<stdio.h>       
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
		printf("Stack empty!");
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
	printf("%d",strlen(infix));
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
	

int main(){
	int j;
	char infix[SIZE], postfix[SIZE];    
	printf("\nEnter string : ");
	fflush(stdin); gets(infix);
	InfixToPostfix(infix, postfix);                   
	printf("Postfix notation : ");
	
	for(j=0; j<=strlen(infix); j++){
		printf(" %c", postfix[j]);         
		}
	return 0;
}
