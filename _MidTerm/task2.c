#include <stdio.h>
#include <string.h>
#include <stdbool.h>


char stack[100], queue[100];
int stack_top = -1, queue_top = -1;

int stack2[100]; int stack_top2 = -1;

bool IsEmpty(int top){
    if (top == -1) return 0;
    else return 1;
}
void push(char arr[], int *top, char val){
    *top = *top+1;
    arr[*top] = val;
}

char pop(char arr[], int *top){
    *top = *top - 1;
    return arr[*top+1];
}



bool isOp(char op){
    if(op == '*' || op == '+' ||op == '-'|| op == '/' )return true;
    else return false;
}

int doOp (int a, int b, char op){
    int ans;
    switch (op) {
        case '+': ans = a + b;
            break;
        case '-': ans = a - b;
            break;
        case '*': ans = a * b;
            break;
        case '/': ans = a % b;
            break;
        }
    return ans;
}

void push2(int arr[], int *top, int val){
    *top = *top+1;
    arr[*top] = val;

}
int pop2(int arr[], int *top){
    *top = *top - 1;
    return arr[*top+1];
}

int chartoint(char a){
    int i = a-'0';
    return i;
}

int main(){
    char inp[100], outp[100];
    int i;
    printf("Input: "); fflush(stdin); scanf("%s", &inp);
    for (i = 0; i < strlen(inp); i++){
        if ('0' <= inp[i] && inp[i] <= '9'){
            push(queue, &queue_top, inp[i]);
        }else if(inp[i] == '*' || inp[i] == '/'){
            while(!IsEmpty(stack_top)){
                if (stack[stack_top] == '*' || stack[stack_top] == '/'){
                    char temp = pop(stack, &stack_top);
                    push(queue, &queue_top, temp);
                }else break;
            }
            push(stack, &stack_top, inp[i]);
        }else{
            while(!IsEmpty(stack_top)){
                char temp = pop(stack, &stack_top);
                push(queue, &queue_top, temp);
            }
            push(stack, &stack_top, inp[i]);
        }
    }
    while (!IsEmpty(stack_top)){
        char temp = pop(stack, &stack_top);
        push(queue, &queue_top, temp);
    }
 
    printf("Result: ");
    for ( i = 0; i <= queue_top; i++){
        printf(" %c", queue[i]);
    }


    for (i = 0; i <= queue_top; i++){
        char c1 = 0;
        int c2 = 0, n1, n2, ans;
        c1 = queue[i]; 
        if (isOp(c1)) {
            c2 = chartoint(c1);
             push2(stack2, &stack_top2, ans); 
        } 
        else { 
            n1 = pop2(stack2, &stack_top2);
            n2 = pop2(stack2, &stack_top2);
            ans = doOp (n1, n2, c1);
             push2(stack2, &stack_top2, ans);
        }
    } 
    printf("\n %d", pop2(stack2, &stack_top2));
return 0;
}
