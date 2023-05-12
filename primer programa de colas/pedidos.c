#include "one.h"
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

