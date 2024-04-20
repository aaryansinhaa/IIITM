#include <stdio.h>
#define SIZE 100
int top =-1;
void pop(int *stack){
	if(top<0){
		printf("Cannot Delete\nThe Stack is EMPTY!!!\n");
	}else{
		printf("Deleting the element %d", stack[top]);
		top--;

	}
}
void status(int *stack){

	int sizeleft = SIZE -top;
	int percent = (sizeleft/SIZE);
	int space = percent * 100;
	printf("STATUS: %d percent space left", space);

}
void push(int *stack){
	int ITEM = 0;
	if(top==-1){
		printf("\nCreating stack....\n");
		printf("\nEnter the Element\n");
		scanf("%d", &ITEM);
		top++;
		stack[top] = ITEM;
	}else if(top > SIZE){
		printf("\nOverFlow!!\n");
	}else{
		printf("\nEnter the element\n");

		scanf("%d", &ITEM);
		top++;

		stack[top] = ITEM;

	}

}
void display(int *stack){
	printf("TOP ->");
	
	for(int i = top; i>=0; i--){
		printf("%d\n", stack[i]);

	}

}

int main(void){
	
	int choice, stack[SIZE];
	do{printf("\n\n---------STACK----------\n\n");

	printf("1. Push\n2. Pop\n3. Display\n4. Status\n5. Exit");
	printf("\nEnter your Choice?\n");
	scanf("%d", &choice);
		
		switch(choice){
			case 1:
				push(stack);
				break;
			case 2: 
				pop(stack);
				break;
			case 3:
				display(stack);
				break;
			case 4:
				status(stack);
				break; 
			case 5:
				printf("\nExiting.....\n");
			default:
				printf("\n\nPlease Enter a valid choice!\n\n");

		}


	}while(choice !=5);


	return 0;
}
