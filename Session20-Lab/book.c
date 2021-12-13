#include<stdio.h>
#include<string.h>
#include<conio.h>


struct book_st{
    int book_cd;
    char book_nm[30];
    char author[30];
    int copies;
};
struct date_st{
    int day;
    int month;
    int year;
};
struct tran_st{
    int book_cd;
    char tran_type;
    struct date_st tran_date;
};

struct book_st books[5];
struct tran_st trans[10];

void main(){
    char addflag;
    int choice = 1, i;
    struct book_st books[5];
    struct tran_st trans[10];

    while(choice!=4){
        system("cls");
        printf("\nSelect from menu: \n1.Add books\n2.Add transaction\n3.Sort transaction\n4.Exit\n");
        scanf("%d", &choice);

    
    switch(choice){
        case(1):
           addflag = 'y';
           for(i = 0; i<5 && addflag == 'y'; i++){
               books[i].book_cd = i + 1;
            printf("Book code: %d \n Book Name: ", i+1);
            scanf("%s", books[i].book_nm);
            printf("Author: "); scanf("%s", books[i].author);
            printf("Num of copies: "); scanf("%d", &books[i].copies);
            printf("Continue? "); scanf(" %c", &addflag);   
           }
        break;   
    /* addflag = 'y';

for(i = 0; i < 5 && addflag == 'y'; i++)
{ books[i].book_cd = i + 1;
printf("\n\nBook code: %d\n\nBook name:",
i+1);
scanf("%s", books[i].book_nm);
printf("\nAuthor: ");
scanf("%s", books[i].author);
printf("\nNumber of copies: ");
scanf("%d", &books[i].copies);
printf("\n\nContinue? (y/n): ");
scanf(" %c", &addflag);
*/


        case(2):
            
            addflag = 'y';
            
            for(i=0; i<10 && addflag == 'y'; i++){
                printf("\n\nBookcode: "); 
                scanf("%d", &trans[i].book_cd );
                printf("\nIssue or Return (I/R): ");
                 scanf(" %c", &trans[i].tran_type);
                printf("\n Date: ");  
                scanf("%d %d %d", &trans[i].tran_date.day, 
                                     &trans[i].tran_date.month,
                                      &trans[i].tran_date.year);
                printf("\n\n Continue(y/n): "); 
                scanf(" %c", &addflag);
            }
        break;    
        
            
        case(3):
            
                sorttrans(trans);
        break; 

        default:
            printf("Bye");
        break;
        }    
    }
}

/*sorttrans(struct tran_st trans[10]){
    int i, j, tempcode;
    struct tran_st temptran;
    for(i=0; i<10; i++){
        for(j= i+1; j<10; j++){
            if(trans[j].book_cd < trans[i].book_cd){
                temptran = trans[i];
                trans[i] = trans[j];
                trans[j] = temptran;
            }
        }
    }
    for(i=0, j=0; i<10; j=0){
        tempcode = trans[i].book_cd;
        while (trans[i].book_cd == tempcode && i<10 ){
            j++; i++;
        }
        printf("%d", i);
        printf("\nBook code %d has %d transactions", tempcode, j); 
    }
    getch();
}*/
sorttrans(struct tran_st trans[10]){
int i, j, tempcode;
struct tran_st temptran;

for(i = 0; i < 10; i++)
for(j = i + 1; j < 10; j++){
        if(trans[i].book_cd > trans[j].book_cd)
{ temptran = trans[i];
trans[i] = trans[j];
trans[j] = temptran;
}
}
for(i = 0, j = 0; i < 10; j = 0)
{ tempcode = trans[i].book_cd;
while(trans[i].book_cd == tempcode && i < 10)
{ j++;
i++;
}
printf("\nBook code %d had %d transactions",
tempcode, j);
}
getch();
}

