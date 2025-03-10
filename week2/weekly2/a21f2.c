#include <stdio.h>


int main() {
    int misthos;
    int arithmos_paidion;
    float epidoma;

    printf("Dwse vasiko mistho: ");
    scanf("%d", &misthos);

    printf("Dwse arithmo paidion: ");
    scanf("%d", &arithmos_paidion);

    if (arithmos_paidion == 1) {
        epidoma = (float) misthos * 0.04f;
    }
    else if (arithmos_paidion == 2) {
        epidoma = (float) misthos * 0.09f;
    }
    else if (arithmos_paidion >= 3) {
        epidoma = (misthos * 0.15f) + (arithmos_paidion - 3) * 0.4f * misthos;
    }
    
    printf("Epidoma: %.2f", epidoma);
}