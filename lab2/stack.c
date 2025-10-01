#include <stdio.h>
#include <stdlib.h>

typedef void (*Func)(int);

typedef struct {
    Func *arr;
    int top;
    int capacity;
} Stack;

void init(Stack *s, int capacity) {
    s->arr = (Func *)malloc(capacity * sizeof(Func));
    if (!s->arr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = capacity;
}

int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == s->capacity - 1; }

void resize(Stack *s) {
    int new_capacity = s->capacity * 2;
    Func *new_arr = (Func *)realloc(s->arr, new_capacity * sizeof(Func));
    if (!new_arr) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    s->arr = new_arr;
    s->capacity = new_capacity;
}

void push(Stack *s, Func f) {
    if (isFull(s)) resize(s);
    s->arr[++s->top] = f;
    printf("Function pushed\n");
}

Func pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return NULL;
    }
    return s->arr[s->top--];
}

Func peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack empty!\n");
        return NULL;
    }
    return s->arr[s->top];
}

void freeStack(Stack *s) {
    free(s->arr);
    s->arr = NULL;
    s->top = -1;
    s->capacity = 0;
}

void hello(int x) {
    printf("Hello %d!\n", x);
}

void square(int x) {
    printf("%d squared = %d\n", x, x*x);
}

void bye(int x) {
    printf("Goodbye %d!\n", x);
}

int main() {
    Stack s;
    init(&s, 2);

    push(&s, hello);
    push(&s, square);
    push(&s, bye);

    Func f = peek(&s);
    if (f) f(5);

    while (!isEmpty(&s)) {
        Func g = pop(&s);
        g(3);  // call with argument
    }

    freeStack(&s);
    return 0;
}

