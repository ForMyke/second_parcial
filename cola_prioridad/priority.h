#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_HEAP_SIZE 100
#define MAX_NOMBRE 50

// Estructura de un documento
typedef struct {
    char nombre[MAX_NOMBRE];
    int prioridad;
} Documento;

// Estructura de un nodo de la cola
typedef struct nodo {
    Documento documento;
    struct nodo* siguiente;
} Nodo;


// Variables globales
Nodo* frente = NULL;
Nodo* final = NULL;
Documento heap[MAX_HEAP_SIZE];

int size = 0;

// Funciones de la cola
void encolar(char *nombre, int prioridad);
Documento desencolar();
void destruir();
void mostrar();
void swap(Documento *x, Documento *y) {
    Documento temp = *x;
    *x = *y;
    *y = temp;
}

void encolar(char *nombre, int prioridad) {
    if (size >= 	MAX_HEAP_SIZE) {
        printf("Desbordamiento del heap\n");
        return;
    }

    Documento *doc = malloc(sizeof(Documento));
strcpy(doc->nombre, nombre);
doc->prioridad = prioridad;
heap[size++] = *doc;
    int i = size - 1;
    while (i > 0 && heap[i].prioridad > heap[(i - 1) / 2].prioridad) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Documento desencolar() {
    if (size <= 0) {
        printf("Subdesbordamiento del heap\n");
        return (Documento){NULL, -1};
    }

    Documento root = heap[0];
    heap[0] = heap[--size];
    int i = 0, j;
    while (2 * i + 1 < size) {
        j = 2 * i + 1;
        if (j + 1 < size && heap[j + 1].prioridad > heap[j].prioridad) {
            j++;
        }
        if (heap[i].prioridad >= heap[j].prioridad) {
            break;
        }
        swap(&heap[i], &heap[j]);
        i = j;
    }
    return root;
}
void mostrar() {
    int i;
    printf("Documentos en la cola:\n");
    for (i = 0; i < size; i++) {
        printf("%s (prioridad %d)\n", heap[i].nombre, heap[i].prioridad);
    }
}

void destruir() {
    while (size > 0) {
        free(heap[--size].nombre);
    }
}
// Función para generar un documento aleatorio
Documento generar_documento_aleatorio() {
    Documento documento;
    char nombre[MAX_NOMBRE];
    int r = rand() % 3;
    if (r == 0) {
        sprintf(nombre, "Documento (direccion) %d", rand() % 100);
        documento.prioridad = 3;
    } else if (r == 1) {
        sprintf(nombre, "Documento (docente) %d", rand() % 100);
        documento.prioridad = 2;
    } else {
        sprintf(nombre, "Documento (estudiante) %d", rand() % 100);
        documento.prioridad = 1;
    }
    strcpy(documento.nombre, nombre);
    return documento;
}

// Función para generar 50 documentos aleatorios y agregarlos a la cola de prioridad
void generar_documentos_aleatorios() {
    int i;
    for (i = 0; i < 50; i++) {
        Documento documento = generar_documento_aleatorio();
        encolar(documento.nombre, documento.prioridad);
    }
}


