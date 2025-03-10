#include <stdio.h>

int main(void) {
    int n;
    float sum;

    printf("Dwse orio:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (float) i;
    }


    printf("To athroisma einai %.2f\n", sum);
    return 0;
}
