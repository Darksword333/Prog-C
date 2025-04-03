#include <stdio.h>
int main(void){
    printf("Saisir une année :\n");
    int annee;
    scanf("%d",&annee);
    if ((annee%4==0 && annee%100!=0) || (annee%4==0 && annee%100==0 && annee%400==0))
        printf("L'année %d est bien bisextile.\n",annee);
    else if (annee%4==0 && annee%100==0 && annee%400!=0)
        printf("L'année %d n'est pas bisextile.\n",annee);
return 0;
}