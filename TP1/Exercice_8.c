#include <stdio.h>

int main(void){
    double val,min,max;
    int a;
    for  (a=0; a<5; a++) {
        printf("Veuillez saisir un nombres réels : \n");
        scanf("%lf"&val);
        if (a==0)
        min = val;
        max = val;
        if (val>max)
            max = val;
        if (val<min)
            min = val;
    }
    printf("Le plus grand nombre de cette série est %lf et le plus petit est %lf", max, min);
return 0;
}