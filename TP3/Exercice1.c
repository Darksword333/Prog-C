#include <stdio.h>
#define MAX 100

int main(void){
    int nb;
    double addition;
    float tab[MAX];
    printf("Saisir le nombre de valeur que vous allez saisir :\n");
    scanf("%d",&nb);
    printf("Saisir les valeurs : \n");
    for (int i=0; i!=nb; i++){
        scanf("%f",&tab[i]);
        addition+=tab[i];
    }
    float moyenne;
    moyenne = addition/nb;
    printf("La moyenne de vos valeurs est %lf \n",moyenne);
    printf("Les valeurs supérieures à la moyenne sont les suivantes :\n");
    for (int i=0; i!=nb; i++){
        if (tab[i] > moyenne)
            printf("%f\n",tab[i]);
    }

return 0;
}