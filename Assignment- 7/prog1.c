//Write a program to implement all functions (insert- first, insert- last, insert- any, delete- first, delete- last, delete- any, sort list, reverse list & search) of singly linked list.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;
struct Node* insertFirst(struct Node* head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}
struct Node* insertLast(struct Node* head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;    
    if (head == NULL) {
        return newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
struct Node* insertAny(struct Node* head, int value, int position) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position doesn't exist.\n");
        free(newNode);
        return NULL;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
}
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted.\n");
    return head;
}
struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        printf("Last node deleted.\n");
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted.\n");
    return head;
}
struct Node* deleteAny(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (position == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Node at position %d deleted.\n", position);
        return head;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
    } else {
        struct Node *delNode = temp->next;
        temp->next = delNode->next;
        free(delNode);
        printf("Node at position %d deleted.\n", position);
    }
    return head;
}
struct Node* sortList(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if ((i->data) > (j->data)) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int search(struct Node* head, int value) {
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}
void display(struct Node* head) {
    struct Node *temp = head;
    printf("Linked list: \n");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int isPositionValid(struct Node* head, int position) {
    if (position <= 0) {
        return 0;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    return temp != NULL || position == 1;
}
int main() {
    struct Node *head = NULL;
    int ch, value, position;
    while (1) {
        printf("\n1. Insert- first\n2. Insert- last\n3. Insert- any\n4. Delete- first\n5. Delete- last\n6. Delete- any\n7. Sort List\n8. Reverse List\n9. Search\n10. Display\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            head = insertFirst(head, value);
            printf("Inserted %d.\n", value);
            break;
        case 2:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &value);
            head = insertLast(head, value);
            printf("Inserted %d.\n", value);
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
            struct Node* result = insertAny(head, value, position);
            if (result != NULL) {
                head = result;
                printf("Inserted %d.\n", value);
            }
            break;
        case 4:
            head = deleteFirst(head);
            break;
        case 5:
            head = deleteLast(head);
            break;
        case 6:
            printf("Enter the position to delete the element: ");
            scanf("%d", &position);
            head = deleteAny(head, position);
            break;
        case 7:
            head = sortList(head);
            printf("List has been sorted.\n");
            display(head);
            break;
        case 8:
            head = reverseList(head);
            printf("List has been reversed.\n");
            display(head);
            break;
        case 9:
            printf("Enter the element to search: ");
            scanf("%d", &value);
            position = search(head,value);
            if (position != 1) {
                printf("Element %d is found at position %d.\n", value, position);
            }
            else {
                printf("Element %d is not found in the list.\n", value);
            }
            break;
        case 10:
            display(head);
            break;
        case 11:
            printf("Program exited.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
