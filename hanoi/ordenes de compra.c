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

int main() {
    int continuar = 1;
    while (continuar) {
        // Preguntar si quiere comprar camisas
        printf("Desea comprar camisas? (1 para SI, 0 para NO): ");
        int respuesta;
        scanf("%d", &respuesta);
        
        if (respuesta) {
            // Pedir el nombre del cliente
            char nombre[50];
            printf("Ingrese su nombre: ");
            scanf("%s", nombre);
            
            // Pedir la cantidad de camisas a comprar
            printf("Ingrese la cantidad de camisas que desea comprar: ");
            int cantidad;
            scanf("%d", &cantidad);
            
            // Verificar si hay suficientes camisas
            if (cantidad <= total_camisas) {
                // Agregar el pedido a la cola
                struct Pedido nuevo_pedido;
                strcpy(nuevo_pedido.cliente, nombre);
                nuevo_pedido.cantidad = cantidad;
                nuevo_pedido.costo = cantidad * precio_camisa; // Calcula el costo del pedido
                enqueue(nuevo_pedido);
                
                // Actualizar el total de camisas
                total_camisas -= cantidad;
            } else {
                printf("Lo siento, no tenemos suficientes camisas.\n");
            }
        } else {
            continuar = 0;
        }
    }
    system("PAUSE()");
    // Mostrar la lista de pedidos
    printf("Lista de pedidos:\n");
    while (!isEmpty()) {
        struct Pedido pedido_actual = dequeue();
        printf("Cliente: %s - Cantidad: %d - Costo: %.2f\n", pedido_actual.cliente, pedido_actual.cantidad, pedido_actual.costo);
    }
    
    // Generar el número aleatorio de la factura
    srand(time(NULL));
    int numero_factura = rand() % 10000;
    printf("Factura generada con numero: %d\n", numero_factura);

    
    return 0;
}

// Función para agregar un pedido a la cola
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

