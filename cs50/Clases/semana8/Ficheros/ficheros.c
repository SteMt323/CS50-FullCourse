#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc; char *argv[]){
    FILE *archi = fopen(argv[1],"r");
    if (archi == NULL){
        printf("Error al abrir el archivo\n");
        return;
    }

    BYTE bytes[3];
    fread(bytes, sizeof(BYTE),3,archi);
    if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff){
        printf("Posiblemente es imagen");
        fclose(file);
    }
}
