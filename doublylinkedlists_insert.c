#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};struct node *head,*tail;

struct Node* createList(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    int count = 1;

    newNode->data = data;

    if (position == 1) {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        printf("Inserted %d at position %d.\n", data, position);
        return;
    }

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, position);
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        printf("List was empty. Inserted %d as the first node.\n", data);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end.\n", data);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Linked List contents:\n");
    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while(1){
        printf("\nMenu:\n");
        printf("1. Create the doubly linked list\n");
        printf("2. Insert a new node at the beginning\n");
        printf("3. Insert a new node at a specific position\n");
        printf("4. Insert a new node at the end\n");
        printf("5. Display the contents of the list\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first node's value: ");
                scanf("%d", &data);
                head = createList(data);
                printf("List created with first node having value: %d\n", data);
                break;

            case 2:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 5:
                displayList(head);
                break;

            case 6:
                exit(0);
               

            default:
                printf("Invalid choice. Please try again.\n");
        }

    }
}