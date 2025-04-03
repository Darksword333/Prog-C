#include <stdio.h>
#include <stdlib.h>
#include "image.h"

typedef struct sImage *tImage;

struct sImage
{
    int NbLig; // Nombre de lignes de l’image
    int NbCol; // Nombre de colonnes de l’image
    tMatrice NivGris; // Matrice des niveaux de gris de l’image
};

int ImNbLig(tImage Im)
{
    return Im->NbLig;
}

int ImNbCol(tImage Im)
{
    return Im->NbCol;
}

tMatrice ImNivGris(tImage Im){
    return Im->NivGris;
}


tImage ImAllouer(int NbLignes, int NbColonnes)
{
    tImage Im = malloc(sizeof(struct sImage));
    if (Im == NULL)
        return NULL;

    Im->NbLig = NbLignes;
    Im->NbCol = NbColonnes;
    Im->NivGris = MatAllouer(NbLignes, NbColonnes);
    if (Im->NivGris == NULL)
    {
        free(Im);
        return NULL;
    }

    return Im;
}

void ImLiberer(tImage *pIm)
{
    MatLiberer(&((*pIm)->NivGris), (*pIm)->NbLig);
    free(*pIm);
    *pIm = NULL;
}

tImage ImLire(char NomFichier[])
{
    FILE *fich;
    fich = fopen(NomFichier, "rt");
    if (fich == NULL)
        return NULL;

    char sig[3];
    int NbLig, NbCol, NivG;
    fscanf(fich, "%2s", sig);
    fscanf(fich, "%d", &NbCol);
    fscanf(fich, "%d", &NbLig);
    fscanf(fich, "%d", &NivG);
    tImage Im = ImAllouer(NbLig, NbCol);
    if (Im == NULL)
    {
        fclose(fich);
        return NULL;
    }

    for (int i = 0; i < NbLig; i++)
    {
        for (int j = 0; j < NbCol; j++)
        {
            int val;
            fscanf(fich, "%d", &val);
            Im->NivGris[i][j] = val;
        }
    }

    fclose(fich);
    return Im;
}

void ImEcrire(tImage Im, char NomFichier[]) {
    FILE *fichier = fopen(NomFichier, "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible d'écrire dans le fichier %s\n", NomFichier);
        exit(EXIT_FAILURE);
    }
    int nb_lignes = ImNbLig(Im);
    int nb_colonnes = ImNbCol(Im);
    tMatrice matrice_gris = ImNivGris(Im);
    fprintf(fichier, "P2\n%d %d\n255\n", nb_colonnes, nb_lignes);
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            fprintf(fichier, "%d ", (int)matrice_gris[i][j]);
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
}

tImage ImRotation90(tImage Im) {
    int nb_lignes = ImNbCol(Im);
    int nb_colonnes = ImNbLig(Im);
    tImage Im_rot = ImAllouer(nb_lignes, nb_colonnes);
    tMatrice matrice_gris = ImNivGris(Im);
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            Im_rot->NivGris[i][j] = (int)matrice_gris[nb_colonnes - j - 1][i];
        }
    }
    return Im_rot;
}
