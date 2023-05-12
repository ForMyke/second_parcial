#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

struct Pedido {
    int id;
    float monto;
    char cliente[50];
};

struct Node {
    struct Pedido value;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, struct Pedido item) {
    struct Node *node = malloc(sizeof(struct Node));
    node->value = item;
    node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
}

struct Pedido dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        struct Pedido item;
        item.id = -1;
        printf("La cola esta vacia\n");
        return item;
    }

    struct Node *node = queue->front;
    struct Pedido item = node->value;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(node);
    return item;
}

int isEmpty(struct Queue *queue) {
    return (queue == NULL || queue->front == NULL);
}

void show(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("NULL\n");
    } else {
        struct Node *node = queue->front;
        while (node != NULL) {
            printf("%d -> ", node->value.id);
            node = node->next;
        }
        printf("NULL\n");
    }
}








int main (){
}


