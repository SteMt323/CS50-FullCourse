#include <stdio.h>
#include <cs50.h>

int main(){
    char carName[] = "Volvo";
    int i;

    for (i = 0; i < 5; ++i) {
        printf("%c\n", carName[i]);
    }
}
