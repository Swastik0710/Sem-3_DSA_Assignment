//Write a program to implement all functions (insert- first, insert- last, insert- any, delete- first, delete- last & delete- any) of circular linked list.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;
struct Node* insertFirst(struct Node* head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    return newNode;
}
struct Node* insertLast(struct Node* head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}
struct Node* insertAny(struct Node* head, int value, int position) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (position == 1) {
        if (head == NULL) {
            newNode->next=newNode;
            return newNode;
        }
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        return newNode;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head && position != 1) {
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    struct Node *delNode = head;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    temp->next = head->next;
    head = head->next;
    free(delNode);
    return head;
}
struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node *temp = head;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    while (temp->next->next != head) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
    return head;
}
struct Node* deleteAny(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (position == 1) {
        return deleteFirst(head);
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head) {
        return head;
    }
    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    return head;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular linked list: \n");
    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}
int isPositionValid(struct Node* head, int position) {
    if (position <= 0) {
        return 0;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    return temp != NULL || position == 1;
}
int main() {
    struct Node *head = NULL;
    int ch, value, position;
    while (1) {
        printf("Choose your operation: ");
        printf("\n1. Insert- first\n2. Insert- last\n3. Insert- any\n4. Delete- first\n5. Delete- last\n6. Delete- any\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            head = insertFirst(head, value);
            printf("Inserted %d.\n", value);
            display(head);
            break;
        case 2:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &value);
            head = insertLast(head, value);
            printf("Inserted %d.\n", value);
            display(head);
            break;
        case 3:
            printf("Enter the position to insert the element: ");
            scanf("%d", &position);
            if (!isPositionValid(head, position)) {
                printf("Position doesn't exist.\n");
                break;
            }
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            head = insertAny(head, value, position);
            printf("Inserted %d.\n", value);
            display(head);
            break;
        case 4:
            head = deleteFirst(head);
            printf("First node deleted.\n");
            display(head);
            break;
        case 5:
            head = deleteLast(head);
            printf("Last node deleted.\n");
            display(head);
            break;
        case 6:
            printf("Enter the position to delete the element: ");
            scanf("%d", &position);
            head = deleteAny(head, position);
            printf("Node at position %d deleted.\n", position);
            display(head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            printf("Program exited.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
