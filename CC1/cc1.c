#include <stdio.h>

int main(void){
    int tab[100], i=0, val;
    printf("Veuillez saisir une série de valeur se terminant par 0\n");
    scanf("%d",&val);
    while (val != 0){
        tab[i] = val;
        i++;
        scanf("%d",&val);
    }
    int min = tab[0];
    for (int j=0; j<i; j++)
        if (min>tab[j]){
            min = tab[j];
        }
    printf("La valeur la plus petite de cette série est %d\n",min);

return 0;
}