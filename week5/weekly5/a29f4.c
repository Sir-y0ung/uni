#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int is_coprime(int a, int b) {
    return gcd(a, b) == 1;
}

int euler_phi(int N) {
    int y = 0;
    for (int i = 1; i <= N; i++) {
        if (is_coprime(i, N)) {
            y += 1;
        }
    }
    return y;
}

int main(void) {
    int x;

    printf("Enter X:");
    scanf("%d", &x);

    for (int i = 1; i <= x;i++) {
        printf("phi(%d) = %d\n",i, euler_phi(i));
    }

    return 0;
}
