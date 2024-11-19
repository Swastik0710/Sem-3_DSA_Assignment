//Write a program to reverse a string using stack.
#include<stdio.h>
#include<string.h>
#define MAX 50
char STACK[MAX];
int top = -1;
void PUSH(char c) {
  if (top < MAX-1) {
    STACK[++top] = c;
  }
}
char POP() {
  if (top >= 0) {
    return STACK[top--];
  }
}
int main() {
  char str[MAX];
  printf("Enter a string: ");
  gets(str);
  for (int i = 0; i < strlen(str); i++) {
    PUSH(str[i]);
  }
  printf("Reversed string: ");
  while (top >= 0) {
    printf("%c", POP());
  }
  printf("\n");
  return 0;
}
