#include <stdio.h>

int main(){
    int a;
    printf("Introduzca un numero: ");
    scanf("%d", &a);

    if(a<18){
        printf("Eres menor de edad");
    }
    else if (a>=18 && a<60){
        printf("Eres mayor de edad");
    }
    else{
        printf("Eres jubilado");
    }
}
