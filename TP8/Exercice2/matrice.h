#ifndef MATRICE_H
#define MATRICE_H

/* Permet de travailler sur les matrices en allouant de la mémoire, la libérer,
copier une matrice, lire les entrées utilisateur et afficher la matrice*/
typedef unsigned char **tMatrice;

extern tMatrice MatAllouer(int NbLig, int NbCol);
extern tMatrice MatCopier(tMatrice Mat, int NbLig, int NbCol);
extern void MatLiberer(tMatrice *pMat, int nbLig);
extern tMatrice MatLire(int *pNbLig, int *pNbCol);
extern void MatAfficher(tMatrice Mat, int NbLig, int NbCol);

#endif