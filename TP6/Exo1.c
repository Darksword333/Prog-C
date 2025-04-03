#include <stdio.h>
#include <stdlib.h>
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

tMatrice MatCopier(tMatrice Mat, int NbLig, int NbCol){
    tMatrice tab=MatAllouer(NbLig, NbCol);
    for (int i=0; i<NbLig; i++){
        for (int j=0; j<NbCol; j++){
            tab[i][j]=Mat[i][j];
        }
        }
    return tab;
}

void MatLiberer(tMatrice *pMat){
    for (int i = 0; i < sizeof(*pMat); i++) {
        free((*pMat)[i]);
    }
    free(*pMat);
    *pMat = NULL;
}


int main(void){
    int NbLig,NbCol;
    tMatrice tab, tab2;
    printf("Première matrice :\n");
    tab=MatLire(&NbLig,&NbCol);
    MatAfficher(tab, NbLig, NbCol);
    printf("Seconde matrice :\n");
    tab2 = MatCopier(tab, NbLig, NbCol);
    MatAfficher(tab2, NbLig, NbCol);
    printf("Libérer l'espace\n");
    MatLiberer(&tab);
    MatLiberer(&tab2);
    return 0;
}