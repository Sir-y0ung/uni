#include <stdio.h>

int total(int num) {

    int total = 0;

    for (int i = 1; i <= num; i++) {
        total += i;
    }

    return total;
}

int main(void) {
    int input_number;

    printf("number:");
    scanf("%d", &input_number);

    printf("total 10  = %d\n", total(10));
    printf("total %d = %d\n",input_number, total(input_number));
    printf("total 100 = %d\n", total(100));

    return 0;
}
