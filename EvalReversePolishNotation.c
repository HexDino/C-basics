#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int data) {
    if(top >= MAX - 1) {
        exit(1);
    }
    stack[++top] = data;
}

int pop() {
    if(top < 0) {
        exit(1);
    }
    return stack[top--];
}

int main()
{
    char c;
    int a, b;
    while(scanf("%c", &c) != EOF && c != '\n' && c != '\r') {
        if(c >= '0' && c <= '9') {
            push(c - '0');
        } else if(c == ' ' || c == '\t') {
            continue;
        } else {
            if(top < 1) {
                exit(1);
            }
            b = pop();
            a = pop();
            switch(c) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    if(b == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(a / b);
                    break;
                default:
                    printf("Invalid operator: %c\n", c);
                    exit(1);
            }
        }
    }
    if(top != 0) {
        exit(1);
    }
    printf("%d\n", pop());
    return 0;
}
