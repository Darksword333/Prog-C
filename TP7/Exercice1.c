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

void MatLiberer(tMatrice *pMat, int NbLig){
    for (int i = 0; i < NbLig; i++) {
        free((*pMat)[i]);
    }
    free(*pMat);
    *pMat = NULL;
}

tMatrice Triangle(int n){
    tMatrice A=MatAllouer(n,n);
    for (int i=0; i<n; i++){
        A[i][0] = 1;
        A[i][i] = 1;
        for (int j=1; j<i; j++){
            A[i][j]=A[i-1][j-1]+A[i-1][j];
        }   
    }
    return A;
}

void AffTriangle(tMatrice A, int NbLig){
    printf("Le triangle de pascal de taille %d est le suivant :\n",NbLig);
    for (int i=0; i<NbLig; i++){
        for (int j=0; j<=i; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    printf("Veuiller saisir le nombre de lignes.\n");
    int n;
    scanf("%d",&n);
    tMatrice A;
    A = Triangle(n);
    AffTriangle(A, n);
    MatLiberer(&A, n);
    return 0;
}