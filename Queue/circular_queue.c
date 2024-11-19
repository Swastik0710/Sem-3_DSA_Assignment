//Write a program to implement circular queue data structure using array.
#include<stdio.h>
#include<stdlib.h>
#define MAX 15
int queue[MAX], front = -1, rear = -1;
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full.\n");
    }
    else {
        if (front == -1){
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("Enqueued %d.\n", value);
    }
}
void dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Dequeued %d.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue element(s) are: \n");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[i]);
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
