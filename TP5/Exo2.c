#include <stdio.h>
#include <stdlib.h>
double *CreerTableau(int NbElts){
    double *tab;
    tab = malloc(tab[NbElts*sizeof(double)]);
    
return tab;
}

void SaisirTableau(double *tab, int NbElts){
    printf("Veuillez saisir une suite d'entier : ");
    for (int i=0; i<NbElts; i++){
        scanf("%lf",&tab[i]);
    }
}

void AfficherTableau(double *tab, int NbElts){
    printf("Le tableau est le suivant : \n");
    for (int i=0; i<NbElts; i++){
        printf("%lf ",tab[i]);
    }
    printf("\n");
}

void LibererTableau(double *tab){
    free(tab);
}

int main(void){
    double *tab;
    printf("Veuillez saisir le nombre d'élément du tableau : ");
    int NbElts;
    scanf("%d",&NbElts);
    tab = CreerTableau(NbElts);
    SaisirTableau(tab,NbElts);
    AfficherTableau(tab, NbElts);
    LibererTableau(tab);

return 0;
}