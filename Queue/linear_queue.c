//Write a program to implement linear queue data structure using array.
#include<stdio.h>
#include<stdlib.h>
#define MAX 15
int queue[MAX], front = -1, rear = -1;
void enqueue(int a) {
  if (rear == MAX-1) {
    printf("Queue overflow.\n");
  }
  else {
    if (front = -1) {
      front = 0;
    }
    rear++;
    queue[rear] = a;
    printf("Enqueued %d.\n", a);
  }
}
void dequeue() {
  if (front == -1 || front > rear) {
    printf("Queue underflow.\n");
  }
  else {
    printf("Dequeued %d.\n",queue[front]);
    front++;
  }
}
void display() {
  if (front == -1) {
    printf("Queue is empty.\n");
  }
  else {
    printf("The element(s) of the queue are: \n");
    for(int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  }
}
int main() {
  int ch,a;
  while(1) {
    printf("\nQueue Operations: \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch) {
      case 1:
        printf("Enter the value to enqueue: ");
        scanf("%d", &a);
        enqueue(a);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      default:
        printf("\nInvalid choice! Please try again.");
    }
  }
  return 0;
}
