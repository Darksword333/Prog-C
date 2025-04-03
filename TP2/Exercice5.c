#include <stdio.h>
int main(void){
    printf("Veuillez saisir deux valeurs entre 0 et 18.\n");
    int a,b;
    scanf("%3d", &a);
    while(a<0 || a>18){
    printf("Veuillez saisir une valeur valide.\n");
    scanf("%3d", &a);
    }
    scanf("%3d", &b);
    while(b<0 || b>18){
    printf("Veuillez saisir une valeur valide.\n");
    scanf("%3d", &b);
    }
    printf("  x | %3d %3d\n",a ,b);
    printf("--------------\n");
    for (int i=0; i<11; i++)
    printf("%3d | %3d %3d\n", i,a*i, b*i);



return 0;
}