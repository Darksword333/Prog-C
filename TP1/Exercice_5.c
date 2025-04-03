#include <stdio.h>

int main(void){
    int a,b,c;
    printf("Saisir un entier : \n");
    scanf("%d", &a);
    printf("Saisir un deuxième entier : \n");
    scanf("%d", &b);
    c = a;
    a = b;
    b = c;
    printf("Le premier nombre est désormais %d et le second %d \n",a,b);
return 0;
}