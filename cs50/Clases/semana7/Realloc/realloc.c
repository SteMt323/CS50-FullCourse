#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int size = 5;

    // Asignar memoria para 5 enteros
    ptr = (int *)malloc(size * sizeof(int));

    if (ptr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Inicializar los valores del array
    for (int i = 0; i < size; i++) {
        ptr[i] = i + 1;
    }

    // Mostrar los valores actuales
    printf("Valores originales:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Aumentar el tamaño del bloque de memoria a 10 enteros
    size = 10;
    ptr = (int *)realloc(ptr, size * sizeof(int));

    if (ptr == NULL) {
        printf("Error al reasignar memoria.\n");
        return 1;
    }

    // Inicializar los nuevos elementos del array
    for (int i = 5; i < size; i++) {
        ptr[i] = i + 1;
    }

    // Mostrar los valores después de la reasignación
    printf("Valores después de realloc:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Liberar la memoria asignada
    free(ptr);

    return 0;
}
