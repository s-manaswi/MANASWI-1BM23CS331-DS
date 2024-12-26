#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

void insertatfirst(struct Node** head, int data){
    struct Node* newnode =createNode(data);
    newnode->next = *head;
    *head = newnode;
}

void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteElement(struct Node** head, int key) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = *head, *prev = NULL;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element at the end\n 2.Delete first element\n 3.Delete specified element\n 4.Delete last element\n 5.Display list\n 6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertatfirst(&head, value);
                break;
            case 2:
                deleteFirst(&head);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteElement(&head, value);
                break;
            case 4:
                deleteLast(&head);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}