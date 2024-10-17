
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void push(struct Node** top, int data);
int pop(struct Node** top);
int peek(struct Node* top);
void display(struct Node* top);
int isEmpty(struct Node* top);

int main() {
    struct Node* top = NULL;  // Stack is initially empty
    int choice, value;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                printf("Value %d pushed onto stack.\n", value);
                break;

            case 2:
                if (!isEmpty(top)) {
                    value = pop(&top);
                    printf("Popped value: %d\n", value);
                } else {
                    printf("Stack is empty!\n");
                }
                break;

            case 3:
                if (!isEmpty(top)) {
                    printf("Top value: %d\n", peek(top));
                } else {
                    printf("Stack is empty!\n");
                }
                break;

            case 4:
                display(top);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = (*top)->data;
    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    return value;
}

// Function to peek at the top element of the stack
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to display the stack elements
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
