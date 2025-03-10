#include <stdio.h>

int main() {
    long timi_temaxiou,pl;
    double fpa;

    printf("Dwse thn timh temaxiou: ");
    scanf("%li", &timi_temaxiou);

    printf("Dwse to pososto FPA: ");
    scanf("%lF", &fpa);

    printf("Dwse to plithos twn temaxiwn: ");
    scanf("%li", &pl);

    long kostos = (timi_temaxiou * pl) + ((pl * timi_temaxiou) * fpa);

    printf("To kostos ths paragelias einai %li ", kostos);

    return 0;
}