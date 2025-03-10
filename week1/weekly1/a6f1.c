#include <stdio.h>

int main() {
    int working_days;
    long daily_payout;
    double gift_percentage;

    printf("Dwse tis hmmeres ergasias tou etous: ");
    scanf("%d", &working_days);

    printf("Dwse thn hmerhsia amoibh: ");
    scanf("%ld", &daily_payout);

    printf("Dwse to pososto dwroy : ");
    scanf("%lf", &gift_percentage);

    double gift = ( (double) working_days * (double) daily_payout) * gift_percentage;

    printf("To dwro einai %g", gift); 

    return 0;
}