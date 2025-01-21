#include <stdio.h>
#include <cs50.h>

int main(void){
    /*
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    printf("%p\n",s);
    printf("%p\n",t);
            //Comparando las cadenas de caracteres, tambien podemos ocupar la funcion strcmp para comparar las cadenas
    if(*s == *t){
        printf("Same\n");
    }else{
        printf("Different\n");
    }


            //Comparando las direcciones de memoria
    if(s == t){
        printf("Same\n");
    }else{
        printf("Different\n");
    }
    */


//___________________________________________________________________________
    int a = 5;
    int *p;        // Declaración de un puntero a un entero
    p = &a;        // p apunta a la dirección de memoria de a

    printf("Valor de a: %d\n", a);       // Imprime 5
    printf("Dirección de a: %p\n", p);   // Imprime la dirección de memoria de a
    printf("Valor a través de p: %d\n", *p); // Imprime 5, accediendo a través del puntero

    *p = 10;      // Modifica el valor de a a través del puntero
    printf("Nuevo valor de a: %d\n", a);  // Imprime 10

    return 0;
}

