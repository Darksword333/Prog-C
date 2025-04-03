#include <stdio.h>

int main (void){
    int a;
    printf("Saisir une température en Farenheit : \n");
    scanf("%d", &a);
    printf("La valeur en Celsius est désormais %d \n", (5*(a-32))/9);
return 0;
}