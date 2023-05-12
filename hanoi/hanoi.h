#include <stdio.h>
#include <stdlib.h>

typedef struct node { //definimos la estrucutura

    int dato;
    struct node *siguiente;
} Nodo;
void push(Nodo **top, int dato) { //creamos la funcion de push la cual no devolvera ningun datos
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));//creamos espacio de memoria
    nuevoNodo->dato = dato; //asignamos el nuevo nodo al actual
    nuevoNodo->siguiente = *top;// ahora al tope de este que sera el siguiente 
    *top = nuevoNodo; //finalmete el tope
}

int pop(Nodo **top) {
    if (*top == NULL) { //verificamos si esta vacia 
        printf("No se puede extraer ningun dato\n");
        return -1;
    }
    Nodo *temp = *top; //temporal apunta al dato en la cima
    int dato = temp->dato; //guardamos eso en dato
    *top = temp->siguiente; //asignamos a top el siguiente dato
    free(temp); //liberamos el espacio de memoria
    return dato; //regresamos el dato
}

void printTorres(Nodo *fuente, Nodo *dest, Nodo *aux) { //pasamos las 3 torres 
	int i;
    Nodo *torres[3] = {fuente, aux, dest}; // las definimos
    char torreNombre[3] = {'A', 'B', 'C'}; // asignamos los valores a las 3 torres
    for ( i = 0; i < 3; i++) { // iteramos sobre cada torre
        printf("Torre %c: ", torreNombre[i]);
        Nodo *actual= torres[i];//definimos el puntero actual 
        while (actual != NULL) {//imprimimso el dato que contiene actual
            printf("%d ", actual->dato);
            actual = actual->siguiente;
        }
        printf("\n");//separamos las torres
    }
    printf("\n");
}

void mover(int disco, char fuente, char dest, char aux) { //imprimimos el mensaje del cambio
    printf("Mover disco %d de la torre %c a la torre %c\n", disco, fuente, dest);
}

void hanoi(int n, Nodo **fuente, Nodo **dest, Nodo **aux) {// pasamos el tamaño de la torre y las 3 torres
    if (n == 1) { //si es igual a 1 moverlo de fuente a destino y salir 
        push(dest, pop(fuente));
        printTorres(*fuente, *dest, *aux);
        mover(1, 'A', 'C', 'B');
        return;
    }
    hanoi(n-1, fuente, aux, dest);// si es mayor que 1 se llamaba recursivamente 
    push(dest, pop(fuente));
    printTorres(*fuente, *dest, *aux);
    mover(n, 'A', 'C', 'B');
    hanoi(n-1, aux, dest, fuente);
}

