#include <stdio.h>
#include <stdlib.h>

int top = -1;
int *a;
int stack_size;

void push();
void pop();
void display();

int main() {
    int choice;

    // Prompting user for stack size
    printf("Enter the stack size: ");
    scanf("%d", &stack_size);

    // Allocating memory for the stack
    a = (int *)malloc(stack_size * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;  // Exit if memory allocation fails
    }

    while (1) {
        printf("\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: push();
            break;
        case 2: pop();
            break;
        case 3: display();
            break;
        case 4:
            free(a);  // Freeing allocated memory
            exit(0);
        default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void push() {
    int x;
    if (top == stack_size - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter the element: ");
        scanf("%d", &x);
        top = top + 1;
        a[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Popped element: %d\n", a[top]);
        top = top - 1;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Elements in the stack:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", a[i]);
        }
    }
}
