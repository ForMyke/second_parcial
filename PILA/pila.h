#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Para la función isdigit()
#include <string.h>
#define MAX_SIZE 100 // Tamaño máximo de la pila

char infija[MAX_SIZE], posfija[MAX_SIZE];
int stack[MAX_SIZE];
int top = -1;

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void push(int item)
{
    if (top >= MAX_SIZE-1)
    {
        printf("No\n");
        exit(1);
    }
    stack[++top] = item;
}



int pop()
{
    if (top == -1)
    {
        printf("No\n");
        exit(1);
    }
    return stack[top--];
}




int peek()
{
    if (top == -1)
    {
        printf("No\n");
        exit(1);
    }
    return stack[top];
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}


void infija_a_posfija()
{
    int i, j;
    char item;
    push('(');
    strcat(infija, ")");
    i = 0;
    j = 0;
    item = infija[i];
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            posfija[j] = item;
            j++;
        }
        else if (isOperator(item) == 1)
        {
            if (precedence(item) > precedence(peek()))
            {
                push(item);
            }
            else
            {
                while (precedence(item) <= precedence(peek()))
                {
                    posfija[j] = pop();
                    j++;
                }
                push(item);
            }
        }
        else if (item == ')')
        {
            while (peek() != '(')
            {
                posfija[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            printf("Invalido\n");
            exit(1);
        }
        i++;
        item = infija[i];
    }
    posfija[j] = '\0';
}
