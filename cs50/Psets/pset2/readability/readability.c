#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text:\n");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
/*
    printf("Letters: %d\n",letters);
    printf("Words: %d\n",words);
    printf("Sentences: %d\n",sentences);
*/
    float L = ((float)letters / words)*100;
    float S = ((float)sentences / words)*100;
    float grade = 0.0588 * L - 0.296 * S - 15.8;


    if(grade <= 0){
        printf("Before Grade 1\n");
    }
    else if(grade >= 1 && grade <= 16){
        printf("Grade %.0f\n", round(grade));
    }
    else if(grade > 16){
        printf("Grade 16+\n");
    }
}

int count_letters(string text){
    int letters = 0;
    for(int i = 0; text[i] != '\0'; i++){
        if(isalpha(text[i])){
            letters++;
        }
    }
    return letters;
}

int count_words(string text){
    int words = 0;
    bool word = false;
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] != ' ' && text[i] != '\n'){
            if(!word){
                word = true;
                if(word == true){
                    words++;
                }
            }
        }
        else{
            word = false;
        }
    }
    return words;
}


int count_sentences(string text){
    int sentences = 0;
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            sentences++;
        }
    }
    return sentences;
}

//Calculos
/*
Letras / Palabras
Su resultado * 100

Oraciones / Palabras
Su resultado * 100

Fórmula:
index = 0.588 * L - 0.296 * S - 15.8;

Donde L es el primer calculo y S el segundo.
*/


