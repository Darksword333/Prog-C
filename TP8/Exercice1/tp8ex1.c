#include <stdio.h>
#include "matrice.h"


int main(void) {

    int NbLig,NbCol;
    tMatrice tab, tab2;
    printf("Première matrice :\n");

    tab=MatLire(&NbLig,&NbCol);
    MatAfficher(tab, NbLig, NbCol);
    printf("Seconde matrice :\n");

    tab2 = MatCopier(tab, NbLig, NbCol);
    MatAfficher(tab2, NbLig, NbCol);
    printf("Libérer l'espace\n");
    MatLiberer(&tab, NbLig);
    MatLiberer(&tab2, NbLig);
    return 0;
}
