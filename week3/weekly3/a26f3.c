#include <stdio.h>

int main(void) {
    int num;
    int sum;

    printf("Num:");
    scanf("%d", &num);

    for (int i = 1; i < num; i++) {
        if (!(num % i)) {
            sum += i;
        }
    }


    printf("Sum: %d\n", sum);
    return 0;
}
