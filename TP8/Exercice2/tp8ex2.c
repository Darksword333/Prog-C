#include <stdio.h>
#include "image.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage de %s <mon_image.pgm> \n", argv[0]);
        return 1;
    }
    tImage image = ImLire(argv[1]);
    tImage image_rot = ImRotation90(image);
    ImEcrire(image_rot, "rotation.pgm");
    ImLiberer(&image);
    ImLiberer(&image_rot);
    return 0;
}

