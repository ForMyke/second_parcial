#include "priority.h"
int main() {
    srand(time(NULL)); // Inicializar la semilla para generar números aleatorios
    generar_documentos_aleatorios(); // Generar 50 documentos aleatorios y agregarlos a la cola
    mostrar();

    printf("\nImprimiendo los documentos en orden de prioridad:\n");
    while (size > 0) {
        printf("%s\n", desencolar().nombre);
    }

    destruir();

    return 0;
}
