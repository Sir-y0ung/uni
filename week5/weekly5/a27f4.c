#include <stdio.h>

long encode(long code) {
    long security_code = (98 - (code * 100) % 97) % 97;

    long result = code * 100 + security_code;

    return result;
}

int check(long final_code) {
    if (final_code % 97 == 1) {
        return 1;
    }
    return 0;
}


int main(void) {
    long limit_1;
    long limit_2;
    long final_code;

    printf("Lower Limit:");
    scanf("%ld", &limit_1);

    printf("Upper Limit:");
    scanf("%ld", &limit_2);

    for (int i = limit_1; i <= limit_2; i++) {
        final_code = encode(i);
        if (check(final_code) == 1) {
            printf("Code: %d Encoding: %ld isValid:yes\n", i, final_code);
        }
        else {
            printf("Code: %d Encoding: %ld isValid:no\n", i, final_code);
        }

    }

    return 0;
}
