#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LGMAXNOM 30
#define LGMAXPRENOM 20
#define LGMAXMAIL 254

// Type structuré pour stocker une date de naissance
struct sDate
{
  unsigned char Jour;
  unsigned char Mois;
  unsigned short int Annee;
};

// Type structuré pour stocker un contact dans une liste simplement chaînée
struct sContact
{
  char Nom[LGMAXNOM+1];
  char Prenom[LGMAXPRENOM+1];
  char Mail[LGMAXMAIL+1];
  struct sDate Naissance;
  struct sContact *pSuivant; // Adresse du contact suivant
};

// Type structuré permettant d'accéder à une liste chaînée de contacts 
struct sRepertoire
{ 
  struct sContact *Debut; // Adresse du premier contact de la liste
  struct sContact *Fin; // Adresse du dernier contact de la liste
};

// Type permettant de manipuler un répertoire
typedef struct sRepertoire *tRepertoire;

/* Affichage des informations d'un contact (version 1)
 * Entrée : 
 *    - Contact : le contact
 */
void AfficherContact1(struct sContact Contact)  
{
  printf("%s\n%s\n%s\n%02d/%02d/%d\n",
         Contact.Nom,
         Contact.Prenom,
         Contact.Mail,
         Contact.Naissance.Jour,
         Contact.Naissance.Mois,
         Contact.Naissance.Annee);
}  
 
/* Affichage des informations d'un contact (version 2)
 * Entrée : 
 *     - pContact : adresse du contact
 */  
void AfficherContact2(const struct sContact *pContact)  
{
  printf("-Nom : %s \n-Prénom : %s \n-Mail : %s \n-Date de naissance : %02d/%02d/%d\n",
          pContact -> Nom,
          pContact -> Prenom,
          pContact -> Mail,
          pContact -> Naissance.Jour,
          pContact -> Naissance.Mois,
          pContact -> Naissance.Annee);
} 

/* Création d'un répertoire vide
 * Valeur de retour : accès au répertoire vide alloué de manière dynamique
 */
tRepertoire CreerRepertoire(void)
{
  struct sRepertoire *nouveau = malloc(sizeof(struct sRepertoire));
  nouveau -> Debut = NULL;
  nouveau -> Fin = NULL;
  return nouveau;
}

/* Affichage de tous les contacts d'un répertoire
 * Entrée :
 *   - Repertoire : accès au répertoire
 */
void AfficherRepertoire(tRepertoire Repertoire)
{
  struct sContact *pActuel = Repertoire -> Debut;
  int i=0;
  while(pActuel != NULL){
    printf("\t \tContact numéro %d\n", i+1);
    i++;
    AfficherContact2(pActuel);
    pActuel= pActuel -> pSuivant;
  }
}

/* Ajout d'un contact à la fin d'un répertoire
 * Entrée : 
 *    - pNouveau : adresse du contact à ajouter
 * Mise à jour (entrée et sortie):
 *    - Repertoire : accès au répertoire
 */
void AjouterContact(struct sContact *pNouveau, tRepertoire Repertoire)
{
  struct sContact *pNouv = malloc(sizeof(struct sContact));
  *pNouv = *pNouveau;
  if (Repertoire -> Debut == NULL)
    Repertoire -> Debut = pNouv;
  else
    Repertoire -> Fin -> pSuivant = pNouv;
  Repertoire -> Fin = pNouv;
}

/* Recherche d'un contact par son nom
 * Entrées :
 *    - NomRecherche : nom recherché (chaîne de caractères)
 *    - Repertoire : accès au répertoire
 * Valeur retournée : adresse du contact trouvé ou NULL si le contact est absent
 */
struct sContact *Rechercher(char NomRecherche[], tRepertoire Repertoire)
{
  struct sContact *pActuel = Repertoire -> Debut;
  int i=0;
  while (pActuel != NULL){
    if (strcmp(NomRecherche, pActuel -> Nom) == 0){
      printf("Le contact %s a été trouvé au numéro %d\n", NomRecherche, i+1);
      return pActuel;
    }
    i++;
    pActuel= pActuel -> pSuivant;
  }
  return 0;
}

