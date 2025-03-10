#include <stdio.h>
#include <math.h>

int Sum_Cube(int num) {
    char str[3];
    int sum = 0;
    int len = sprintf(str, "%d", num);

    for (int i = 0; i < len; i++) {
        sum += pow(str[i] - 0x30, 3);
    }

    return sum;
}

int IsArmstrong(int num) {
    if (num == Sum_Cube(num))
        return 1;

    return 0;
}

int main(void) {

    for (int i = 1; i <= 999;i++) {
        if (IsArmstrong(i)) {
            printf("%d\n", i);
        }

    }

    return 0;
}