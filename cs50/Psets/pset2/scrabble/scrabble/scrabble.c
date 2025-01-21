#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 > score2){
        printf("Player 1 wins!\n");
    }
    else if(score1 < score2){
        printf("Player 2 wins!\n");
    }
    else{
        printf("Tie!\n");
    }
}


    //Cabe resaltar que en este caso podriamos hacerlo alreves, convirtiendo las mayusculas a minusculas y cambiando la condicional donde se suman los puntos , si lo hicieramos de dicha forma, el programa deberia de interactuar de la misma manera.
int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    for(int i = 0; word[i] != '\0'; i++){
        char c = word[i];//En cada iteracion del bucle, "c" toma un valor diferente, en este caso si introducieramos la palabra "hola", en la primera iteracion, "c", tomaria el valor de "h" y asi sucesivamente con las demas iteraciones.
        if(islower(c)){
            c = toupper(c); //Todas los caracteres minusculas se convierten a mayusculas
        }

        if(c >= 'A' && c <= 'Z'){
            score += POINTS[c - 'A'];
        }
    }

    return score;
}
