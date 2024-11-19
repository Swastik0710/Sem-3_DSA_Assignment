//Write a program to convert infix expression to post-fix expression.
#include<stdio.h>
#include<ctype.h>
#define MAX 50
char STACK[MAX];
int top = -1;
void PUSH(char x) {
  STACK[++top] = x;
}
char POP() {
  if (top == -1) {
    return -1;
  }
  else {
    return STACK[top--];
  }
}
int precedence(char x) {
  if (x == '(') {
    return 0;
  }
  else if (x == '+' || x == '-') {
    return 1;
  }
  else if (x == '*' || x == '/') {
    return 2;
  }
}
int infixTopostfix(char infix[MAX], char postfix[MAX]) {
  char temp, x;
  int i = 0, j = 0;
  while (infix[i] != '\0') {
    temp = infix[i];
    if (isalnum(temp)) {
      postfix[j++] = temp;
    }
    else if (temp == '(') {
      PUSH(temp);
    }
    else if (temp == ')') {
      while ((x = POP()) != '(') {
        postfix[j++] = x;
      }
    }
    else {
      while (precedence(STACK[top]) >= precedence(temp)) {
        postfix[j++] = POP();
      }
      PUSH(temp);
    }
    i++;
  }
  while (top != -1) {
    postfix[j++] = POP();
  }
    postfix[j] = '\0';
}
int main() {
  char infix[MAX], postfix[MAX];
  printf("Enter the infix expression: ");
  scanf("%s", infix);
  printf("The infix expression is %s.\n",infix);
  infixTopostfix(infix, postfix);
  printf("The postfix expression is %s.\n",postfix);
  return 0;
}
