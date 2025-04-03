#include <stdio.h>
#define Maximum 6
void Affichertab(int Tab[], int NbElt){
    for (int i=0; i<NbElt; i++){
        printf("%d",Tab[i]);
        printf(" ");
    }
    printf("\n");
}

int Min(int Tab[], int NbElt){
    int min = Tab[0];
    for (int i=1; i<NbElt; i++){
        if (min>Tab[i]){
            min = Tab[i];
        }
    }
return min;
}

int Max(int Tab[], int NbElt){
    int max = Tab[0];
    for (int i=1; i<NbElt; i++){
        if (max<Tab[i]){
            max = Tab[i];
        }
    }
return max;
}

void MinMax(int Tab[], int NbElt, int *pMin, int *pMax){
    *pMin = Tab[0];
    *pMax = Tab[0];
    for (int i=1; i<NbElt; i++){
        if (*pMin>Tab[i]){
            *pMin = Tab[i];
        }
    for (int i=1; i<NbElt; i++){
        if (*pMax<Tab[i]){
            *pMax = Tab[i];
        }
    }
}
}

int SupprimerVal(int Tab[], int *pNbElt, int Val){
    int NbSuppr = 0;
    int tab2[Maximum];
    int j =0;
    for (int i=0; i<Maximum; i++){
        if (Tab[i] != Val){
            tab2[j] = Tab[i];
            j++;
        }
        else {
            NbSuppr++;
        }
    }
    printf("Le tableau est désormais :\n");
    Affichertab(tab2, Maximum-NbSuppr);
    printf("Le nombre de suppression est de %d\n",NbSuppr);
return Maximum-NbSuppr;
}

int main(void){
    int tab[Maximum] = {5,1,2,3,4,5};
    printf("Le tableau est le suivant :\n");
    Affichertab(tab, Maximum);
    printf("---\n");

    printf("Sa valeur minimale est :\n");
    printf("%d\n",Min(tab, Maximum));
    printf("---\n");

    printf("Sa valeur maximale est :\n");
    printf("%d\n",Max(tab, Maximum));
    printf("---\n");

    printf("Les valeurs minimale et maximale sont: \n");
    int min,max;
    MinMax(tab, Maximum, &min, &max);
    printf("%d %d\n",min,max);
    printf("---\n");

    int NbElt = Maximum;
    printf("La taille du tableau est désormais de %d\n",SupprimerVal(tab, &NbElt, 5));


return 0;
}