//Write a program to implement all functions (insert- first, insert- last, insert- any, delete- first, delete- last & delete- any) of doubly linked list.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;
struct Node* insertFirst(struct Node* head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}
struct Node* insertLast(struct Node* head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
struct Node* insertAny(struct Node* head, int value, int position) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position doesn't exist.\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("First node deleted.\n");
    return head;
}
struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    printf("Last node deleted.\n");
    return head;
}
struct Node* deleteAny(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node *temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
    } else {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
        printf("Node at position %d deleted.\n", position);
    }
    return head;
}
void display(struct Node* head) {
    struct Node *temp = head;
    printf("Doubly Linked list: \n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            head = insertAny(head, value, position);
            printf("Inserted %d.\n", value);
            display(head);
            break;
        case 4:
            head = deleteFirst(head);
            display(head);
            break;
        case 5:
            head = deleteLast(head);
            display(head);
            break;
        case 6:
            printf("Enter the position to delete the element: ");
            scanf("%d", &position);
            head = deleteAny(head, position);
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
