#include <stdio.h>
#include <math.h>

int main(void){
    printf("Saisir un nombre entier : \n");
    double a;
    scanf("%lf", &a);
    printf("La racine carré de ce nombre est %lf \n",sqrt(a));
return 0;
}