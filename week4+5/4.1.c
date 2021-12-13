#include <stdio.h>
#include <stdlib.h>

enum{ 
	SUCESS,
	FAIL
};

struct Address{
    char name[20];
    char phone[9];
    char email[20];
};
int main(){
    FILE *fin;
    
	if ((fin= fopen("PhoneBook.txt", "r")) == NULL){
        printf("Cannot open file!\n");
        return 0;
    }
    
    int cap = 1;
    char c;
    for (c = getc(fin); c != EOF; c = getc(fin)){
        if (c == '\n') cap++;
    }
    
    fseek(fin, 0, SEEK_SET);
    struct Address* stack = (struct Address*)malloc(cap*sizeof(struct Address));
    
	int top = -1;
    while (!feof(fin)){
        top++;
        fscanf(fin, "%s %s %s", (stack+top)->name, (stack+top)->phone, (stack+top)->email);
    }
    fclose(fin);
  
    FILE *fout = fopen("PhoneBookout.txt", "w");
    fprintf(fout, "%-40s %-15s %-15s\n", "Ten", "So DT", "Email");
    while(top > -1){
        fprintf(fout, "%-40s %-15s %-15s\n", (stack+top)->name, (stack+top)->phone, (stack+top)->email);
        top--;
    }
    free(stack);
    fclose(fout);
}
