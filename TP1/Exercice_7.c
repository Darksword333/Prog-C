#include <stdio.h>

int main(void){
    printf("Saisir un nombre entier : \n");
    unsigned char c;
    scanf("%hhu", &c);
    printf("Le carré de ce nombre est %hhu \n",c*c);

/* Le résultat pour 8 est bon mais pas pour 16 
car cela vaut 256 et le résultat est donc plus un entier non signé */

return 0;
}