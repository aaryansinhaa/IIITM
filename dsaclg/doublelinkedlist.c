#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*rl,*ll;
};
typedef struct node NODE;

void insert_begining(NODE**head)
{
    printf("\nenter the data");
    NODE*Nnode=(NODE*)malloc(sizeof(NODE));
    scanf("%d",&Nnode->data);
    if (*head==NULL)
    {
        Nnode->ll=NULL;
        Nnode->rl=NULL;
        *head=Nnode;
    }
    else
    {
        Nnode->rl=*head;
        (*head)->ll=Nnode;
        *head=Nnode;
    }
}

void insert_end(NODE**head)
{
    printf("\nenter the data");
    NODE*Nnode=(NODE*)malloc(sizeof(NODE));
    scanf("%d",&Nnode->data);

    if (*head==NULL)
    {
        *head=Nnode;
        Nnode->ll=NULL;
        Nnode->rl=NULL;
    }
    else
    {
        NODE*temp=*head;
        while (temp->rl!=NULL)
        {
            temp=temp->rl;
        }
        Nnode->rl=NULL;
        Nnode->ll = temp;
        temp->rl=Nnode;
    }

}
void insert_anywhere(NODE** head)
{
    int no;
    printf("\nenter the data and position");
    NODE* ptr= *head;
    NODE* nNode=(NODE*)malloc(sizeof(NODE));
    scanf("%d %d",&nNode->data,&no);
    if (*head==NULL)
    {
        *head=nNode;
        nNode->rl=NULL;
        nNode->ll=NULL;
    }
    else
    {
        int count=1;
        while (ptr != NULL)
        {
            ptr=ptr->rl;
            count++;
        }
        if (count >= no)
        {
          NODE*temp=*head;
            for (int i = 1; i != no-1; i++)
            {
                temp = temp->rl;
            }
            nNode->rl=temp->rl;
            nNode->ll=temp;
            temp->rl=nNode;
        }
        else
        {
            printf ("invalid");
        }
    }

}

void insert_af_data(NODE**head)
{
    int pos;
    printf("\nenter the position data and data");
    NODE*Nnode=(NODE*)malloc(sizeof(NODE));
    scanf("%d%d",&pos,&Nnode->data);

    if (*head==NULL)
    {
        *head=Nnode;
        Nnode->ll=NULL;
        Nnode->rl=NULL;
    }

    else
    {
        NODE*temp=*head;
        while(temp->data!=pos && temp->rl != NULL)
        {
            temp=temp->rl;
        }

        if(temp->data != pos)
        {
            printf("invalid data position");
        }
        else
        {
            Nnode->rl = temp->rl;
            Nnode->ll=temp;
            temp->rl = Nnode;
            printf("entered data is %d\n",temp->data);
            printf("entered data is %d\n",temp->rl->data);
            printf("entered data is %d\n",temp->ll->data);
        }

    }
}

void delete_beginig(NODE**head)
{
    if (*head==NULL)
    {
        printf("no data to delete");
    }

    else
    {
        NODE*ptr=*head;
        if ((*head)->rl==NULL)
        {
            *head=(*head)->rl;
        }

        else
        {
            (*head)->rl->ll=*head;
            *head=(*head)->rl;
        }
        free(ptr);
    }
}


void delete_end(NODE** head) {
    if (*head == NULL) {
        printf("No data to delete");
    } else {
        NODE* temp = *head;

        // Traverse to the last node
        while (temp->rl != NULL) {
            temp = temp->rl;
        }

        if (temp->ll != NULL) {
            // If there is a previous node, update its right link to NULL
            temp->ll->rl = NULL;
        } else {
            // If there is no previous node, update the head pointer
            *head = NULL;
        }

        // Free the last node
        free(temp);
    }
}



void delete_position(NODE** head) {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (*head == NULL)
    {
        printf("No data to delete");
    }
    else if ((*head)->rl == NULL)
    {
        NODE*ptr=*head;
        *head=NULL;
    }

    else {
        NODE* temp = *head;
        int count = 0;

// Count the number of nodes in the linked list
        while (temp->rl != NULL && count != pos-1) {
            temp = temp->rl;
            count++;
        }
        NODE*ptr;
        if (temp->rl == NULL && count==pos-1)
        {
            ptr=temp->ll->rl;
            temp->ll->rl=NULL;
            free(ptr);
        }
        else if (temp->rl != NULL)
        {
            ptr=temp->ll->rl;
            temp->rl->ll=temp->ll;
            temp->ll->rl=temp->rl;
            free(ptr);
        }

        else
        {
            printf("invalid position");
        }


    }
}




void delete_af_data(NODE** head)
{
    int pos;
    printf("enter the data");
    scanf("%d", &pos);
    if (*head == NULL)
    {
        printf("no data to delete");
    }

    else
    {
        NODE* temp = *head;

        while (temp != NULL && temp->data != pos)
        {
            temp = temp->rl;
        }

        if (temp == NULL)
        {
            printf("data does not exist");
        }

        else
        {
            NODE* ptr = temp;
            if (temp->rl == NULL)
            {
                temp->ll->rl = NULL;
            }

            else
            {
                temp->rl->ll = temp->ll;
                temp->ll->rl = temp->rl;
            }
            free(ptr);
        }
    }
}


void display(NODE*head)
{
    if (head==NULL)
    {
        printf("empty linked list");
    }
    else
    {
        NODE* temp;
        temp=head;
        while (temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->rl;
        }
    }
}

int main() {
    NODE *head = NULL;
    int choice;

    do {
        printf("\n\n--- Linked List Operations ---");
        printf("\n1. Insert at the Beginning");
        printf("\n2. Insert at the End");
        printf("\n3. Insert at Any Position");
        printf("\n4. Insert After a Data Value");
        printf("\n5. Delete from the Beginning");
        printf("\n6. Delete from the End");
        printf("\n7. Delete at a Specific Position");
        printf("\n8. Delete After a Data Value");
        printf("\n9. Display Linked List");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_begining(&head);
                break;

            case 2:
                insert_end(&head);
                break;

            case 3:
                insert_anywhere(&head);
                break;

            case 4:
                insert_af_data(&head);
                break;

            case 5:
                delete_beginig(&head);
                break;

            case 6:
                delete_end(&head);
                break;

            case 7:
                delete_position(&head);
                break;

            case 8:
                delete_af_data(&head);
                break;

            case 9:
                display(head);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
