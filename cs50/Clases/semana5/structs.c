#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

//struct definition
struct infoP{
    string name;
    string lastname;
    int age;
    int number;
    string country;
    string department;
};

int main(){
    struct infoP e[4];
    for(int i = 0; i < 3; i++){
        e[i].name = get_string("Ingrese su nombre: ");
        /*printf("Ingrese su nombre: ");
        fgets(e[i].name, sizeof(e[i].name),stdin);
        e[i].name[strcspn(e[i].name, "\n")] = '\0';*/

        e[i].lastname = get_string("Ingrese su apellido: ");
        /*printf("Ingrese su apellido: ");
        fgets(e[i].lastname, sizeof(e[i].lastname),stdin);
        e[i].lastname[strcspn(e[i].lastname, "\n")] = '\0';*/

        e[i].age = get_int("Ingrese su edad: ");
        /*printf("Ingrese su edad: ");
        scanf("%d",&e[i].age);
        printf("Ingrese su numero: ");
        scanf("%d",&e[i].number);*/
        e[i].number = get_int("Ingrese su numero: ");
        /*printf("Ingrese su pais de origen: ");
        fgets(e[i].country, sizeof(e[i].country),stdin);
        e[i].country[strcspn(e[i].country, "\n")] = '\0';*/
        e[i].country = get_string("Ingrese su pais de procedencia: ");
    }
    int opc;
    do{
        printf("Que usuario desea visualizar?\n");
        printf("Usuario 1\n");
        printf("Usuario 2\n");
        printf("Usuario 3\n");
        printf("Ninguno\n");
        printf("Opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                printf("Nombre: %s\n", e[0].name);
                printf("Apellido: %s\n", e[0].lastname);
                printf("Edad: %d\n", e[0].age);
                printf("Numero: %d\n", e[0].number);
                printf("Ciudad: %s\n", e[0].country);
                return 0;
            case 2:
                printf("Nombre: %s\n", e[1].name);
                printf("Apellido: %s\n", e[1].lastname);
                printf("Edad: %d\n", e[1].age);
                printf("Numero: %d\n", e[1].number);
                printf("Ciudad: %s\n", e[1].country);
                return 0;
            case 3:
                printf("Nombre: %s\n", e[2].name);
                printf("Apellido: %s\n", e[2].lastname);
                printf("Edad: %d\n", e[2].age);
                printf("Numero: %d\n", e[2].number);
                printf("Ciudad: %s\n", e[2].country);
                return 0;
            case 0:
                break;
        }
    }while(opc != 0);
}


