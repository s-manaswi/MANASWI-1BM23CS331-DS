#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertatfirst(struct node** head, int data){
    struct node* newnode = createnode(data);
    newnode ->next = *head;
    *head = newnode;
}

void insertatend (struct node* *head, int data){
    struct node* newnode = createnode(data);
    if (*head == NULL){
        *head = newnode;
        return;
    }
    struct node*temp= *head;
    while(temp->next =NULL){
        temp= temp->next;
    }
    temp ->next =newnode;
}

void insertatposition (struct node* *head, int data, int position){
    struct node* newnode= createnode(data);
    if (position==1){
        newnode-> next = * head;
        *head =newnode;
        return;
    }
    struct node* temp = *head;
    for (int i=1; i< position-1 && temp!=NULL;i++)
    {
        temp = temp->next;
    }
    if (temp==NULL)
    {
        printf("position out of range/n");
        free (newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void display(struct node* head)
{
    struct node* temp= head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    struct node*head=NULL;
    int choice, data,postion;
    while(1){
        printf("enter choices:\n");
        printf("1.insert at first position\n 2.insert at end\n 3.insert at specific location\n 4.display\n 5.exit\n");
        printf("\nenter your choices:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter data to insert:");
                    scanf("%d",&data);
                    insertatfirst(&head, data);
                    break;
            case 2: printf("enter data to insert:");
                    scanf("%d",&data);
                    insertatend(&head,data);
                    break;
            case 3: printf("enter data to insert:");
                    scanf("%d",&data);
                    printf("enter position:");
                    scanf("%d ",&postion);
                    insertatposition(&head,data,postion);
                    break;
            case 4: printf("the elements are: ");
                    display(head);
                    break;
            case 5: exit(0);
                    break;
            default: printf("invalid choice");
        }
    }
}