/* Écriture de tous les contacts d'un répertoire dans un fichier au format binaire
 * Entrées :
 *    - Repertoire : accès au répertoire
 *    - NomFichier : nom du fichier (chaîne de caractères)
 */
void EcrireFichier(tRepertoire Repertoire, char NomFichier[])
{
  FILE *fichier = fopen(NomFichier, "wb");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible d'écrire dans le fichier %s\n", NomFichier);
        exit(EXIT_FAILURE);
    }
  struct sContact *pActuel = Repertoire -> Debut;
  while (pActuel != NULL){
    fwrite(pActuel, sizeof(struct sContact), 1, fichier);
    pActuel= pActuel -> pSuivant;
  }
  fclose(fichier);
}

/* Lecture d'un répertoire dans un fichier au format binaire
 * Entrée :
 *    - NomFichier : nom du fichier (chaîne de caractères)
 * Valeur de retour : accès au répertoire créé ou NULL en cas de problème
 */
tRepertoire LireFichier(char NomFichier[])
{
  FILE *fichier = fopen(NomFichier, "rb");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible d'écrire dans le fichier %s\n", NomFichier);
        return NULL;
    }
  struct sRepertoire *Repertoire = CreerRepertoire();
  struct sContact pActuel;
  int nbLus = fread(&pActuel, sizeof(struct sContact), 1, fichier);
  while (nbLus != 0){
    AjouterContact(&pActuel, Repertoire);
    nbLus = fread(&pActuel, sizeof(struct sContact), 1, fichier);
  }
  return Repertoire;
}

/* Libération de tout l'espace mémoire occupé par un répertoire
 * et mise à NULL de l'accès au répertoire
 * Mise à jour (entrée et sortie) : 
 *    - pRepertoire : adresse de l'accès à un répertoire
 */
void LibererRepertoire(tRepertoire *pRepertoire)
{
  struct sContact *pPrec;
  struct sContact *pActuel = (*pRepertoire) -> Debut;
  while (pActuel != NULL){
    pPrec = pActuel;
    pActuel = pActuel -> pSuivant;
    free(pPrec);
  }
  free(*pRepertoire);
  *pRepertoire = NULL;
}


int main(void)
{
  // Trois contacts
  struct sContact 
    c1={"KARENA","Emma","emma.karena@legria.es",{1,5,2001},NULL},
    c2={"DEUF","John","john.deuf@mayonnaise.fr",{12,1,1999},NULL},
    c3={"MANVUSSA","Gerard","gerard.manvussa@etonnant.com",{24,11,2000},NULL};
 
  printf("***** Création du répertoire.\n");
  tRepertoire Rep=CreerRepertoire();

  printf("***** Ajout de trois contacts.\n");
  AjouterContact(&c1,Rep);
  AjouterContact(&c2,Rep);
  AjouterContact(&c3,Rep);
  printf("***** Répertoire initial :\n");
  AfficherRepertoire(Rep);
  
  // Contact supplémentaire
  struct sContact Nouv={"AMBOLAGE",
                        "Oscar",
                        "oscar.ambolage@latele.com",
                        {9,6,2002},
                        NULL};
  printf("***** Ajout d'un contact.\n");
  AjouterContact(&Nouv,Rep);
  printf("***** Répertoire après ajout :\n");
  AfficherRepertoire(Rep);
  
  char Nom[]="DEUF"; // Nom qui va être recherché
  printf("\n***** Recherche de %s :\n",Nom);
  struct sContact *Res=Rechercher(Nom,Rep);
  if (Res==NULL)
    printf("%s n'est pas dans le repertoire.\n",Nom);
  else
    AfficherContact2(Res);
    
  char Fichier[]="repertoire2.dat"; // Nom du fichier binaire
  printf("\n***** Écriture du répertoire dans le fichier %s.\n",Fichier);
  EcrireFichier(Rep,Fichier);
  printf("\n***** Lecture du répertoire depuis le fichier %s.\n",Fichier);
  tRepertoire RepLu=LireFichier("repertoire2.dat");
  printf("***** Répertoire lu :\n");
  AfficherRepertoire(RepLu);
  
  printf("\n***** Libération des répertoires.\n");
  LibererRepertoire(&Rep);  
  LibererRepertoire(&RepLu);
  
  return 0;
}
