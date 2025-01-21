#include <stdio.h>

//arrays
int main(){
    //Arreglos unidimensionales
    /*int myNumbers[] = {25, 50, 75, 100};
    int i;

    for (i = 0; i < 4; i++) {
        printf("%d\n", myNumbers[i]);
    }*/

   //__________________________________________________________________

   //Arreglos bidimensionales
    /*int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

    printf("%d\n", matrix[1][2]);*/

    int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

    int i, j;
    //El primer bucle for recorre las filas
    for (i = 0; i < 2; i++) {
        //El segundo bucle recorre las columnas
        for (j = 0; j < 3; j++) {
            printf("%d\n", matrix[i][j]);
        }
    }
}
