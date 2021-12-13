#include<stdio.h>
#include<stdlib.h>

void DoubleSpace(FILE *fin, FILE *fout){
	int c;
	while((c = fgetc(fin) )!= EOF){
		putc(c, fout);
		if ( c == '\n')
		putc('\n', fout);
	}
}
void Printf(char *pgm_name){
	printf("\n%s%s%s\n\n%s%s\n\n", "Usage: ", pgm_name, " infile outfile", "The contents of infile will be double-spaced","and written to outfile.");
}

int main(int argc, char **argv){
	FILE *fin, *fout;
	
	if(argc != 3){
		Printf(argv[0]);
		exit(1);
	}
	fin = fopen(argv[1],"r");
	fout = fopen(argv[2],"w");
	DoubleSpace(fin, fout);
	fclose(fin), fclose(fout);
	
	return 0;
	}
