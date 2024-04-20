#include <stdio.h>
#define SIZE 100
int front = -1, rear = -1;

void enqueue(int*);
void dequeue(int*);
void display(int *);
int main(void){
	int choice, queue[SIZE];
	do{
		printf("\n-----LINEAR QUEUE--------\n");
		printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
		printf("\nENTER YOUR CHOICE\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				enqueue(queue);
				break;
			case 2:
				dequeue(queue);
				break;
			case 3:
				display(queue);
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

void enqueue(int* queue){
	int ITEM;
	if(front == -1 && rear == -1){
		printf("\nCreating a Linear Queue\n");
		front++;
		rear++;
		printf("ENTER THE ITEM\n");
		scanf("%d", &ITEM);
		queue[rear] = ITEM;
	}else if(rear >= SIZE){
		printf("\nOVERFLOW!!!\n");
	}else{
		rear++;
		printf("ENTER THE ITEM\n");
		scanf("%d", &ITEM);
		queue[rear] = ITEM;


	}

}
void dequeue(int* queue){
	if(front == -1 && rear == -1){
		printf("\nQueue Undefined or Underflow!!!\n");
	}else {
		printf("\n DELETING ITEM %d", queue[front]);
		front++;

	}
	

}


void display(int* queue){
	printf("front -> ");
	for(int i = front; i<= rear; i++){
		printf("%d  ",queue[i] );

	}
	printf(" <- rear");

}
