#include <stdio.h>
#include <windows.h>


int main(){
    SetConsoleOutputCP(CP_UTF8);
    printf("__________________________________________\n");
    printf("Catálogode entrenimiento\n");
    printf("1. Betty la fea\n");
    printf("2. La que no podia olvidar\n");
    printf("3. La que se enamoro de su mejor amiga\n");
    printf("__________________________________________\n");
    printf("¿Qué serie deseas ver?\n");
    int serie;
    scanf("%d", &serie);
    if(serie==1){
        printf("La serie es Betty la fea\n");
    }
    else if(serie==2){
        printf("La serie es La que no podia olvidar\n");
    }
    else if(serie==3){
        printf("La serie es La que se enamoro de su mejor amiga\n");
    }
    else{
        printf("La serie que escogio %d no existe\n",serie);
    }
}
