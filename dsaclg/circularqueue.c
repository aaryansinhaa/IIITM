#include <stdio.h>
#define SIZE 5
int front = -1, rear = -1;
int cqinsert(int*);
int cqdelete(int*);
int display(int*);

int main(void){
	int choice, cqueue[SIZE];
	do{
	printf("\n-----CIRCULAR QUEUE--------\n");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit");
		printf("\nENTER YOUR CHOICE\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				cqinsert(cqueue);
				break;
			case 2:
				cqdelete(cqueue);
				break;
			case 3:
				display(cqueue);
				break;
			case 4: 
				printf("\n\nEXITING.....");
				return 0;
			default:
				printf("\nEnter a valid choice!\n");
		}




	}while(choice != 4);


	return 0;

}



int cqinsert(int* cqueue){
	int ITEM;
	if(front == -1 && rear == -1){
		printf("\nCreating A CIRCULAR QUEUE\n");
		printf("\nEnter the Element\n");
		scanf("%d", &ITEM);
		front++;
		rear++;
		cqueue[rear] = ITEM;

	}else if(rear%SIZE == front ){
		printf("\nOVERFLOW!!\n");

	}else{
		printf("ENTER THE ITEM\n");
		scanf("%d", &ITEM);
	
		rear = (rear+1)%SIZE;
		cqueue[rear] = ITEM;
	}


}
int cqdelete(int*);
int display(int* queue){
	
	


}

