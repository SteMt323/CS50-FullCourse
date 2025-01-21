#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    FILE *archis = NULL;
    BYTE buffer[512];
    int i = 0;
    char tittle[10];

//Comprobamos si el usuario ingreso solo un argumento
    if(argc != 2){
        printf("Usage: ./recover\n");
        return 1;
    }
//Abrimos el archivo archi
    FILE *archi = fopen(argv[1],"r");
    if (archi == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }
//Mientras se lee el contenido se ejecuta su bloque
    while(fread(buffer,sizeof(BYTE),512,archi) == 512){
        //Comprobando si tiene cabecera o header jpeg
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff){
            //Escribimos una cadena que se guarda en tittle, teniendo
            //un formato 000.jpg, donde los tres numeros puden variar en dependencia
            //del incremento del contador, osea que puede ser 001, 010, 100
            sprintf(tittle, "%03i.jpg", i++);
            archis = fopen(tittle,"w");
            if (archis == NULL){
            printf("Error al abrir el archivo\n");
            return 1;
            }
        }
        //Y aqui simplemente escribo el contenido
    if(archis != NULL){
        fwrite(buffer,sizeof(BYTE),512,archis);
    }
    }
    //Cerramos archis para que se ejecute el while nuevamente sin problemas
    if(archi != NULL){
        fclose(archis);
    }

    fclose(archi);



    return 0;
}
//pero ni mi ex me hizo llorar asi
//me rindo wey
//Pero no uso malloc apa :(, tengo que usar?

//Su programa, si se usa malloc, no debe perder memoria.

