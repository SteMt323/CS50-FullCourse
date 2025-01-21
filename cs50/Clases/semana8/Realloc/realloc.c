#include <stdio.h> // Incluye la biblioteca estándar para operaciones de entrada/salida, aunque no se usa en este código
#include <stdlib.h> // Incluye la biblioteca estándar para funciones de asignación/liberación de memoria

int main(void)
{
    // Asigna memoria para un arreglo de 3 enteros
    int *list = malloc(3 * sizeof(int));

    // Verifica si la asignación de memoria fue exitosa
    if (list == NULL)
        return 1; // Si la asignación falla, termina el programa con un código de error 1

    // Inicializa los elementos del arreglo
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Reasigna memoria para el arreglo, ampliando el tamaño a 4 enteros
    int *tmp = realloc(list, 4 * sizeof(int));

    // Verifica si la reasignación de memoria fue exitosa
    if (tmp == NULL)
    {
        // Si la reasignación falla, libera la memoria inicialmente asignada y termina el programa
        free(list);
        return 1; // Termina el programa con un código de error 1
    }

    // Agrega un nuevo elemento al arreglo, que ahora tiene 4 enteros
    tmp[3] = 4;

    // Actualiza el puntero list para que apunte a la nueva ubicación de memoria
    list = tmp;

    // Libera la memoria asignada antes de terminar el programa
    free(list);
}
