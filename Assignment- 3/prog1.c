//Write a program using array to implement stack operations using switch case (PUSH, POP and DISPLAY).
#include<stdio.h>
#include<stdlib.h>
#define MAX 15
int top = -1, STACK[MAX], elem;
void PUSH(int elem) {
  if (top == MAX-1) {
    printf("The stack is full.");
  }
  else {
    STACK[++top] = elem;
    printf("Pushed %d onto the stack.\n", elem);
  }
}
void POP() {
  if (top == -1) {
    printf("The stack is empty.");
  }
  else {
    printf("Popped %d from the stack.\n", STACK[top--]);
  }
}
void DISPLAY() {
  if (top == -1) {
    printf("Stack is empty.");
  }
  else {
    printf("Stack elements are: \n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n",STACK[i]);
    }
  }
}
int main() {
  int ch,elem;
  while(1) {
    printf("Stack operations are: ");
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch) {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &elem);
            PUSH(elem);
            break;
        case 2:
            POP();
            break;
        case 3:
            DISPLAY();
            break;
        case 4:
            printf("Exiting the program.");
            exit(0);
        default:
            printf("Invalid choice! Please try again.");
    }
  }
  return 0;
}
