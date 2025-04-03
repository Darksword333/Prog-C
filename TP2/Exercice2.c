#include <stdio.h>
int main(void){
    printf("Saisir un texte sans accent et sans espace : \n");
    char voyelle[7]={'a','e','i','o','u','y'};
    char car;
    int nblettre, nbvoyelle;
    scanf("%c", &car);
    while (car != '#'){
        if (car == voyelle[0] ||car == voyelle[1] ||car == voyelle[2] ||car == voyelle[3] ||car == voyelle[4] ||car == voyelle[5])
            nbvoyelle++;
        nblettre++;
        scanf("%c", &car);
    }
    printf("Voici le nombre de voyelle %d et voici le nombre de lettre %d.\n",nbvoyelle,nblettre);

return 0;
}