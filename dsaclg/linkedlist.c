#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;

};
typedef struct node NODE;

void insert_at_beggining(NODE**);
void insert_at_end(NODE**);
void insert_at_position(NODE**);
void display(NODE*);
void delete_at_beggining(NODE**);
void delete_at_end(NODE**);
void delete_at_position(NODE**);



int main(void){
	NODE* head = NULL;
	int choice;
	do{
		printf("\n--------SINGLY LINKED LIST----------\n");
		printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Insert after a data\n5. Display\n6. Delete at Beginning\n7. Delete at End\n8. Delete at Position\n9. Delete after Data\n 10. To Exit.");
	scanf("%d", &choice);
		switch(choice){
			case 1:
				insert_at_beggining(&head);
				break;
			case 2:
				insert_at_end(&head);
				break;
			case 3:
				insert_at_position(&head);
				break;
			case 5:
				display(head);
				break;
			case 6:
				delete_at_beggining(&head);
				break;
		/*	case 7:
				delete_at_end(&head);
				break;
			case 8:
				delete_at_position(&head);*/
			case 10:
				printf("\n\nEXITING.........");
				break;
			default:
				printf("\n\nPlease Enter a Valid Choice\n\n");
		}

	}while(choice !=10);

	return 0;
}



void insert_at_beggining(NODE** head){
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	printf("\nEnter the Data!");
	scanf("%d", &ptr->data);
	ptr->next = NULL;
	if(*head == NULL){
		*head = ptr;

	}else{
		ptr->next = *head;
		*head = ptr;

	}


}
void insert_at_end(NODE** head){
	NODE* ptr = (NODE*)malloc(sizeof(NODE*));
	printf("\nEnter the Data!");
	scanf("%d", &ptr->data);
	ptr->next = NULL;
	NODE* temp = *head;
	if(*head == NULL){
		*head = ptr;
	}else{
		while(temp->next != NULL){
			temp = temp->next;
			
		}
		temp->next = ptr;
	}



}
void insert_at_position(NODE** head){
	NODE* ptr = (NODE*)malloc(sizeof(NODE*));
	printf("\nEnter the Data!");
	scanf("%d", &ptr->data);
	ptr->next = NULL;
	NODE* temp = *head;
	int posn;
	printf("\nEnter the Position:");
	scanf("%d", &posn);
	if(*head == NULL){
		*head = ptr;
	}else{
		int i = 1;
		int count = 1;
		for(count = 1; temp->next!=NULL; count++){temp = temp->next;}
		if(posn>count){
			printf("\nThe position %d does not exist, inserting at the last possible position\n", posn);
		}
		while(temp->next != NULL && i<posn){
			temp = temp->next;
			i++;
		}
		ptr->next = temp->next;
		temp->next = ptr;
		
	}



}
void display(NODE* head){
	if(head == NULL){
		printf("\nEmpty List!!\n");

	}else{
		printf("Start ");
		while(head != NULL){
			printf(" -> %d", head->data);
			head = head->next;


		}
		printf(" <-END");

	}


}
void delete_at_beggining(NODE** head){
	
	NODE* temp = *head;
	printf("Deleting %d.", temp->data);

	*head = temp->next;
	 
	free(temp);



}
void delete_at_end(NODE** head){
	
	NODE* temp = *head;
	NODE* ptr;
	while(temp->next!= NULL){
		ptr = temp;
		temp = temp->next;
	}
	printf("Deleting")
	ptr->next = NULL;
	

	


}


