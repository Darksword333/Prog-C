#include <stdio.h>
#include <math.h>
#define EPS 1e-10

int main(void){


int ordre;
int symetrique = 1;
printf("Veuillez saisir l'ordre de la matrice : \n");
scanf("%d",&ordre);
double tab[ordre][ordre];

for (int i=0; i!=ordre; i++){
    printf("Veuillez saisir les valeurs de la ligne %d \n",i+1);
    for (int j=0; j!=ordre; j++){
        scanf("%lf",&tab[i][j]);
    }
}

for (int i=0; i!=ordre && symetrique; i++){
    for (int j=0; j!=ordre && symetrique; j++){
        if (fabs(tab[i][j]-tab[j][i])>EPS)
            symetrique = 0;
    }
}

if (symetrique == 0)
    printf("La matrice n'est pas symétrique. \n");
else 
    printf("La matrice est symétrique. \n");


return 0;
}