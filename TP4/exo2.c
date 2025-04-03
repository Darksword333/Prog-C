#include <stdio.h>

void temps_heure(int *seconde, int *minute, int *heure){
    while (*seconde>=60){
        *seconde-=60;
        *minute+=1;
    }
    while (*minute>=60){
        *minute-=60;
        *heure+=1;
    }
}

void tab_temps_heure(int *seconde, int tab[]){
    int minute=0, heure=0;
    while (*seconde>=60){
        *seconde-=60;
        minute+=1;
    }
    while (minute>=60){
        minute-=60;
        heure+=1;
    }
    tab[0] = heure;
    tab[1] = minute;
    tab[2] = *seconde;
}

int main(void){
    int seconde, minute = 0, heure = 0;
    printf("Veuillez saisir une valeur en seconde\n");
    scanf("%d",&seconde);
    temps_heure(&seconde,&minute,&heure);
    printf("Le temps est donc de %dh %dmin et %ds\n",heure, minute, seconde);
    printf("---\n");

    int tab[5];
    tab_temps_heure(&seconde, tab);
    printf("Le temps est donc de %dh %dmin et %ds\n",tab[0], tab[1], tab[2]);

    return 0;
}
