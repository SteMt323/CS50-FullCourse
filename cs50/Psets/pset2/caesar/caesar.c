#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void Caesar(int key, string text);
bool only_digits(string s);

int main(int argc, string argv[])
{
    int key;

    if (argc != 2 ){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if(!only_digits(argv[1])){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else{
        key = atoi(argv[1]);
        string text = get_string("plaintext: ");
        Caesar(key, text);
        printf("ciphertext: %s\n",text);
        return 0;
    }


}

void Caesar(int key, string text){
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] >= 65 && text[i] <= 90){
            text[i] = (text[i] - 65 + key) % 26 + 65;
        }
        else if(text[i] >= 97 && text[i] <= 122){
            text[i] = (text[i] - 97 + key) % 26 + 97;
        }
    }
}

bool only_digits(string s){
    bool ver;
    for(int i = 0; s[i] != '\0'; i++){
        if(isdigit(s[i])){
            ver = true;
        }
        else{
            ver = false;
        }
    }
    return ver;
}


