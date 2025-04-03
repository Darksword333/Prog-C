#include <stdio.h>
#include "ti.h"

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Usage de %s <mon_image.pgm> \n", argv[0]);
        return 1;
    }
    unsigned char Table[256];
    tImage image = ImLire(argv[1]);
    tImage image_rot = ImRotation90(image);
    ImEcrire(image_rot, "rotation.pgm");
    ImLiberer(&image);
    ImLiberer(&image_rot);
    printf("Rotation effectuée");
    RemplirTableInversion(Table[256]);
    tImage image2 = AppliquerTable(Table[256], image);
    ImEcrire(image2, "inversion.pgm");
    return 0;
}