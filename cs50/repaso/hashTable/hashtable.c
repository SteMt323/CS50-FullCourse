#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<cs50.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Nodo{
    string palabra;
    struct Nodo* siguiente;
} Nodo;

typedef struct HashTable{
    Nodo* tabla[26];
} HashTable;

void insertarPalabra(HashTable* hashTable, string palabra);
int calcularPosicion(char letra);
void buscarPalabra(HashTable* hashTable, string palabra);
int liberarHashTable(HashTable* hashTable);

int main(void)
{
    HashTable hashTable;
    for(int i = 0; i<26;i++)
    {
        hashTable.tabla[i] = NULL;
    }
    int opcion = 0;
    string palabra = malloc(51);
    do
    {
        printf("1. Ingrese una palabra\n");
        printf("2. Busque una palabra\n");
        printf("3. Salir\n");
        opcion = get_int("Digite una opcion: ");
        int DatosBorrados = 0;
        switch(opcion)
        {
            case 1:
                palabra = get_string("Digite la palabra a ingresar: ");
                insertarPalabra(&hashTable, palabra);
                break;
            case 2:
                palabra = get_string("Digite la palabra a buscar: ");
                buscarPalabra(&hashTable,palabra);
                break;
            case 3:
                printf("Estamos limpiando la memoria.....\n");
                DatosBorrados = liberarHashTable(&hashTable);
                printf("Limpiamos %d datos de la memoria\n",DatosBorrados);
                break;
            default:
                printf("Digitaste una opcion incorrecta\n");
        }
    }while(opcion !=3);
}

void insertarPalabra(HashTable* hashTable, string palabra)
{
    int posicion = calcularPosicion(palabra[0]);
    Nodo* nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->palabra = malloc(sizeof(strlen(palabra) + 1));
    strcpy(nuevoNodo->palabra,palabra);
    nuevoNodo->siguiente = hashTable->tabla[posicion];
    hashTable->tabla[posicion] = nuevoNodo;
}

int calcularPosicion(char letra)
{
    letra = tolower(letra);
    letra = letra - 97;
    return (int)letra;
}

void buscarPalabra(HashTable* hashTable, string palabra)
{
    int posicion = calcularPosicion(palabra[0]);
    Nodo* actual = hashTable->tabla[posicion];
    while(actual != NULL)
    {
        if(strcasecmp(actual->palabra,palabra)== 0)
        {
            printf("Encontramos la palabra %s en el indice %d de nuestra hash table\n",actual->palabra,posicion);
            return;
        }
        actual = actual->siguiente;
    }
    printf("No encontramos la palabra, tristito\n");
}

int liberarHashTable(HashTable* hashTable)
{
    int contador = 0;
    for(int i = 0; i < 26; i++)
    {
        Nodo* borrar = hashTable->tabla[i];
        while(borrar != NULL)
        {
            Nodo* tmp = borrar->siguiente;
            free(borrar);
            borrar = tmp;
            contador++;
        }
    }
    return contador;
}
