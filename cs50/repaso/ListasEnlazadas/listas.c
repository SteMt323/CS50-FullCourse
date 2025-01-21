#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo en la lista enlazada
typedef struct nodo
{
    int valor;
    struct nodo *siguiente;
} nodo;

// Prototipos de las funciones
void insertarAlFinal(nodo **cabeza, int valor); // Se cambia a puntero a puntero
void freeList(nodo *cabeza);
void imprimirLista(nodo *cabeza);
nodo *crearNodo(int valor); // Se usa 'nodo' en lugar de 'struct nodo'

int main()
{
    nodo *cabeza = NULL; // Definición de la cabeza de la lista enlazada

    insertarAlFinal(&cabeza, 10); // Se pasa un puntero a cabeza
    insertarAlFinal(&cabeza, 20);
    insertarAlFinal(&cabeza, 30);

    printf("Lista enlazada: ");
    imprimirLista(cabeza);

    freeList(cabeza);
    return 0;
}

// Función para crear un nuevo nodo
nodo *crearNodo(int valor)
{
    nodo *nuevoNodo = (nodo *) malloc(sizeof(nodo));
    if (nuevoNodo == NULL)
    {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(1); // Termina el programa si no se puede asignar memoria
    }

    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final de la lista
void insertarAlFinal(nodo **cabeza, int valor)
{
    nodo *nuevoNodo = crearNodo(valor);
    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
    }
    else
    {
        nodo *temp = *cabeza;
        while (temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista enlazada
void imprimirLista(nodo *cabeza)
{
    nodo *actual = cabeza;

    while (actual != NULL)
    {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }

    printf("NULL\n");
}

// Función para liberar la memoria de la lista enlazada
void freeList(nodo *cabeza)
{
    while (cabeza != NULL)
    {
        nodo *tmp = cabeza->siguiente;
        free(cabeza);
        cabeza = tmp;
    }
}
