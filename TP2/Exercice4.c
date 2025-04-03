#include <stdio.h>
int main(void){
    printf("Veuillez saisir le nombre de ligne. \n");
    int nblignes,nbetoile = 1;
    char espace=' ',etoile ='*';
    scanf("%d",&nblignes);
    for (int i=1; i<nblignes+1; i++){
        for (int j=0; j<nblignes-i; j++)
            printf("%c",espace);
        for (int k=0; k<nbetoile; k++)
        printf("%c",etoile);
    printf("\n");
    nbetoile+=2;
    }


return 0;
}