#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pAddr{
    char name[20];
    char pNum[10];
    char eAddr[20];
};
typedef struct pAddrList{
    struct pAddr data;
    struct pAddrList *next;
} *node;
node createNode (struct pAddr val){
    node temp = (node)malloc(sizeof(struct pAddrList)); // Check thu voi sizeof(node)?
    temp->data = val; temp->next = NULL;
    return temp;
}
node addNode(node head, struct pAddr val, int pos){
    if (pos == 0 || head == NULL){
        node temp = createNode(val);
        if (head == NULL) head = temp;
        else{
            temp->next = head;
            head = temp;
        }
    }else{
        int k = 1; node p = head; // chen node thi can biet node truoc vi tri chen
        while (p != NULL && k != pos){ // dung o vi tri node cuoi+1
            p = p->next;
            k++;
        }
        if (k != pos){// den null roi ma chua den vi tri
            printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else{
            node temp = createNode(val);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
void Traverser(node head){
    node p;
    printf("%-40s %-15s %-15s\n", "Ten", "So DT", "Email");
    for( p = head; p != NULL; p = p->next){
        printf("%-40s %-15s %-15s\n", p->data.name, p->data.pNum, p->data.eAddr);
    }
}
node delNode(node head, int pos){
    if(pos == 0 || head == NULL || head->next == NULL){ // Neu head->next == NULL -> ko ton tai head->next->next
        if (head == NULL) printf("Cha co gi de xoa het!");
        else head = head->next;
    }else{
        int k = 1; node p = head; // can biet node truoc vi tri xoa
        while (p->next->next != NULL && k != pos){ // Dung o vi tri node cuoi
            p = p->next;
            k++;
        }
        if (k != pos) printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        else{
            node curr = p->next;
            p->next = p->next->next;
            free(curr);
        }
    }   
    return head;
}
node list_reverse(node head){
    node curr = head, prev = NULL, temp;
    while (curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}
node AddTail(node head, struct pAddr val){
    node temp = createNode(val);
    if (head == NULL) head = temp;
    else{
        node p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
node loadFile(char filename[], node head){
    FILE *in = fopen(filename, "r");
    if (in == NULL) printf("Load data -> file not found\n");
    struct pAddr temp;
    while (!feof(in)){
        fscanf(in, "%s %s %s", &temp.name, &temp.pNum, &temp.eAddr);
        head = AddTail(head, temp);
    }
    fclose(in);
    return head;
}
void Find(char name[], node head){
    node p, rs = NULL;
    for ( p = head; p != NULL; p = p->next){
        if (strcmp(p->data.name, name) == 0){
            rs = p;
            break;
        }
    }
    if (rs == NULL) printf("Cannot found %s!\n", name);
    else{
        printf("Found profile is:\n");
        printf("%-40s %-15s %-15s\n", "Ten", "So DT", "Email");
        printf("%-40s %-15s %-15s\n", rs->data.name, rs->data.pNum, rs->data.eAddr);
    }
}
void saveFile(char filename[], node head){
    node p;
    FILE *out = fopen(filename, "w");
    fprintf(out, "%-40s %-15s %-15s\n", "Ten", "So DT", "Email");
    for ( p = head; p != NULL; p = p->next){
        fprintf(out, "%-40s %-15s %-15s\n", p->data.name, p->data.pNum, p->data.eAddr);
    }
    fclose(out);
}
int main(){
    printf("Chuong trinh quan li so dien thoai\n");
    printf("1. Them ban ghi\n2. In danh sach\n3. Xoa ban ghi\n4. Dao nguoc danh sach\n5. Doc va ghi du lieu tu file\n6. Tim ban ghi\n7. Luu du lieu vao file van ban\n8. Thoat\n");
    int c = 0; node head = NULL; struct pAddr val; int pos;
    char filename[1000], name[40];
    while (c != 8){
        printf("Nhap lua chon: "); scanf("%d", &c);
        switch(c){
            case 1:
                printf("Nhap lan luot thong tin:\n");
                printf("Ten: "); fflush(stdin); gets(val.name);
                printf("So dien thoai: "); fflush(stdin); gets(val.pNum);
                printf("Email: "); fflush(stdin); gets(val.eAddr);
                printf("Nhap vi tri can chen: "); scanf("%d", &pos);
                head = addNode(head, val, pos);
                break;
            case 2:
                Traverser(head);
                break;
            case 3:
                printf("Nhap vi tri can xoa: "); scanf("%d", &pos);
                head = delNode(head, pos);
                break;
            case 4:
                head = list_reverse(head);
                break;
            case 5:
                printf("Nhap ten file: "); fflush(stdin); gets(filename);
                head = loadFile(filename, head);
                break;
            case 6:
                printf("Nhap ten can tim: "); fflush(stdin); gets(name);
                Find(name, head);
                break;
            case 7:
                printf("Nhap ten file: "); fflush(stdin); gets(filename);
                saveFile(filename, head);
                break;
            case 8:
                printf("Hen gap lai!\n");
                break;
            default:
                printf("Sai dinh dang!\n");
                break;
        }
    }
}
