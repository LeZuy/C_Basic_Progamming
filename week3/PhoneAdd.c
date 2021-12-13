#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char phone[9];
	char name[20];
	char email[20];
}phonebook;

typedef struct linked_list{
     phonebook data;
    struct linked_list *next;
}node;

node *root, *cur;

node *Create( phonebook value){
    node *new;
        new = (node*)malloc(sizeof(node));
        new->data = value;
        new->next = NULL;
    return new;
}

node *AddAt(int pos, phonebook value, node *head){
	node *new = Create(value);
	if(pos == 0 || head == NULL){ 		//p = 0 la vi tri head
		if(head == NULL)head = new;
		else{ 
			new->next = head;
			head = new;
			} 
		}
	else{
		int k = 1;
		node *temp = head;
			while(k != pos && temp != NULL){
				temp = temp->next;
				k++;
			}
			if(k!=pos)printf("Vi tri chen vuot qua vi tri cuoi cung");
			else{
				new->next = temp->next;
				new->data = value;
			}
		}
	return head;
	}




void Traversal(node head){
    printf("\n");
    printf(" %-40s %-15s %-15s", "Ten", "So DT", "Email");
    for(cur = root->next; cur != NULL; cur = cur->next){
    	printf(" %-40s %-15s %-15s", cur->data.name, cur->data.phone, cur->data.email);
//        printf("->%d", cur->data);
    }
}

node *DeleteAt(node *head, int pos){
	int k = 1; 
		node *temp;
	if(pos == 0 || head == NULL || head->next == NULL){
		if(head == NULL){
			printf("Danh sach trong");
		}
		else head = head->next;
		return head;
	}
		
	else{
	
		
		while(temp->next->next != NULL && k != pos){
			temp = temp->next;
			++k;
		}
	}
	if(k!=pos)printf("Vi tri xoa vuot qua vi tri cuoi cung");
	else{ 
		temp = temp->next;
		temp->next = temp->next->next;
		free(temp);
		}
		return head;
	
}
node *reverse(node *head){
    node *prev = NULL, *temp;
    cur = head;
    
    while (cur != NULL){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
    return head;
}

void SearchName(char name[], node *head){
    node *tmp, *result = NULL;
    for (tmp = head; tmp != NULL; tmp = tmp->next){
        if (strcmp(tmp->data.name, name) == 0){
            result = tmp;
            break;
        }
    }
    if (result == NULL) printf("Cannot found %s!\n", name);
    else{
        printf("Found profile is:\n");
        printf("%-40s %-15s %-15s\n", "Ten", "So DT", "Email");
        printf("%-40s %-15s %-15s\n", result->data.name, result->data.phone, result->data.email);
    }
}

int main(){
	
    return 0;

}

