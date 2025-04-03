#include <stdio.h>
int main(void){
    printf("Saisir le nombre de notes dont vous voulez calculer la moyenne :\n");
    double nombre, valeur, valeurs;
    scanf("%lf",&nombre);
    printf("Saisir les notes dont vous voulez calculer la moyenne (comprises entre 0 et 20) : \n");
    for (int i=0; i<nombre; i++){
        scanf("%lf",&valeur);
        while (valeur < 0|| valeur > 20){
            printf("Veuillez saisir une note valide. \n");
            scanf("%lf",&valeur);
        }
        valeurs += valeur;

        }

    double moyenne;
    moyenne = valeurs/nombre;
    printf("La moyenne des valeurs saisi est %lf \n", moyenne);

return 0;
}