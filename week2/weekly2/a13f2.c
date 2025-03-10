#include <stdio.h>

int main() {
    int coffe_ammount;
    int kermata[] = {0,0,0,0,0};
    int psila[] = {200 ,100, 50, 20, 10};

    printf("Dose kafedes:");
    scanf("%d", &coffe_ammount);

    double pay_ammount = coffe_ammount * 70;

    if (pay_ammount <= 500) {    
        double resta = 500 - pay_ammount;
        int i = 0;

        while (i < 5 && pay_ammount ) {
            
            kermata[i] = (resta / psila[i]);
            resta = resta -  ( kermata[i] * psila[i]);
            i++;
        }

        printf("Resta \n");
        printf("Kermata 2E : %d\n", kermata[0]);
        printf("Kermata 1E : %d\n", kermata[1]);
        printf("Kermata 50L : %d\n", kermata[2]);
        printf("Kermata 20L : %d\n", kermata[3]);
        printf("Kermata 10L : %d\n", kermata[4]);

    } else {
        printf("Sfalma\n");
    }

    return 0;
}