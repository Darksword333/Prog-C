#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
typedef unsigned char **tMatrice;

tMatrice MatAllouer(int NbLig, int NbCol){
    tMatrice tab = NULL;
    tab = malloc(NbLig * sizeof(unsigned char *));
    if (tab == NULL)
        return NULL;

    for (int i = 0; i < NbLig; i++) {
        tab[i] = malloc(NbCol * sizeof(unsigned char));
        if (tab[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(tab[j]);
            free(tab);
            return NULL;
        }
    }

    return tab;
}

tMatrice MatCopier(tMatrice Mat, int NbLig, int NbCol){
    tMatrice tab=MatAllouer(NbLig, NbCol);
    for (int i=0; i<NbLig; i++){
        for (int j=0; j<NbCol; j++){
            tab[i][j]=Mat[i][j];
        }
        }
    return tab;
}

void MatLiberer(tMatrice *pMat, int nbLig){
    for (int i = 0; i < nbLig; i++) {
        free((*pMat)[i]);
    }
    free(*pMat);
    *pMat = NULL;
}

tMatrice MatLire(int *pNbLig, int *pNbCol){
    printf("Combien de ligne et de colonne souhaitez vous saisir ?\n");
    scanf("%d",pNbLig);
    scanf("%d",pNbCol);
    tMatrice tab;
    tab=MatAllouer(*pNbLig, *pNbCol);
    if (tab == NULL)
        return NULL;
    printf("Veuiller saisir les valeurs de la matrice (unsigned char).\n");
    unsigned char val;
    for (int i=0; i<*pNbLig; i++){
        for (int j=0; j<*pNbCol; j++){
            scanf("%hhu",&val);
            tab[i][j]=val;
        }
    }
return tab;
}

void MatAfficher(tMatrice Mat, int NbLig, int NbCol){
    printf("La matrice est la suivante :\n");
    for (int i=0; i<NbLig; i++){
        for (int j=0; j<NbCol; j++){
            printf("%hhu ",Mat[i][j]);
        }
        printf("\n");
    }
}