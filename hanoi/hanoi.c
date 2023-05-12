#include "hanoi.h"

void push(Nodo **top, int dato);
int pop(Nodo **top);
void printTorres(Nodo *fuente, Nodo *dest, Nodo *aux);
void mover(int disco, char fuente, char dest, char aux);
void hanoi(int n, Nodo **fuente, Nodo **dest, Nodo **aux);




int main() {
    int i,j,discos[] = {5, 7, 10}; // asignamos el tamaño de los discos
    int numDiscos = sizeof(discos) / sizeof(discos[0]); // determinamos cuantos discos hay en esa variable 
    for ( i = 0; i < numDiscos; i++) { // un bucle for para vaciar las 3 pilas y asignar a n el valor de los discos
        int n = discos[i]; 
        Nodo *fuente = NULL;
        Nodo *dest = NULL;
        Nodo *aux = NULL;
        for (j = n; j > 0; j--) { // añadimos a las pilas el tamaño de los discos 
            push(&fuente, j);
        }
        printf("Solución para %d discos:\n", n);
        printTorres(fuente, dest, aux); // imprimimos el estados inicial de las torres
        hanoi(n, &fuente, &dest, &aux); // llamos a la funcion hanoi para resolver el problema 
    }
    return 0;
}
