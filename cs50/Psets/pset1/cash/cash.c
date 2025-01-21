#include <stdio.h>
#include <cs50.h>

int calculo25(int credito);
int calculo10(int credito);
int calculo5(int credito);
int calculo1(int credito);

int main(){
    int credito;
    int coins = 0;
    credito = get_int("Ingrese el credito a devolver: ");

    //Calculo de monedas de 25
    coins += calculo25(credito);
    credito = credito - calculo25(credito) * 25;

    coins += calculo10(credito);
    credito = credito - calculo10(credito) * 10;

    coins += calculo5(credito);
    credito = credito - calculo5(credito) * 5;

    coins += calculo1(credito);
    credito = credito - calculo1(credito) * 1;

    printf("%d\n", coins);
}

int calculo25(int credito){
    int V;
    V = credito / 25;
    return V;

}

int calculo10(int credito){
    int D;
    D = credito / 10;
    return D;
}

int calculo5(int credito){
    int C;
    C = credito / 5;
    return C;
}

int calculo1(int credito){
    int U;
    U = credito / 1;
    return U;
}
