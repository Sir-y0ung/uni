#include <stdio.h>

int main() {

    double profit, saleAmount;
    long purchaseAmount;
    int rate;

    printf("Dose kathari axia: ");
    scanf("%li", &purchaseAmount);

    printf("Dose pososto kerdous: ");
    scanf("%d", &rate);

    profit = purchaseAmount * (rate / 100.0);
    saleAmount = purchaseAmount + profit;

    printf("Kerdos: %g\n", profit);
    printf("Synoliko poso: %g\n", saleAmount);

    return 0;
}