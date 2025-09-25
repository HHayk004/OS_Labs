#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;      // dynamic array
    int top;       // index of top element
    int capacity;  // current allocated size
} Stack;

// Initialize stack with a given capacity
void init(Stack *s, int capacity) {
    s->arr = (int *)malloc(capacity * sizeof(int));
    if (!s->arr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = capacity;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

// Resize stack when full (double capacity)
void resize(Stack *s) {
    int new_capacity = s->capacity * 2;
    int *new_arr = (int *)realloc(s->arr, new_capacity * sizeof(int));
    if (!new_arr) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    s->arr = new_arr;
    s->capacity = new_capacity;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        resize(s);
    }
    s->arr[++s->top] = value;
    printf("%d pushed\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

int size(Stack *s) {
    return s->top + 1;
}

void clear(Stack *s) {
    s->top = -1;
    printf("Stack cleared!\n");
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void freeStack(Stack *s) {
    free(s->arr);
    s->arr = NULL;
    s->top = -1;
    s->capacity = 0;
}

int main() {
    Stack s;
    init(&s, 5);  // start with capacity 5

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);  // will trigger resize

    display(&s);

    printf("Top = %d\n", peek(&s));
    printf("Size = %d\n", size(&s));

    printf("Popped = %d\n", pop(&s));
    printf("Popped = %d\n", pop(&s));

    display(&s);

    clear(&s);
    display(&s);

    freeStack(&s); // free memory at end
    return 0;
}

