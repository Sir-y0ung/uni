#include <stdio.h>
#include <math.h>

int main() {
    double cars_ammount = 80000;
    int years = 0;

    while (cars_ammount < 160000) {
        cars_ammount = ceil(cars_ammount * (1.07));
        years++;
    }

    printf("%d\n", years);
    printf("%g\n", cars_ammount);

    return 0;
}