#include<stdio.h>
#include<string.h>

struct Address{
	char Name[20];
	char Email[20];
	char Number[10];	
};
 
struct Address a[100];


int main(){
	int index = 0;
	FILE *fin = fopen("PhoneBook.txt","r");
		if (fin == NULL){
			printf("Cannot open file");
			return 0;
			}

		while(!feof(fin)){
			fscanf(fin, "%s %s %s", &a[index].Name, &a[index].Number, &a[index].Email);
				index++;
		}
	fclose(fin);

	char key[20];
		printf("Nhap ten can tim: "); fflush(stdin); gets(key);
	int found = -1, i;
		for (i = 0; i < index; i++){
			if(strcmp(a[i].Name, key) == 0){
			found = i;
			break;
			}
		}
		if (found == -1)printf("Name not found\n");
		else {
			printf("Success!\n");
			FILE *fout = fopen("result.txt", "w");
			fprintf(fout, "Found record:\n Name: %s, PhoneNumber: %s, Email: %s", a[i].Name, a[i].Number, a[i].Email);
			fclose(fout);
		}
}
