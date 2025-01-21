#include <cs50.h>
#include <stdio.h>

void triangulo();
void ejecutar();

int main()
{

    ejecutar();
    return 0;
}

void triangulo()
{
    int altura;
    do
    {
        printf("---------------------------------------\n");
        altura = get_int("ingrese la altura: ");
    }
    while (altura < 1 || altura > 8);

    for (int i = 1; i <= altura; i++)
    {
        for (int j = 1; j <= altura - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        for (int n = 1; n <= 2; n++)
        {
            printf(" ");
        }
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}

void ejecutar()
{

    do
    {
        triangulo();
        break;
    }
    while (!0);
}
