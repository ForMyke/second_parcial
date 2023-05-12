#include "pila.h"

int isOperator(char c);

void push(int item);

int pop();

int peek();

int precedence(char op);

void infija_a_posfija();

int main()
{
    printf("Inserta la expresion infija: ");
    scanf("%s", infija);
    infija_a_posfija();
    printf("Expresion posfija: %s\n", posfija);
    return 0;
}
