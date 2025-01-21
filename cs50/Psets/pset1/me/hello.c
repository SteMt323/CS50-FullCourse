#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(){
    /*Realizare dos maneras de como hacer este código, una con la biblioteca
    brindada por CS50, y otra sin ella.*/

/*
    char name[50];
    printf("Ingresa tu nombre: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Hello, %s\n", name);
*/

    string name = get_string("Ingrese su nombre: ");
    printf("Hello, %s\n", name);
}
