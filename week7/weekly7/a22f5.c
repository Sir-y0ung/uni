#include <stdio.h>

int check_card_number(long long card_ellements[16]) {
    if (card_ellements[0] > 7 || card_ellements[0] < 4) {
        return 0;
    }

    for (int i =0; i < 16; i = i + 2) {
        card_ellements[i] = card_ellements[i] * 2;
        if (card_ellements[i] > 9) {
            card_ellements[i] = (card_ellements[i] % 10) + (card_ellements[i] / 10);
        }
    }

    int sum = 0;
    for (int i = 0; i < 16; i++) {
        sum += (int) card_ellements[i];
    }

    if (!(sum % 10)) {
        return 1;
    }
    return 0;
}

int main(void) {
    long long card_number;
    long long card_elements[16];

    printf("Insert card number:");
    scanf("%lld", &card_number);

    long long starting_card = card_number;

    for (int i = 15; i > -1; i--) {
        card_elements[i] = card_number % 10;
        card_number = card_number / 10;
    }


    if (check_card_number(card_elements) &&  starting_card > 1000000000000000 && starting_card <= 9999999999999999) {
        printf("%lld is valid", starting_card);
    }
    else {
        printf("%lld is invalid", starting_card);
    }

    return 0;
}
