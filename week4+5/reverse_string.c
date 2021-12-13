#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
		char data;
		struct node *link;
};

//Nganxep
struct node *push(struct node *p, char *value){
	struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
	if (temp == NULL){
		printf("Unable to push data \n");
		exit(0);
	}
	temp->data = *value;
	temp->link = p;
	p = temp;
	return(p);
}

struct node *pop(struct node *p, char *value){
	struct node *temp;
	if (p == NULL){
		printf("Stack empty");
		exit(0);
	}
	*value = p->data;
     printf("%c", *value);
	temp = p;
	p = p->link;
	free(temp);
	return (p);
}
void In(struct node *top){
	struct node *p;
	for( p = top; p!=NULL; p =p->link ){
		printf("%c", p->data);
	}
}

int main(){
	struct node *top = NULL;
	int n, value, i, *p;
	char *s;
		printf("So ky tu xau: "); scanf("%d", &n);
		s = (char*)malloc(n *sizeof(char));
		if(s == NULL){
			printf("Ko the cap phat bo nho");
			return 1;
			}
	printf("Nhap xau: ");scanf("%s", s);
	for(i=0; i<n; i++){
		top = push(top, &s[i]);
	}
	//In(top);
	while(top!=NULL){
		top = pop(top, &s[i]);
	}
	return 0;
}
	


