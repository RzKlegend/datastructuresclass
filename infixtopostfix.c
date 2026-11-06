#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        return '\0';
    } else {
        return stack[top--];
    }
}

int precedence(char symbol) {
    if (symbol == '^') return 3;
    else if (symbol == '*' || symbol == '/') return 2;
    else if (symbol == '+' || symbol == '-') return 1;
    else return 0;
}

int isOperator(char symbol) {
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^') {
        return 1;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char item, x;
    
    push('(');
    strcat(infix, ")");
    
    item = infix[i];
    
    while (item != '\0') {
        if (item == '(') {
            push(item);
        }
        else if (isdigit(item) || isalpha(item)) {
            postfix[j] = item;
            j++;
        }
        else if (isOperator(item) == 1) {
            x = pop();
            while (isOperator(x) == 1 && precedence(x) >= precedence(item)) {
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix[j] = x;
                j++;
                x = pop();
            }
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter Infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    return 0;
}