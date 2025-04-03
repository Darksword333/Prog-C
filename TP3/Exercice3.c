#include <stdio.h>

int main(void){
char car;
char tab[80];
char tab2[80];
int i = 0;
int palindrome = 1;
printf("Veuillez saisir une chaine de caractère. \n");
scanf("%c",&car);
while (car != '\n' && i < 80){
    tab[i] = car;
    i++;
    scanf("%c",&car);
}
tab[i] = '\0';
printf("La chaine est la suivante : \n%s \n",tab);
printf("La chaine inversé est la suivante : \n");
int k=0;
for (int j=i-1; j>=0; j--){
    printf("%c",tab[j]);
    tab2[k++] = tab[j];
}
tab2[k] = '\0';
printf("\n");

while (i >= 0 && palindrome){
    if (tab[i] != tab2[i])
        palindrome = 0;
    i--;
}
if (palindrome == 1)
    printf("Cette phrase est un palindrome. \n");
else 
    printf("Cette phrase n'est pas un palindrome. \n");

return 0;
}