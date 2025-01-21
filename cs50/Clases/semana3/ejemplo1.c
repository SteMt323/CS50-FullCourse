#include <stdio.h>
#include <string.h>


int main() {
    char name[100];
    printf("Ingresa tu nombre completo: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("El nombre ingresado es: %s\n", name);
    return 0;
}
