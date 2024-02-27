#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
typedef struct node NODE;
void insert_begin(NODE** head,int Data)
{
    NODE* nNode=(NODE*)malloc(sizeof(NODE));
    nNode->data= Data;
    if (*head==NULL)
    {
        *head=nNode;
        nNode->link=NULL;
    }
    else
    {
        nNode->link=*head;
        *head=nNode;
    }
    
}

void insert_anywhere(NODE* head,int Data,int no)
{
    NODE* ptr= head;
    if (head==NULL)
    {
        insert_begin(&head,Data);
    }
    else
    {
        int count=0;
        while (ptr->link != NULL)
        {
            ptr=ptr->link;
            count++;
        }
        if (count <= no+1)
        {
            NODE* nNode=(NODE*)malloc(sizeof(NODE));
            nNode->data= Data;
            for (int i = 1; i != no; i++)
            {
                ptr = ptr->link;
            }
            nNode->link=ptr;
            ptr->link=nNode;   
        }
        else
        {
            printf ("we are assining it to end");
            insert_end(&head,Data);
        }
    }
    
}
void insert_end(NODE** head,int Data)
{
    NODE* nNode=(NODE*)malloc(sizeof(NODE));
    nNode->data= Data;
    nNode->link=NULL;
    NODE* ptr=*head;
    while (ptr->link!=NULL)
    {
        ptr = ptr->link;
    }
    ptr->link=nNode; 
}
void insert_af_data(NODE** head, int Data, int no)
{
    NODE* nNode = (NODE*)malloc(sizeof(NODE));
    nNode->data = Data;
    NODE* ptr = *head;

    // Special case: inserting at the beginning
    if (ptr->data == no)
    {
        nNode->link = *head;
        *head = nNode;
        return;
    }

   while (ptr->data!=no && ptr->link != NULL)
   {
        ptr=ptr->link;
   }
   if (ptr->data!=no)
   {
        printf("data does not exist\n");
        printf("we are assining it at the end\n");
        ptr->link = nNode;
        nNode->link= NULL;
   }
   else
   {
        nNode->link = ptr->link;
        ptr->link = nNode;
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
            temp=temp->link;
        }
    } 
}
void begin_delete(NODE*head)
{
    if (head==NULL)
    {
        printf("\nthere is no data to delete\n");
    }
    else
    {
        printf("deleted data is %d",head->data);
        head=head->link;
    }
}
void end_delete(NODE*head)
{
    if (head==NULL)
    {
        printf("\nthere is no data to delete\n");
    }
    else
    {
        NODE* temp;
        temp=head;
        while (temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=NULL;
    }
    
}
void del_anywhere(NODE*head,int no)
{
    if (head==NULL)
    {
        printf("\nthere is no data to delete\n");
    }
    else
    {
        NODE* temp;
        temp=head;
        for (int i = 1; i < no; i++)
        {
            temp=temp->link;
        }
        temp=temp->link;
    }
        
}
void del_af_data(NODE*head,int no)
{
    if (head==NULL)
    {
        printf("\nthere is no data to delete\n");
    }
    else
    {
        NODE* temp;
        temp=head;   
        while (temp->link!=NULL && temp->data != no)
        {
            temp=temp->link;
        }
        if (temp->link==NULL)
        {
            printf("there is no data to delete");
        }
        else
        {
            temp=temp->link->link;
        }
        
        
    }
    
}

void main()
{
    NODE* head=NULL;
    int choice,Data;
    char ch;
    int no;
    do
    {
        printf("for insert at begining press 1\n");
        printf("for insert at end press 2\n");
        printf("for insert at a position press 3\n");
        printf("for insert after any specific data press 4\n");
        printf("enter 5 for display\n");
        printf("for delete data at begining press 6\n");
        printf("for delete data at end press 7\n");
        printf("for delete data at a position press 8\n");
        printf("for delete data after any specific data press 9\n");
        printf("enter 0 for exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter the data");
            scanf("%d",&Data);
            insert_begin(&head,Data);
            break;
        case 2:
            printf("enter the data");
            scanf("%d",&Data);
            insert_end(&head,Data);
            break;
        case 3:
            printf("\nenter specific position no\n");
            scanf("%d",&no);
            printf("enter the data");
            scanf("%d",&Data);
            insert_anywhere(head,Data,no);
            break;

        case 4:
            printf("\n enter specific data \n");
            scanf("%d",&no);
            printf("enter the data");
            scanf("%d",&Data);
            insert_af_data(&head,Data,no);
            break;
        case 5:
            display(head);
            break;
        case 6:
            begin_delete(head);
            break;
        case 7:
            end_delete(head);
            break;
        case 8:
            printf("\n enter specific position \n");
            scanf("%d",&no);
            del_anywhere(head, no);
            break;
        case 9:
            printf("\n enter specific data \n");
            scanf("%d",&no);
            del_af_data(head,no);
            break;
        default:
            exit(0);
            break;
        }
        printf("\n for continue press y \n");
        scanf(" %c",&ch);
    }
    while (ch=='y'|| ch=='Y');
}