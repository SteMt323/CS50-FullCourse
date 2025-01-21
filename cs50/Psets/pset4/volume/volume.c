// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);


    uint8_t header[HEADER_SIZE];
    /*En este caso declaro header como un tido de dato uint8_t
    esto puede almacenar valores en el rango de 0 a 255 debido a que un solo byte
    puede representar 256 valores posibles*/

    // TODO: Copy header from input file to output file
    fread(header, sizeof(header),1,input);
    fwrite(header, sizeof(header),1,output);


    // TODO: Read samples from input file and write updated data to output file

    /*Considerando de que las secuencias de muestras estan representadas por
    enteros de 2 bytes (16 bits), e investigando acerca de la librería stdint.h
    la mejor forma que considero útil para leer cada sample es el tipo de dato
    "int16_t" o "uint16_t", sin embargo en el caso de que existan valores con signos
    la mejor opción a usar, debería de ser "int16_t".
    */

    int16_t samples;
    while(fread(&samples, sizeof(samples),1,input)){
        samples = samples * factor;

        fwrite(&samples, sizeof(samples),1,output);
    }


    // Close files
    fclose(input);
    fclose(output);
}
