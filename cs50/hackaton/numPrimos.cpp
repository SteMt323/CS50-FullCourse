#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
bool ComprobacionPrimos(int num);
int main() {
    int num1;
    int num2;
    int c = 0;
    printf("I: ");
    scanf("%d", &num1);
    printf("I2: ");
    scanf("%d", &num2);
    for(int i = num1;i <= num2; i++){
        if(ComprobacionPrimos(i)){
            c++;
        }
    }
    printf("%d\n", c);


    return 0;
}

bool ComprobacionPrimos(int num){
    if(num % 1 == 1 && num % num == num){
        return true;
    }
    return false;
}
