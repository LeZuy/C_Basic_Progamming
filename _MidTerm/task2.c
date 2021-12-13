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
	if(val == '*' || val == '/' ||val == '+' || val =='-')return true;
	else return false;
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
		printf(" %c", item);
		if( !isOp(item)){
			postfix[j] = item;
			j++;
		}
		if(isOp(item)){
			printf(" %c", stack[top]);
			if(ttuutien(item)<ttuutien(stack[top])){
				push(item);
				j++;
			}
			else{
				postfix[j] = item;
				while(!isEmpty(top)){
					postfix[j] = pop();
					j++;
				}
			}
		}
	}
}
int main()
{
	char infix[SIZE], postfix[SIZE];    
	printf("\nEnter string : ");
	fflush(stdin); gets(infix);
	InfixToPostfix(infix, postfix);                   
	printf("Postfix notation : ");
	printf(" %s", postfix);                    
	return 0;
}
