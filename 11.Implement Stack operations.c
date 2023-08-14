#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;
void initializeStack(Stack* stack) {
    stack->top = -1;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element.\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element.\n");
        return -1; 
    }
    int poppedValue = stack->data[stack->top];
    stack->top--;
    return poppedValue;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; 
    }
    return stack->data[stack->top];
}
int main() {
    Stack stack;
    initializeStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Peek: %d\n", peek(&stack)); 
    int poppedElement = pop(&stack);
    printf("Popped: %d\n", poppedElement); 
	printf("Peek: %d\n", peek(&stack)); 
    return 0;
}
