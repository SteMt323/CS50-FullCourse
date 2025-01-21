#include <stdio.h>
#include <stdlib.h>  // Incluir stdlib.h para usar malloc

int main() {
    int *ptr;  // Declaración de un puntero a entero

    // Asignar memoria para 10 enteros
    ptr = (int *)malloc(10 * sizeof(int));

    // Verificar si malloc devolvió NULL (error de asignación)
    if (ptr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Usar la memoria asignada
    for (int i = 0; i < 10; i++) {
        ptr[i] = i * 2;  // Asignar valores al array
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }

    // Liberar la memoria asignada
    free(ptr);

    return 0;
}
