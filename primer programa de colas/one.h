#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estructura para los pedidos
struct Pedido {
    char cliente[50];
    int cantidad;
    float costo;
};

// Declaración de funciones
void enqueue(struct Pedido item);
struct Pedido dequeue();
int isEmpty();
void show();

// Variables globales
struct Pedido queue[100];
int inicio = -1, final = -1;
int total_camisas = 100;
float precio_camisa = 10.0;

// Función para sacar un pedido de la cola
void enqueue(struct Pedido item) {
    if (final == 99) {
        printf("Error: la cola esta llena.\n");
    } else {
        if (inicio == -1) {
            inicio = 0;
        }
        final++;
        queue[final] = item;
        queue[final].costo = item.cantidad * 20.0; // Precio por camisa es 20
    }
}
// Función para sacar un pedido de la cola
struct Pedido dequeue() {
    struct Pedido item;
    if (isEmpty()) {
        printf("Error: la cola esta vacia.\n");
        item.cantidad = -1;
        return item;
    } else {
        item = queue[inicio];
        inicio++;
        if (inicio> final) {
            inicio = final = -1;
        }
        return item;
    }
}

// Función para verificar si la cola está vacía
int isEmpty() {
    if (inicio==-1 || inicio > final) {
        return 1;
    } else {
        return 0;
    }
}
