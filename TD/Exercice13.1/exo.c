#include <stdio.h>
#include <stdlib.h>

struct article {
    char descr[100];
    float prix;
};

// strlib.h
// void qsort(void *Tab, size_t NbElts, size_t Taille, int (*Compare)(const void *, const void *))

int comp_int(const void *a, const void *b){
    int x = *((int *) a);
    int y = *((int *)b);
    return x - y;
}

int comp_art(const void *a, const void *b){
    int x = ((struct article *) a) -> prix;
    int y = ((struct article *)b) -> prix;
    return x - y;
}

void trier(int tab[], int NbElts){
    qsort(tab, NbElts, sizeof(int), comp_int);
}

void affich_int(struct article a[], int NbElts){
    for (int i=0; i<NbElts; i++)
        printf("[%s, %.3f] ",a[i].descr, a[i].prix);
    printf("\n");
}

void affich_art(int tab[], int NbElts){
    for (int i=0; i<NbElts; i++)
        printf("%d ",tab[i]);
    printf("\n");
}

int main(void){
    int tab[5]={3,5,4,8,1};
    affich_int(tab, 5);
    trier(tab, 5);
    affich_int(tab, 5);
    struct article tab_article[3] = { {"iPad", 599.9}, {"BD", 12.5}, {"Montre", 100.0}};
    affich_art(tab_article, 3);
    qsort(tab_article, 3, sizeof(struct article), comp_art);
    affich_art(tab_article, 3);

    return 0;
}