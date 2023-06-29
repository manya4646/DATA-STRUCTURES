#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}

bool isWellParenthesized(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (top == -1 || !isMatchingPair(pop(), expr[i])) {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter expression: ");
    scanf("%s", expr);
    if (isWellParenthesized(expr)) {
        printf("Expression is well-parenthesized\n");
    } else {
        printf("Expression is not well-parenthesized\n");
    }
    return 0;
}