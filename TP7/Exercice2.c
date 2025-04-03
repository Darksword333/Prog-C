#include <stdio.h>
#define MAX 10

void Trier(int Tab[], int NbElts){
    int temp;
    for (int i=0; i<NbElts-1; i++){
        for (int j=0; j<NbElts-1; j++){
            if (Tab[j+1] < Tab[j]){
                temp = Tab[j+1];
                Tab[j+1] = Tab[j];
                Tab[j] = temp;
            }
        }
    }
}

void Aff(int Tab[], int NbElts){
    printf("Le tableau de taille %d est le suivant :\n",NbElts);
    for (int i=0; i<NbElts; i++){
        printf("%d ",Tab[i]);
    }
    printf("\n");
}

void TrierPtr(int Tab[], int NbElts, int *Ptr[])

int main(void){
    int Tab[MAX] = {1, 2, 5, 6, 9, 8, 7, 3, 4};
    Aff(Tab ,MAX-1);
    Trier(Tab, MAX-1);
    Aff(Tab, MAX-1);
    return 0;
}