#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  Node* next;
};

struct Queue {
  Node* front;
  Node* rear;
};

void init_queue(Queue* q) {
  q->front = NULL;
  q->rear = NULL;
}

void enqueue(Queue* q, int val) {
  Node* node = (Node*)malloc(sizeof(Node));
  
  if (node == NULL) {
    printf("ERROR: Heap is full\n");
    exit(1);
  }
  
  node->next = NULL;

  if (q->front == NULL) {
    q->front = node;
    q->rear = node;
  } else {
    q->rear->next = node;
    q->rear = q->rear->next;
  }
}

void dequeue(Queue* q) {
  Node* tmp = q->front;
  
  if (tmp == NULL) {
    printf("ERROR: q is empty\n");
    exit(1);
  }

  q->front = q->front->next;
  free(tmp);

  if (q->front == NULL) {
    q->rear = NULL;
  }
}

Node* front(Queue* q) {
  return q->front;
}

int empty(Queue* q) {
  return q->front == NULL;
}

int main() {
  Queue q;

  init_queue(&q);

  for (int i = 0; i < 5; ++i) {
    enqueue(q, i);
  }

  for (int i = 0; i < 5; ++i) {
    printf("val = %d", front(q)->val);
    dequeue(q);
  }

  printf("It is empty? = %d", empty(q));

  return 0;
}
