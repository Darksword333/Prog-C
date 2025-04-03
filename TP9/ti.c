#include <stdio.h>
#include <math.h>
#include "ti.h"

// Il faut include math.h
// La fonction double round(double x) retourne l’entier le plus proche de x.
// La fonction double pow(double x, double y) retourne x(puissance)y

tImage AppliquerTable(unsigned char Table[256], tImage Im){
    int nb_lignes = ImNbLig(Im);
    int nb_colonnes = ImNbCol(Im);
    tMatrice Im2 = ImAllouer(nb_lignes, nb_colonnes);
    tMatrice NivG = ImNivGris(Im);
    tMatrice NivG2 = ImNivGris(Im2);
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            NivG2[i][j] = Table[NivG[i][j]];
        }
    }
    return Im2;
}

void RemplirTableInversion(unsigned char Table[256]){
    for (int i=255; i>=0; i--){
        Table[i] = 255-i;
    }
}